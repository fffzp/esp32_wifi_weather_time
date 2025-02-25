#include "esp32_s3_szp.h"
#include "freertos/semphr.h"
#include "esp_sntp.h"
#include "esp_system.h"
#include "esp_netif_sntp.h"

#include "gui_guider.h"
#include "custom.h"
#include "audio.h"

LV_FONT_DECLARE(font_alipuhui20);

extern lv_ui guider_ui;

extern SemaphoreHandle_t xGuiSemaphore;
static const char *TAG = "time_sync";
static int8_t alarm_hour = -1;  // 闹钟小时
static int8_t alarm_min = -1;   // 闹钟分钟
static TaskHandle_t audio_task_handle = NULL;

static void alarm_msgbox_event_cb(lv_event_t * e);

// SNTP同步时间函数
void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");

    esp_sntp_config_t config = ESP_NETIF_SNTP_DEFAULT_CONFIG("pool.ntp.org");
    config.servers[1] = "ntp1.aliyun.com";
    config.servers[2] = "ntp.ntsc.ac.cn";
    esp_netif_sntp_init(&config);

    // 将时区设置为中国标准时间
    setenv("TZ", "CST-8", 1);
    tzset();

    if (esp_netif_sntp_sync_wait(pdMS_TO_TICKS(10000)) != ESP_OK) {
        printf("Failed to update system time within 10s timeout");
    }
}

// 添加设置闹钟时间的函数
void set_alarm_time(int8_t hour, int8_t min) {
    alarm_hour = hour;
    alarm_min = min;
    ESP_LOGI(TAG, "Set alarm time to %02d:%02d", hour, min);
}


//获取时间任务
static void timer_Task(void *pvParameter)
{
    time_t now;
    struct tm timeinfo;
    char strftime_buf[64];
    char weekday[][4] = {"日", "一", "二", "三", "四", "五", "六"};


    initialize_sntp();
    while(1)
    {
        time(&now);
        localtime_r(&now, &timeinfo);
        // strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);

        // 如果时间已同步（年份大于 2020）
        if (timeinfo.tm_year > (2020 - 1900)) {
            snprintf(strftime_buf,sizeof(strftime_buf), "%d/%02d/%02d 星期%s %02d:%02d:%02d",
                    timeinfo.tm_year + 1900, 
                    timeinfo.tm_mon + 1, 
                    timeinfo.tm_mday,
                    weekday[timeinfo.tm_wday],
                    timeinfo.tm_hour,
                    timeinfo.tm_min,
                    timeinfo.tm_sec
                );
            ESP_LOGI(TAG, "The current date/time in Shanghai is: %s", strftime_buf);
            
            // 检查是否到达闹钟时间
            if (alarm_hour >= 0 && alarm_min >= 0 && 
                timeinfo.tm_hour == alarm_hour && 
                timeinfo.tm_min == alarm_min && 
                timeinfo.tm_sec == 0) {
                ESP_LOGI(TAG, "Alarm time reached!");
                
                xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);

                static const char * btns[] = {"确认", ""};
                lv_obj_t * mbox = lv_msgbox_create(NULL, "提示", "闹钟时间到啦！", btns, false);
                
                // 设置消息框文本字体
                lv_obj_set_style_text_font(mbox, &font_alipuhui20, 0);
                
                // 获取按钮并设置样式
                lv_obj_t * btn = lv_msgbox_get_btns(mbox);
                lv_obj_set_style_bg_color(btn, lv_color_make(0, 119, 255), LV_PART_ITEMS | LV_STATE_DEFAULT);  // 设置蓝色背景
                lv_obj_set_style_text_color(btn, lv_color_white(), LV_PART_ITEMS | LV_STATE_DEFAULT);  // 设置白色文本
                lv_obj_set_style_bg_opa(btn, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);  // 设置不透明度
                lv_obj_set_style_radius(btn, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);  // 设置圆角
                lv_obj_set_style_pad_top(btn, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);  // 设置内边距
                lv_obj_set_style_pad_bottom(btn, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_left(btn, 20, LV_PART_ITEMS | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_right(btn, 20, LV_PART_ITEMS | LV_STATE_DEFAULT);
                
                lv_obj_set_style_pad_all(mbox, 20, 0);  // 设置消息框内边距
                lv_obj_set_style_radius(mbox, 10, 0);  // 设置消息框圆角
                
                lv_obj_add_event_cb(mbox, alarm_msgbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
                lv_obj_center(mbox);
                
                xSemaphoreGive(xGuiSemaphore);
                
                // 播放音乐
                pa_en(1); // 打开音频
                audio_start(&audio_task_handle); // 传入任务句柄
            }

            xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
            lv_label_set_text(guider_ui.screen_label_timerinfo, strftime_buf);
            xSemaphoreGive(xGuiSemaphore);
        } else {
            ESP_LOGI(TAG, "Waiting for time synchronization...");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));        
    }
    vTaskDelete(NULL); // 在任务内部删除自身
}

void time_sync_start(void)
{   
    xTaskCreate(timer_Task,   "timer",    4096,NULL, 0, NULL);
}

// 添加消息框回调函数
static void alarm_msgbox_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_current_target(e);
    lv_msgbox_close(obj);
    
    // 停止音乐任务
    if (audio_task_handle != NULL) {
        audio_stop();  // 设置停止标志
        pa_en(0);     // 关闭音频
        audio_task_handle = NULL;  // 任务会自行清理并退出
    }
}

#include "esp32_s3_szp.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"
#include "esp_timer.h"

#include "weather.h"
#include "time_sync.h"
#include "gui_guider.h"
#include "custom.h"

lv_ui guider_ui;

#define LV_TICK_PERIOD_MS 1

static const char *TAG = "guitask";

SemaphoreHandle_t xGuiSemaphore;

static void lv_tick_task(void *arg)
{
    lv_tick_inc(LV_TICK_PERIOD_MS);
}

void guiTask(void *pvParameter)
{
    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui",
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));//参数单位应该是微秒

    setup_ui(&guider_ui);       //加载GUI页面
    
    weathertask_start();   //创建心知天气任务
    time_sync_start(); //创建时间同步任务
    ESP_LOGI(TAG, "create other task ok");
    
    while (1)
    {
        /* Try to take the semaphore, call lvgl related function on success */
        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);    
        lv_task_handler();
        xSemaphoreGive(xGuiSemaphore);

        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL); // 在任务内部删除自身
}
 
void guitask_start(void)
{
    xGuiSemaphore = xSemaphoreCreateMutex();
}


#include "esp32_s3_szp.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "weather.h"

#include "gui_guider.h"
#include "custom.h"
extern lv_ui guider_ui;
extern SemaphoreHandle_t xGuiSemaphore;
LV_FONT_DECLARE(font_alipuhui20);

#define MAX_HTTP_OUTPUT_BUFFER 2048

#define YOUR_API_KEY "Sr9X3QfHuV3dXfKXU"  // 心知天气 API 密钥
#define YOUR_CITY "zhongshan"

static const char *TAG = "app";

//心知天气任务
static void xzweather_Task(void *pvParameter)
{
    char tempstr[10];
    //1-定义需要的变量
    char output_buffer[MAX_HTTP_OUTPUT_BUFFER] = {0};     //用于接收http协议返回的数据
    int content_length = 0;          //http协议头的长度

    //2-配置http结构体
    esp_http_client_config_t httpconfig;
    memset(&httpconfig,0,sizeof(httpconfig));

    static const char *URL = "http://api.seniverse.com/v3/weather/daily.json?key="YOUR_API_KEY"&location="YOUR_CITY"&language=zh-Hans&unit=c&start=0&days=3";//向配置结构体内部写入url
    httpconfig.url = URL;

    esp_http_client_handle_t client = esp_http_client_init(&httpconfig);    //初始化http连接
    esp_http_client_set_method(client, HTTP_METHOD_GET);        //设置发送请求
    
    //3-查询任务
    while (1){
        // 与目标主机创建连接，并且声明写入内容长度为0
        esp_err_t err = esp_http_client_open(client, 0);

        //如果连接失败
        if (err != ESP_OK) {
            ESP_LOGI(TAG, "Failed to open HTTP connection: %s", esp_err_to_name(err));
        } 
        //如果连接成功
        else {

            //读取目标主机的返回内容的协议头
            content_length = esp_http_client_fetch_headers(client);

            //如果协议头长度小于0，说明没有成功读取到
            if (content_length < 0) {
                ESP_LOGI(TAG, "HTTP client fetch headers failed");
            } 

            //如果成功读取到了协议头
            else {

                //读取目标主机通过http的响应内容
                int data_read = esp_http_client_read_response(client, output_buffer, MAX_HTTP_OUTPUT_BUFFER);
                if (data_read >= 0) {

                    //打印响应内容，包括响应状态，响应体长度及其内容
                    ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                    (int)esp_http_client_get_status_code(client),				//获取响应状态信息
                    (int)esp_http_client_get_content_length(client));			//获取响应信息长度
                    ESP_LOGI(TAG, "data:%s\n", output_buffer);

                    //对接收到的数据作相应的处理
                    cJSON* root = NULL;
                    root = cJSON_Parse(output_buffer);

                    // 获取 "results" 数组中的第一个元素
                    cJSON* cjson_item = cJSON_GetObjectItem(root,"results");
                    cJSON* cjson_results =  cJSON_GetArrayItem(cjson_item,0);

                    // 获取位置信息
                    cJSON* cjson_location = cJSON_GetObjectItem(cjson_results, "location");
                    cJSON* cjson_location_name = cJSON_GetObjectItem(cjson_location, "name");
                    ESP_LOGI(TAG, "Location: %s", cjson_location_name->valuestring);

                    // 获取 "daily" 数组
                    cJSON* cjson_daily = cJSON_GetObjectItem(cjson_results, "daily");

                    // 遍历 "daily" 数组，提取今天、明天和后天的数据
                    int daily_count = cJSON_GetArraySize(cjson_daily);
                    for (int i = 0; i < daily_count && i < 3; i++) // 只处理前三天
                    { 
                        cJSON* cjson_day = cJSON_GetArrayItem(cjson_daily, i);
                        
                        // 提取日期
                        cJSON* cjson_date = cJSON_GetObjectItem(cjson_day, "date");
                        // 提取 text_day
                        cJSON* cjson_text_day = cJSON_GetObjectItem(cjson_day, "text_day"); 
                        // 提取 code_day
                        cJSON* cjson_code_day = cJSON_GetObjectItem(cjson_day, "code_day");
                        // 提取 high
                        cJSON* cjson_high = cJSON_GetObjectItem(cjson_day, "high");
                        // 提取 low
                        cJSON* cjson_low = cJSON_GetObjectItem(cjson_day, "low");
                        // ESP_LOGI(TAG, "date: %s", cjson_date->valuestring);
                        // ESP_LOGI(TAG, "text_day: %s", cjson_text_day->valuestring);
                        // ESP_LOGI(TAG, "high: %s", cjson_high->valuestring);
                        // ESP_LOGI(TAG, "low: %s", cjson_low->valuestring);

                        snprintf(tempstr,sizeof(tempstr),"%s/%s",cjson_high->valuestring,cjson_low->valuestring);

                        // 根据天气代码显示图片
                        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
                        switch (atoi(cjson_code_day->valuestring))
                        {
                            case 0:
                            case 1:
                                if (i == 0) lv_obj_clear_flag(guider_ui.screen_img_qing_card1, LV_OBJ_FLAG_HIDDEN);
                                if (i == 1) lv_obj_clear_flag(guider_ui.screen_img_qing_card2, LV_OBJ_FLAG_HIDDEN);
                                if (i == 2) lv_obj_clear_flag(guider_ui.screen_img_qing_card3, LV_OBJ_FLAG_HIDDEN);
                                break;
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                                if (i == 0) lv_obj_clear_flag(guider_ui.screen_img_duoyun_card1, LV_OBJ_FLAG_HIDDEN);
                                if (i == 1) lv_obj_clear_flag(guider_ui.screen_img_duoyun_card2, LV_OBJ_FLAG_HIDDEN);
                                if (i == 2) lv_obj_clear_flag(guider_ui.screen_img_duoyun_card3, LV_OBJ_FLAG_HIDDEN);
                                break;
                            case 9:
                            case 30:
                                if (i == 0) lv_obj_clear_flag(guider_ui.screen_img_yin_card1, LV_OBJ_FLAG_HIDDEN);
                                if (i == 1) lv_obj_clear_flag(guider_ui.screen_img_yin_card2, LV_OBJ_FLAG_HIDDEN);
                                if (i == 2) lv_obj_clear_flag(guider_ui.screen_img_yin_card3, LV_OBJ_FLAG_HIDDEN);
                                break;
                            case 11:
                            case 12:
                                if (i == 0) lv_obj_clear_flag(guider_ui.screen_img_leidian_card1, LV_OBJ_FLAG_HIDDEN);
                                if (i == 1) lv_obj_clear_flag(guider_ui.screen_img_leidian_card2, LV_OBJ_FLAG_HIDDEN);
                                if (i == 2) lv_obj_clear_flag(guider_ui.screen_img_leidian_card3, LV_OBJ_FLAG_HIDDEN);
                                break;
                            case 10:
                            case 13:
                            case 14:
                            case 15:
                            case 16:
                            case 17:
                            case 18:
                                if (i == 0) lv_obj_clear_flag(guider_ui.screen_img_yu_card1, LV_OBJ_FLAG_HIDDEN);
                                if (i == 1) lv_obj_clear_flag(guider_ui.screen_img_yu_card2, LV_OBJ_FLAG_HIDDEN);
                                if (i == 2) lv_obj_clear_flag(guider_ui.screen_img_yu_card3, LV_OBJ_FLAG_HIDDEN);
                                break;
                            default:
                                break;
                        }
                        //显示位置(显示一次就好)
                        if (i == 0) lv_label_set_text(guider_ui.screen_label_location, cjson_location_name->valuestring);

                        // 显示天气现象
                        if (i == 0) lv_label_set_text(guider_ui.screen_label_weather_card1, cjson_text_day->valuestring);
                        if (i == 1) lv_label_set_text(guider_ui.screen_label_weather_card2, cjson_text_day->valuestring);
                        if (i == 2) lv_label_set_text(guider_ui.screen_label_weather_card3, cjson_text_day->valuestring);

                        //最高/最低温度
                        if (i == 0) lv_label_set_text(guider_ui.screen_label_temp_card1, tempstr);
                        if (i == 1) lv_label_set_text(guider_ui.screen_label_temp_card2, tempstr);
                        if (i == 2) lv_label_set_text(guider_ui.screen_label_temp_card3, tempstr);

                        xSemaphoreGive(xGuiSemaphore);
                    }
                } 
                //如果不成功
                else {
                    ESP_LOGI(TAG, "Failed to read response");
                }
            }
        }
        //关闭连接
        esp_http_client_close(client);
        vTaskDelay(pdMS_TO_TICKS(60000));
    }
    vTaskDelete(NULL); // 在任务内部删除自身
}


void weathertask_start(void)
{
    xTaskCreate(xzweather_Task,   "xzweather",    4096*2,NULL, 0, NULL);
}

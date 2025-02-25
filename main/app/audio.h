#pragma once
#include "esp32_s3_szp.h"

esp_err_t es8311_codec_init(void);
esp_err_t i2s_driver_init(void);
void audio_start(TaskHandle_t *task_handle);
void audio_stop(void);
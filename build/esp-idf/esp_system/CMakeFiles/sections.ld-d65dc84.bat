@echo off
cd /D E:\My_embeded_project\esp32s3\10_wifi_weather_time_version6\build\esp-idf\esp_system || (set FAIL_LINE=2& goto :ABORT)
d:\Embedded_tool\esp32\.espressif\python_env\idf5.3_py3.11_env\Scripts\python.exe D:/Embedded_tool/esp32/v5.3.2/esp-idf/tools/ldgen/ldgen.py --config E:/My_embeded_project/esp32s3/10_wifi_weather_time_version6/sdkconfig --fragments-list D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/xtensa/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_gpio/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_pm/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_mm/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/spi_flash/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_system/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_system/app.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_common/common.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_common/soc.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_rom/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/hal/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/log/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/heap/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/soc/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_hw_support/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_hw_support/dma/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_hw_support/ldo/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/freertos/linker_common.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/freertos/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/newlib/newlib.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/newlib/system_libs.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_gptimer/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_ringbuf/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_uart/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/app_trace/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_event/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_pcnt/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_spi/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_mcpwm/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_ana_cmpr/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_dac/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_rmt/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_sdm/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_i2c/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_ledc/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_driver_parlio/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/driver/twai/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_phy/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/vfs/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/lwip/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_netif/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/wpa_supplicant/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_wifi/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_adc/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_eth/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_gdbstub/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_psram/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/esp_lcd/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/espcoredump/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/ieee802154/linker.lf;D:/Embedded_tool/esp32/v5.3.2/esp-idf/components/openthread/linker.lf --input E:/My_embeded_project/esp32s3/10_wifi_weather_time_version6/build/esp-idf/esp_system/ld/sections.ld.in --output E:/My_embeded_project/esp32s3/10_wifi_weather_time_version6/build/esp-idf/esp_system/ld/sections.ld --kconfig D:/Embedded_tool/esp32/v5.3.2/esp-idf/Kconfig --env-file E:/My_embeded_project/esp32s3/10_wifi_weather_time_version6/build/config.env --libraries-file E:/My_embeded_project/esp32s3/10_wifi_weather_time_version6/build/ldgen_libraries --objdump D:/Embedded_tool/esp32/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/bin/xtensa-esp32s3-elf-objdump.exe || (set FAIL_LINE=3& goto :ABORT)
goto :EOF

:ABORT
set ERROR_CODE=%ERRORLEVEL%
echo Batch file failed at line %FAIL_LINE% with errorcode %ERRORLEVEL%
exit /b %ERROR_CODE%
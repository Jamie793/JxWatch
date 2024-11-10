#include "task_rtc.h"
#include "rtc.h"
#include "ui_main.h"
#include "stdio.h"

extern lv_ui ui_main;
static RTC_TimeTypeDef currentTime;
static RTC_DateTypeDef currentData;
uint8_t rtcBuf[10] = "08:08";
portTASK_FUNCTION_PROTO(xtask_rtc, pvParameters)
{
    for (;;)
    {
        HAL_RTC_GetTime(&hrtc, &currentTime, RTC_FORMAT_BIN);
        HAL_RTC_GetDate(&hrtc, &currentData, RTC_FORMAT_BIN);
        // snprintf((char *)rtcBuf, sizeof(rtcBuf), "%02d:%02d", currentTime.Hours, currentTime.Minutes);
        // lv_label_set_text(ui_main.screen_main_label_time, "Test");
        // lv_label_set_text_fmt(ui_main.screen_main_label_time, "%02d:%02d", currentTime.Hours, currentTime.Minutes);
        vTaskDelay(1000);
    }
}
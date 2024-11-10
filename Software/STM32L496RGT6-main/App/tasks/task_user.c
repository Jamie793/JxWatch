#include "task_user.h"
#include "main.h"
#include "tim.h"
#include "task_lcd.h"
#include "task_rtc.h"

portTASK_FUNCTION_PROTO(xtask_test, param)
{
    for (;;)
    {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        vTaskDelay(1000);
        // vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void xTaskInit(void)
{

    if (xTaskCreate(xtask_lvgl_handler, "LVGL_Handler", 128 * 5, NULL, 1, NULL) != pdPASS)
        return;

    if (xTaskCreate(xtask_lvgl_tick, "LVGL_Tick", 128, NULL, 1, NULL) != pdPASS)
        return;

    if (xTaskCreate(xtask_test, "Task_Test", 32, NULL, 4, NULL) != pdPASS)
        return;

    if (xTaskCreate(xtask_rtc, "RTC", 128 * 5, NULL, 3, NULL) != pdPASS)
        return;

    /** Start FreeRTOS Tick */
    HAL_TIM_Base_Start_IT(&htim6);
    vTaskStartScheduler();
}

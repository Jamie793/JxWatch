#include "task_lcd.h"
#include "ui_main.h"
TaskHandle_t lvglTaskToNotify;
uint8_t lv_task_handler_notification = 1;
extern void app_setup(void);
extern lv_ui ui_main;
portTASK_FUNCTION_PROTO(xtask_lvgl_tick, pvParameters)
{
    for (;;)
    {
        lv_tick_inc(10);
        vTaskDelay(10);
    }
}

portTASK_FUNCTION_PROTO(xtask_lvgl_handler, pvParameters)
{
    /** Init mutex lock */
    lvglTaskToNotify = xTaskGetCurrentTaskHandle();
    xTaskNotifyGiveIndexed(lvglTaskToNotify, lv_task_handler_notification);

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    /* Initialize UI*/
    // ui_init();
    lv_demo_benchmark();
    // lv_demo_music();
    // lv_demo_widgets();
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);

    for (;;)
    {
        if (ulTaskNotifyTakeIndexed(lv_task_handler_notification, pdTRUE, portMAX_DELAY) != pdFALSE)
        {
            /* code */
            lv_task_handler();
            vTaskDelay(1);
            xTaskNotifyGiveIndexed(lvglTaskToNotify, lv_task_handler_notification);
        }
    }

    vTaskDelete(NULL);
}
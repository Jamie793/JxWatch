#include "main.h"
static SemaphoreHandle_t uixMutex;

portTASK_FUNCTION_PROTO(xTask_Lvgl_handler, pvParameters)
{
    uixMutex = xSemaphoreCreateMutex();

    /* Turn on LCD backlight */
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, SET);
    lv_init();
    lv_port_display_init();
    lv_obj_t *label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Hello world");

    for (;;)
    {
        /* code */
        if (xSemaphoreTake(uixMutex, portMAX_DELAY) == pdTRUE)
        {
            lv_task_handler();
            xSemaphoreGive(uixMutex);
        }
        vTaskDelay(1);
    }

    vTaskDelete(NULL);
}
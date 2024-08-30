#include "main.h"
#include "semphr.h"

static SemaphoreHandle_t uixMutex;
TaskHandle_t lvglTaskToNotify;

portTASK_FUNCTION_PROTO(xTask_Lvgl_handler, pvParameters)
{
    /** Init mutex lock */
    uixMutex = xSemaphoreCreateMutex();
    lvglTaskToNotify = xTaskGetCurrentTaskHandle();

    if (uixMutex == NULL)
        return;

    lv_init();
    lv_port_disp_init();

    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello world\nHello Jamiexu");
    lv_obj_align(label, LV_DIR_ALL, 80, 160);

    for (;;)
    {
        /* code */
        lv_task_handler();
        xSemaphoreGive(uixMutex);
        vTaskDelay(20);
    }

    vTaskDelete(NULL);
}
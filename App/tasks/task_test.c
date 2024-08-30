#include "main.h"

portTASK_FUNCTION_PROTO(xTask_Test, param)
{
    for (;;)
    {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
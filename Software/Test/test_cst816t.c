#include "cst816t.h"
#include "main.h"

void test_cst816t(void){
    LCD_TP_RST_GPIO_Port->ODR &= ~LCD_TP_RST_Pin;
    HAL_Delay(500);
    LCD_TP_RST_GPIO_Port->ODR |= LCD_TP_RST_Pin;
    HAL_Delay(100);

    volatile uint8_t reg = cst816t_read_reg(0xA7);
    reg = 2;
} 

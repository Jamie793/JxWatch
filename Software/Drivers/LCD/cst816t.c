/**
 * @file cst816t.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "cst816t.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t cst816t_read_reg(uint8_t reg)
{
    if (HAL_I2C_Master_Transmit(&hi2c1, CST816T_ADDR_WRITE, &reg, 1, 0xFFFF) == HAL_OK)
    {
        if (HAL_I2C_Master_Receive(&hi2c1, CST816T_ADDR_READ, &reg, 1, 0xFFFF) == HAL_OK)
        {
            return reg;
        }
        else
        {
            Error_Handler();
        }
    }
    else
    {
        volatile uint8_t error = HAL_I2C_GetError(&hi2c1);
        Error_Handler();
    }
    return 0xFF;
}

void cst816t_write_reg(uint8_t reg, uint8_t data)
{
    uint8_t temp[2];
    temp[0] = reg;
    temp[1] = data;

    if (HAL_I2C_Master_Transmit(&hi2c1, CST816T_ADDR_WRITE, &temp, 2, 0xFFFF) == HAL_OK)
    {
        
    }
    else
    {
        volatile uint8_t error = HAL_I2C_GetError(&hi2c1);
        Error_Handler();
    }
}

uint8_t cst816t_read_ID(void)
{
    return cst816t_read_reg(0xA7);
}

uint8_t cst816t_self_check(void)
{
    return cst816t_read_ID() == CST816T_CHIP_ID;
}

cst816t_gesture_t cst816t_read_gesture(void){
    return cst816t_read_reg(0x01);
}

uint8_t cst816t_read_finger_nums(void){
    return cst816t_read_reg(0x02);
}

uint16_t cst816t_read_x(void){
    return (cst816t_read_reg(0x03) << 8) | cst816t_read_reg(0x04);
}

uint16_t cst816t_read_y(void){
    return (cst816t_read_reg(0x05) << 8) | cst816t_read_reg(0x06);
}
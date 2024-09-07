#ifndef __CST816T_JAMIEXU_H__
#define __CST816T_JAMIEXU_H__
#include "stm32l4xx_hal.h"

#define CST816T_CHIP_ID 0xB5

#define CST816T_ADDR 0x15

#define CST816T_ADDR_WRITE (CST816T_ADDR << 0x01u)

#define CST816T_ADDR_READ (CST816T_ADDR_WRITE | 0x01u)

typedef enum
{
    CST816T_GEN_NO_GESTURE = 0x00,
    CST816T_GEN_SWIPE_UP = 0x01,
    CST816T_GEN_SWIPE_DOWN = 0x02,
    CST816T_GEN_SWIPE_LEFT = 0x03,
    CST816T_GEN_SWIPE_RIGHT = 0x04,
    CST816T_GEN_SINGLE_TAP = 0x05,
    CST816T_GEN_DOUBLE_TAP = 0x0B,
    CST816T_GEN_LONG_PRESS = 0x0C
} cst816t_gesture_t;

uint8_t cst816t_read_reg(uint8_t reg);

void cst816t_write_reg(uint8_t reg, uint8_t data);

uint8_t cst816t_read_ID(void);

uint8_t cst816t_self_check(void);

cst816t_gesture_t cst816t_read_gesture(void);

uint8_t cst816t_read_finger_nums(void);

uint16_t cst816t_read_x(void);

uint16_t cst816t_read_y(void);

#endif
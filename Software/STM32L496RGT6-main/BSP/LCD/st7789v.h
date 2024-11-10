
/**
 * @file st7789v.h
 * @author Jamiexu(Jamie793/Jamies19) (doxm@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __ST77789_JAMIEXU_H__
#define __ST77789_JAMIEXU_H__

#include "main.h"

typedef enum
{
	ST7789V_CMD_NOP = 0X00,	   /* NOP */
	ST7789V_CMD_SWRESET = 0X01, /*  Software Reset */
	ST7789V_CMD_RDDID = 0x04,  /* Read Display ID */
	ST7789V_CMD_RDDST = 0x09, /* Read Display Status */
	ST7789V_CMD_RDDPM = 0x0A, /*  Read Display Power Mode */
	ST7789V_CMD_RDDMADCTL = 0x0B, /* Read Display MADCTL */
	ST7789V_CMD_RDDCOLMOD = 0x0C, /* Read Display Pixel Format */
	ST7789V_CMD_RDDIM = 0x0D, /* Read Display Image Mode */
	ST7789V_CMD_RDDSM = 0x0E, /* Read Display Signal Mode */
	ST7789V_CMD_RDDSDR = 0x0F, /* Read Display Self-Diagnostic Result */
	ST7789V_CMD_SLPIN = 0x10,
	ST7789V_CMD_SLPOUT = 0x11,
	ST7789V_CMD_PTLON = 0x12,
	ST7789V_CMD_NORON = 0x13,
	ST7789V_CMD_INVOFF = 0x20,
	ST7789V_CMD_INVON = 0x21,
	ST7789V_CMD_GAMSET = 0x26,
	ST7789V_CMD_DISPOFF = 0x28,
	ST7789V_CMD_DISPON = 0x29,
	ST7789V_CMD_CASET = 0x2A,
	ST7789V_CMD_RASET = 0x2B,
	ST7789V_CMD_RAMWR = 0x2C,
	ST7789V_CMD_RAMRD = 0x2E,
	ST7789V_CMD_PTLAR = 0x30,
	ST7789V_CMD_VSCRDEF = 0x33,
	ST7789V_CMD_TEOFF = 0x34,
	ST7789V_CMD_TEON = 0x35,
	ST7789V_CMD_MADCTL = 0x36,
	ST7789V_CMD_VSCRSADD = 0x37,
	ST7789V_CMD_IDMOFF = 0x38,
	ST7789V_CMD_IDMON = 0x39,
	ST7789V_CMD_COLMOD = 0x3A,
	ST7789V_CMD_RAMWRC = 0x3C,
	ST7789V_CMD_RAMRDC = 0x3E,
	ST7789V_CMD_TESCAN = 0x44,
	ST7789V_CMD_RDTESCAN = 0x45,
	ST7789V_CMD_WRDISBV = 0x51,
	ST7789V_CMD_RDDISBV = 0x52,
	ST7789V_CMD_WRCTRLD = 0x53,
	ST7789V_CMD_RDCTRLD = 0x54,
	ST7789V_CMD_WRCACE = 0x55,
	ST7789V_CMD_RDCABC = 0x56,
	ST7789V_CMD_WRCABCMB = 0x5E,
	ST7789V_CMD_RDCABCMB = 0x5F,
	ST7789V_CMD_RDABCSDR = 0x68,
	ST7789V_CMD_RDID1 = 0xDA,
	ST7789V_CMD_RDID2 = 0xDB,
	ST7789V_CMD_RDID3 = 0xDC
} st7789v_cmd_t;

typedef enum{
	/* MY MX MV */
	ST7789V_ROT_0D = 0x00,
	ST7789V_ROT_90D = 0x03,
	ST7789V_ROT_180D = 0x06,
	ST7789V_ROT_270D = 0x05
} st7789v_rotation_t;

#define LCD_CMD_EOF 0xFF

extern SPI_HandleTypeDef hspi1;

static void st7789v_send_cmd_list(uint8_t *cmds);

static void st7789v_send_cmd(st7789v_cmd_t cmd, uint8_t *param, uint8_t param_size);

void st7789v_read_id(void);

void st7789v_set_window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

void st7789v_set_rotation(st7789v_rotation_t rot);

void st7789v_set_sleep(uint8_t mode);

void st7789v_init(void);

// void st7789_send_color()

#endif
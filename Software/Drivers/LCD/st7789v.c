/**
 * @file st7789v.c
 * @author Jamiexu(Jamie793/Jamies19) (doxm@foxmail.com)
 * @brief
 * @version 0.1
 * @date 2024-08-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "st7789v.h"

static uint8_t MADCL = 0x08;

static const uint8_t init_list[] = {
	/** cmd param_size param(param_size != 0) delay_ms */
	ST7789V_CMD_SWRESET, 0, 120,
	ST7789V_CMD_SLPOUT, 0, 5,
	ST7789V_CMD_NORON, 0, 20,
	ST7789V_CMD_GAMSET, 1, 0x01, 0,
	ST7789V_CMD_MADCTL, 1, 0x08, 0,
	ST7789V_CMD_COLMOD, 1, 0x65, 0,
	ST7789V_CMD_DISPON, 0, 0,
	LCD_CMD_EOF};

static void st7789v_send_cmd_list(uint8_t *cmds)
{
	uint8_t cmd;
	uint8_t *param;
	uint8_t param_size;
	while (1)
	{
		cmd = *cmds++;
		param_size = *cmds++;
		if (param_size != 0)
		{
			param = cmds;
			cmds += param_size;
		}

		if (cmd == LCD_CMD_EOF)
			break;

		st7789v_send_cmd(cmd, param, param_size);
		vTaskDelay(pdMS_TO_TICKS(*cmds));
		cmds++;
	}
}

static void st7789v_send_cmd(st7789v_cmd_t cmd, uint8_t *param, uint8_t param_size)
{
	/** Select chip */
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
	
	if (HAL_SPI_Transmit(&hspi1, &cmd, 1, 0xFF) == HAL_OK)
	{
		if (param_size != 0 && param != NULL)
		{
			HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);

			HAL_SPI_Transmit(&hspi1, param, param_size, 0xFF);
		}
	}

	/** Unselect chip */
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
}

void st7789v_read_id(void)
{
	uint8_t data = ST7789V_CMD_RDDID;
	uint8_t ID1 = 0xFF;
	uint8_t ID2 = 0xFF;
	uint8_t ID3 = 0xFF;
	// st7789v_send_cmd(ST7789V_CMD_RDDPM, NULL, 0);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(&hspi1, &data, 1, 0xFF);

	data = 0xFF;
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
	
	HAL_SPI_Transmit(&hspi1, &data, 1, 0xFF);
	HAL_SPI_Transmit(&hspi1, &data, 1, 0xFF);

	HAL_SPI_Receive(&hspi1, &ID1, 1, 0xFF);
	HAL_SPI_Receive(&hspi1, &ID2, 1, 0xFF);
	HAL_SPI_Receive(&hspi1, &ID3, 1, 0xFF);

	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
	vTaskDelay(data);
}

void st7789v_set_window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint8_t param[4];
	param[0] = (x1 >> 8) & 0xFF;
	param[1] = x1 & 0xFF;
	param[2] = (x2 >> 8) & 0xFF;
	param[3] = x2 & 0xFF;
	st7789v_send_cmd(ST7789V_CMD_CASET, param, 4);

	param[0] = (y1 >> 8) & 0xFF;
	param[1] = y1 & 0xFF;
	param[2] = (y2 >> 8) & 0xFF;
	param[3] = y2 & 0xFF;
	st7789v_send_cmd(ST7789V_CMD_RASET, param, 4);

	st7789v_send_cmd(ST7789V_CMD_RAMWR, NULL, 0);
}

void st7789v_set_rotation(st7789v_rotation_t rot){
	MADCL &= ~(0x07 << 5);
	MADCL |= (rot << 5);
	st7789v_send_cmd(ST7789V_CMD_MADCTL, &MADCL, 1);
}

void st7789v_init(void)
{
	st7789v_send_cmd_list(init_list);

	st7789v_set_rotation(ST7789V_ROT_180D);

	// st7789v_read_id();

	/* Testing */
// 	st7789v_set_window(50, 50, 0xFF, 0xFF0);

// 	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

// 	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);

// 	uint32_t i = 0xFFFF;

// 	while (i--)
// 	{
// 		uint16_t data = 0x1F00;
// 		HAL_SPI_Transmit(&hspi1, &data, 2, 0xFF);
// 	}
// 	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
}
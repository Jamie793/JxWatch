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

// static const uint8_t init_list[] = {
// 	/** cmd param_size param(param_size != 0) delay_ms */
// 	ST7789V_CMD_SWRESET, 0, 120,
// 	ST7789V_CMD_SLPOUT, 0, 5,
// 	ST7789V_CMD_NORON, 0, 20,
// 	ST7789V_CMD_INVON, 0, 20, // Display inversion on
// 	ST7789V_CMD_GAMSET, 1, 0x01, 0,
// 	ST7789V_CMD_MADCTL, 1, 0x08, 0,
// 	ST7789V_CMD_COLMOD, 1, 0x65, 0,
// 	ST7789V_CMD_DISPON, 0, 0,
// 	LCD_CMD_EOF};
// static const uint8_t init_list[] = {
// 	/** cmd param_size param(param_size != 0) delay_ms */
// 	ST7789V_CMD_SWRESET, 0, 120,
// 	0x36, 1, 0x00, 0,
// 	0x3A, 1, 0x05, 0,
// 	0xB2, 5, 0x0C, 0x0C, 0x00, 0x33, 0x33, 0,
// 	0xB7, 1, 0x35, 0,
// 	0xBB, 1, 0x19, 0,
// 	0xC0, 1, 0x2C, 0,
// 	0xC2, 1, 0x01, 0,
// 	0xC3, 1, 0x12, 0,
// 	0xC4, 1, 0x20, 0,
// 	0xC6, 1, 0x0F, 0,
// 	0xD0, 2, 0xA4, 0xA1, 0,
// 	0xE0, 14, 0xD0, 0x04, 0x0D, 0x11, 0x13, 0x2B, 0x3F, 0x54, 0x4C, 0x18, 0x0D, 0x0B, 0x1F, 0x23, 0,
// 	0xE1, 14, 0xD0, 0x04, 0x0C, 0x11, 0x13, 0x2C, 0x3F, 0x44, 0x51, 0x2F, 0x1F, 0x1F, 0x20, 0x23, 0,
// 	0x21, 0, 0,
// 	0x11, 0, 0,
// 	0x29, 0, 0,
// 	LCD_CMD_EOF};
// static const uint8_t init_list[] = {
// 	/** cmd param_size param(param_size != 0) delay_ms */
// 	ST7789V_CMD_SWRESET, 0, 120,
// 	0x3A, 1, 0x55, 0,
// 	0xB2, 5, 0x0C, 0x0C, 0x00, 0x33, 0x33, 0,
// 	0xB7, 1, 0x75, 0,
// 	0xC2, 1, 0x01, 0,
// 	0xC3, 1, 0x16, 0,
// 	0xC4, 1, 0x20, 0,
// 	0xC6, 1, 0x0F, 0,
// 	0xD0, 2, 0xA4, 0xA1, 0,
// 	0xD6, 1, 0xA1, 0,
// 	0xBB, 1, 0x3B, 0,
// 	0xE0, 14, 0xF0, 0x0B, 0x11, 0x0E, 0x0D, 0x19, 0x36, 0x33, 0x4B, 0x07, 0x14, 0x14, 0x2C, 0x2E, 0,
// 	0xE1, 14, 0xF0, 0x0D, 0x12, 0x0B, 0x09, 0x03, 0x32, 0x44, 0x48, 0x39, 0x16, 0x16, 0x2d, 0x30, 0,
// 	0xE4, 3, 0x25, 0x00, 0x00, 0,
// 	0x21, 0, 0,
// 	0x29, 0, 0,
// 	0x2c, 0, 0,
// 	LCD_CMD_EOF};

static const uint8_t init_list[] = {
	/** cmd param_size param(param_size != 0) delay_ms */
	ST7789V_CMD_SWRESET, 0, 120,
	ST7789V_CMD_SLPOUT, 0, 120,
	ST7789V_CMD_NORON, 0, 20,
	ST7789V_CMD_INVON, 0, 20, // Display inversion on
	ST7789V_CMD_MADCTL, 1, 0x08, 0,
	// ST7789V_CMD_GAMSET, 1, 0x01, 0,
	0xB0, 2, 0x00, 0xE0, 0,
	0xB6, 2, 0x0A, 0x82, 0,
	0xB2, 5, 0x0C, 0x0C, 0x00, 0x33, 0x33, 0,
	0xB7, 1, 0x35, 0,
	0xBB, 1, 0x28, 0,
	0xC0, 1, 0x0C, 0,
	0xC2, 2, 0x01, 0xFF, 0,
	0xC3, 1, 0x20, 0,
	0xC6, 1, 0x0F, 0,
	0xD0, 2, 0xA4, 0xA1, 0,
	0xE0, 14, 0xD0, 0x00, 0x02, 0x07, 0x0A, 0x28, 0x32, 0x44, 0x42, 0x06, 0x0E, 0x12, 0x14, 0x17, 0,
	0xE1, 14, 0xD0, 0x00, 0x02, 0x07, 0x0A, 0x28, 0x31, 0x54, 0x47, 0x0e, 0x1C, 0x17, 0x1B, 0x1E, 0,
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
	// HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
	LCD_CS_GPIO_Port->ODR &= ~LCD_CS_Pin;

	// HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
	LCD_DC_GPIO_Port->ODR &= ~LCD_DC_Pin;

	if (HAL_SPI_Transmit(&hspi1, &cmd, 1, 0xFF) == HAL_OK)
	{
		if (param_size != 0 && param != NULL)
		{
			// HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
			LCD_DC_GPIO_Port->ODR |= LCD_DC_Pin;

			HAL_SPI_Transmit(&hspi1, param, param_size, 0xFF);
		}
	}

	/** Unselect chip */
	// HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
	LCD_CS_GPIO_Port->ODR |= LCD_CS_Pin;
}

// void st7789v_read_id(void)
// {
// 	uint8_t data = ST7789V_CMD_RDID1;
// 	uint16_t ID1 = 0xFFFF;
// 	uint8_t ID2 = 0xFF;
// 	uint8_t ID3 = 0xFF;
// 	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
// 	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);

// 	HAL_SPI_Transmit(&hspi1, &data, 1, 0xFF);

// 	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);

// 	// Dummy code
// 	HAL_SPI_Transmit(&hspi1, &data, 1, 0xFF);

// 	HAL_SPI_Receive(&hspi1, &ID1, 2, 0xFF);

// 	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
// }

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

void st7789v_set_rotation(st7789v_rotation_t rot)
{
	MADCL &= ~(0x07 << 5);
	MADCL |= (rot << 5);
	st7789v_send_cmd(ST7789V_CMD_MADCTL, &MADCL, 1);
}

void st7789v_test(void)
{
	st7789v_set_window(0, 0, 239, 319);

	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);

	uint32_t i = 240 * 320;
	uint16_t data = 0xF800;
	while (i--)
	{
		// HAL_SPI_Transmit_DMA(&hspi1, &data, 2);
		HAL_SPI_Transmit(&hspi1, &data, 2, 0xFF);
	}
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
}

void st7789v_init(void)
{
	st7789v_send_cmd_list(init_list);

	st7789v_set_rotation(ST7789V_ROT_180D);

	// st7789v_read_id();

	/* Testing */
	// st7789v_test();
}
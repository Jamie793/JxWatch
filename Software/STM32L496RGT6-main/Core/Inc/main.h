/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "lvgl.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTTERY_ADC_Pin GPIO_PIN_0
#define BTTERY_ADC_GPIO_Port GPIOC
#define VCC1V8_CTL_Pin GPIO_PIN_1
#define VCC1V8_CTL_GPIO_Port GPIOC
#define ESP_HSPI_MISO_Pin GPIO_PIN_2
#define ESP_HSPI_MISO_GPIO_Port GPIOC
#define ESP_HSPI_MOSI_Pin GPIO_PIN_3
#define ESP_HSPI_MOSI_GPIO_Port GPIOC
#define LCD_TP_INT_Pin GPIO_PIN_3
#define LCD_TP_INT_GPIO_Port GPIOA
#define LCD_TP_INT_EXTI_IRQn EXTI3_IRQn
#define LCD_DC_Pin GPIO_PIN_4
#define LCD_DC_GPIO_Port GPIOA
#define LCD_SCK_Pin GPIO_PIN_5
#define LCD_SCK_GPIO_Port GPIOA
#define ESP_HSPI_CS_Pin GPIO_PIN_6
#define ESP_HSPI_CS_GPIO_Port GPIOA
#define LCD_SDA_Pin GPIO_PIN_7
#define LCD_SDA_GPIO_Port GPIOA
#define LCD_TP_RST_Pin GPIO_PIN_4
#define LCD_TP_RST_GPIO_Port GPIOC
#define LCD_RST_Pin GPIO_PIN_5
#define LCD_RST_GPIO_Port GPIOC
#define ESP_EN_CTL_Pin GPIO_PIN_0
#define ESP_EN_CTL_GPIO_Port GPIOB
#define LCD_BL_Pin GPIO_PIN_1
#define LCD_BL_GPIO_Port GPIOB
#define LCD_CS_Pin GPIO_PIN_2
#define LCD_CS_GPIO_Port GPIOB
#define ESP_HSPI_SCK_Pin GPIO_PIN_10
#define ESP_HSPI_SCK_GPIO_Port GPIOB
#define MAX30102_INT_Pin GPIO_PIN_12
#define MAX30102_INT_GPIO_Port GPIOB
#define MAX30102_INT_EXTI_IRQn EXTI15_10_IRQn
#define MAX30102_SCK_Pin GPIO_PIN_13
#define MAX30102_SCK_GPIO_Port GPIOB
#define MAX30102_SDA_Pin GPIO_PIN_14
#define MAX30102_SDA_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_6
#define LED0_GPIO_Port GPIOC
#define USART1_TX_Pin GPIO_PIN_9
#define USART1_TX_GPIO_Port GPIOA
#define USART1_RX_Pin GPIO_PIN_10
#define USART1_RX_GPIO_Port GPIOA
#define LCD_TP_SCK_Pin GPIO_PIN_6
#define LCD_TP_SCK_GPIO_Port GPIOB
#define LCD_TP_SDA_Pin GPIO_PIN_7
#define LCD_TP_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
#ifndef __TASK_LCD_JAMIEXU_H__
#define __TASK_LCD_JAMIEXU_H__
#include "main.h"
#include "semphr.h"
#include "lv_demo_benchmark.h"
#include "lv_demo_music.h"
#include "lv_demo_widgets.h"

portTASK_FUNCTION_PROTO(xtask_lvgl_handler, pvParameters);

portTASK_FUNCTION_PROTO(xtask_lvgl_tick, pvParameters);

#endif
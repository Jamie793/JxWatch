#ifndef __UI_STOPWATCH_JAMIEXU_H__
#define __UI_STOPWATCH_JAMIEXU_H__
#include "lvgl.h"
#include "ui.h"


static void ui_setup_cb(void);
static void ui_destory_cb(void);
static void event_setup_cb(void);
static void btn_flag_cb(lv_event_t *e);
static void btn_start_cb(lv_event_t *e);
static void btn_stop_cb(lv_event_t *e);
static void timer_cb(lv_timer_t *e);
#endif
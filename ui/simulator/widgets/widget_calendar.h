#ifndef __WIDGEGET_CALENDAR_JAMIEXU_H__
#define __WIDGEGET_CALENDAR_JAMIEXU_H__
#include "lvgl.h"
#include "font.h"

static uint8_t is_leap_year(uint16_t year);

static void load_date(lv_calendar_date_t date);

lv_obj_t *widget_calendar_create(lv_obj_t *parent);

void widget_calendar_set_today(lv_calendar_date_t date);

#endif
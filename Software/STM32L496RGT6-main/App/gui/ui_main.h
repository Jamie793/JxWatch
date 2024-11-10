#ifndef __UI_MAIN_JAMIEXU_H__
#define __UI_MAIN_JAMIEXU_H__

#include "lvgl.h"
#include "lv_fonts.h"

typedef struct
{

    lv_obj_t *screen_main;
    bool screen_main_del;
    lv_obj_t *screen_main_tileview;
    lv_obj_t *screen_main_tileview_tile;
    lv_obj_t *screen_main_tileview_tile_1;
    lv_obj_t *screen_main_label_time;
    lv_obj_t *screen_main_label_date;
    lv_obj_t *screen_main_meter_battery;
    lv_meter_scale_t *screen_main_meter_battery_scale_0;
    lv_meter_indicator_t *screen_main_meter_battery_scale_0_ndline_0;
    lv_obj_t *screen_main_chart_heart;
    lv_chart_series_t *screen_main_chart_heart_0;
    lv_obj_t *screen_main_label_info;
    lv_obj_t *screen_main_label_bluetooth;
    lv_obj_t *screen_main_label_wifi;
    lv_obj_t *screen_main_cont_1;
    lv_obj_t *screen_main_list_1;
    lv_obj_t *screen_main_list_1_item0;
    lv_obj_t *screen_main_list_1_item1;
    lv_obj_t *screen_main_list_1_item2;
    lv_obj_t *screen_main_list_1_item3;
    lv_obj_t *screen_main_list_1_item4;
    lv_obj_t *screen_main_img_1;
    lv_obj_t *screen_main_label_weather_sub;
    lv_obj_t *screen_main_label_weather_main;
    lv_obj_t *screen_main_label_8;
} lv_ui, *lv_ui_ptr;

static void setup_scr_screen_main(lv_ui *ui);

#endif

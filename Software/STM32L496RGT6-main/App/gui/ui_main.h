#ifndef __UI_MAIN_JAMIEXU_H__
#define __UI_MAIN_JAMIEXU_H__
#include "lvgl.h"

typedef struct
{
    lv_obj_t *scrMain;
    bool scrMain_del;
    lv_obj_t *scrMain_tileview;
    lv_obj_t *scrMain_tileview_tileMain;
    lv_obj_t *scrMain_tileview_tileWeather;
    lv_obj_t *scrMain_tileview_tileSettings;
    lv_obj_t *scrMain_tileview_tileMenu;
    lv_obj_t *scrMain_labelTime;
    lv_obj_t *scrMain_labelDate;
    lv_obj_t *scrMain_chartHeart;
    lv_obj_t *scrMain_labelBattery;
    lv_obj_t *scrMain_img_2;
    lv_obj_t *scrMain_cont_1;
    lv_obj_t *scrMain_tableWeatherInfo;
    lv_obj_t *scrMain_imageWeather;
    lv_obj_t *scrMain_labelSubWeather;
    lv_obj_t *scrMain_labelWeather;
    lv_obj_t *scrMain_label_8;

    lv_obj_t *scrMain_Notif;
    lv_obj_t *scrMain_Notif_tips;

    lv_obj_t *gridTools;
} lv_ui_main_t;

void ui_main_init(void);
#endif
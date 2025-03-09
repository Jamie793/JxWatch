/**
 * @file ui_main_menu.c
 * @author Jamiexu (doxm@foxmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "ui_main_menu.h"
#include "ui_calendar.h"
#include "ui_calculator.h"
#include "ui_weather.h"
#include "font.h"
#include "anim.h"

#define MENU_ITEM_MAX_SIZE 4

// LV_IMG_DECLARE(_alarm_alpha_30x30);
// LV_IMG_DECLARE(_calculator_alpha_30x30);
// LV_IMG_DECLARE(_calender_alpha_30x30);
// LV_IMG_DECLARE(_timer_alpha_30x30);
// LV_IMG_DECLARE(_time_alpha_30x30);
// LV_IMG_DECLARE(_heart_alpha_30x30);
// LV_IMG_DECLARE(_Bed_alpha_30x30);
// LV_IMG_DECLARE(_weather_qing_alpha_30x30_map);
LV_IMG_DECLARE(_tianqi_alpha_30x30);
LV_IMG_DECLARE(_calendar_alpha_30x30);
LV_IMG_DECLARE(_jisuanqi_alpha_30x30);
LV_IMG_DECLARE(_stopwatch_alpha_30x30);

static const ui_main_menu_item_t menuItmes[MENU_ITEM_MAX_SIZE] = {
    {.icon = &_tianqi_alpha_30x30,
     .name = "Weather"},
    {.icon = &_calendar_alpha_30x30,
     .name = "Calendar"},
    {.icon = &_jisuanqi_alpha_30x30,
     .name = "Calcuator"},
    {.icon = &_stopwatch_alpha_30x30,
     .name = "Stopwatch"}};

static void my_onclike_event_cb(lv_event_t *e)
{
    // lv_point_t point;
    ui_main_menu_item_t *item = lv_event_get_user_data(e);
    // lv_indev_t *indev = lv_indev_get_act();
    // if (indev == NULL)
    //     return;
    // lv_indev_get_point(indev, &point);
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        if (item == &menuItmes[0])
        {
            ui_load(LV_PAGE_WEATHER);
        }
        // else if (item == &menuItmes[1])
        // {
            
        // }
        else if (item == &menuItmes[2])
        {
            ui_load(LV_PAGE_CALCULATOR);
        }
        else if (item == &menuItmes[3])
        {
            ui_load(LV_PAGE_STOPWATCH);
        }
    }
}

void ui_main_menu_load(lv_obj_t *tile)
{
    lv_obj_t *cont = lv_obj_create(tile);
    lv_obj_set_pos(cont, 0, 0);
    lv_obj_set_size(cont, MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x0000000), LV_PART_MAIN);
    lv_obj_set_style_border_opa(cont, LV_OPA_0, LV_PART_MAIN);

    uint8_t i;
    for (i = 0; i < MENU_ITEM_MAX_SIZE; i++)
    {
        lv_obj_t *obj;
        lv_obj_t *img;
        lv_obj_t *label;

        /*Add items to the column*/
        obj = lv_btn_create(cont);
        lv_obj_set_size(obj, LV_PCT(100), LV_PCT(15));
        lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_bg_opa(obj, LV_OPA_20, LV_PART_MAIN);
        lv_obj_set_style_shadow_opa(obj, LV_OPA_0, LV_PART_MAIN);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xeeeeee), LV_STATE_PRESSED);
        lv_obj_add_event_cb(obj, my_onclike_event_cb, LV_EVENT_CLICKED, &menuItmes[i]);

        img = lv_img_create(obj);
        lv_img_set_src(img, menuItmes[i].icon);

        label = lv_label_create(obj);
        lv_label_set_text(label, menuItmes[i].name);
        lv_obj_set_style_pad_top(label, 10, LV_PART_MAIN);
        lv_obj_set_style_pad_left(label, 10, LV_PART_MAIN);
    }
}

static void ui_destory_cb(void)
{
}

static void event_setup_cb(void)
{
}
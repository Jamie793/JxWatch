/**
 * @file ui_weather.c
 * @author Jamiexu (doxm@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ui_weather.h"

lv_ui_page_t lv_ui_page_weather = {
	.id = LV_PAGE_WEATHER,
    .page = NULL,
	.ui_setup_cb = ui_setup_cb,
	.ui_destory_cb = ui_destory_cb,
	.event_setup_cb = event_setup_cb
};

LV_IMG_DECLARE(_tianqi_alpha_30x30);

static int16_t map_value(int x) {
    return (int16_t)(0.5 * x + 50);
}

static void chart_draw_event_cb(lv_event_t *e){
    lv_obj_draw_part_dsc_t *dsc = (lv_obj_draw_part_dsc_t*)lv_event_get_draw_part_dsc(e);
    if(!lv_obj_draw_part_check_type(dsc, &lv_chart_class, LV_CHART_DRAW_PART_TICK_LABEL )) return;
    if(dsc->text){
        lv_snprintf(dsc->text, dsc->text_length, "%d/%d", 1, 21);
    }
}

static void ui_setup_cb(void)
{
    lv_ui_page_weather.page = lv_obj_create(NULL);
    lv_obj_t *page = lv_ui_page_weather.page;
    lv_obj_set_pos(page, 14, 14);
    lv_obj_set_size(page, MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_obj_set_scrollbar_mode(page, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(page, LV_OBJ_FLAG_SCROLLABLE);
    // lv_obj_set_flex_flow(page, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(page, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(page, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_obj_t *cont = lv_obj_create(page);
    lv_obj_set_size(cont, LV_PCT(100), 80);
    lv_obj_set_style_bg_opa(cont, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_border_opa(cont, LV_OPA_0, LV_PART_MAIN);

    lv_obj_t *img = lv_img_create(cont);
    lv_img_set_src(img, &_tianqi_alpha_30x30);
    lv_obj_set_style_img_recolor(img, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t *label = lv_label_create(cont);
    lv_label_set_text(label, "Today");
    lv_obj_align_to(label, img, LV_ALIGN_OUT_RIGHT_MID, 15, -15);
    lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_22, LV_PART_MAIN);

    lv_obj_t *date = lv_label_create(cont);
    lv_label_set_text(date, "Tue. 21 Jan");
    lv_obj_set_width(date, 100);
    lv_label_set_long_mode(date, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align_to(date, img, LV_ALIGN_OUT_RIGHT_MID, 15, 15);
    lv_obj_set_style_text_font(date, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_set_style_text_color(date, lv_color_hex(0xFFFFFF), LV_PART_MAIN);


    lv_obj_t *arc = lv_arc_create(page);
    lv_obj_set_size(arc, 120, 120);
    lv_obj_align(arc, LV_ALIGN_CENTER, 0, 10);
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);
    lv_arc_set_value(arc, map_value(26));

    lv_obj_t *place = lv_label_create(page);
    lv_obj_set_width(place, 100);
    lv_label_set_text(place, "ShenZhen Longgan.");
    lv_label_set_long_mode(place, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align_to(place, date, LV_ALIGN_OUT_BOTTOM_MID, 0, 15);
    lv_obj_set_style_text_color(place, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t *weather = lv_label_create(page);
    lv_label_set_text(weather, "26°");
    lv_obj_align(weather, LV_ALIGN_CENTER, 0, 10);
    lv_obj_set_style_text_font(weather, &lv_font_montserrat_28, LV_PART_MAIN);
    lv_obj_set_style_text_color(weather, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t *cont2 = lv_obj_create(page);
    lv_obj_set_size(cont2, LV_PCT(105), 90);
    lv_obj_align_to(cont2, arc, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    lv_obj_set_style_bg_color(cont2, lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_opa(cont2, LV_OPA_0, LV_PART_MAIN);

    lv_obj_t *chart = lv_chart_create(cont2);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    lv_obj_set_size(chart, LV_PCT(100), 60);
    lv_obj_set_style_bg_color(chart, lv_color_hex3(0x000), LV_PART_MAIN);


    lv_chart_series_t *series_1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t *series_2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_SECONDARY_Y);
    
    lv_chart_set_next_value(chart, series_1, 31);
    lv_chart_set_next_value(chart, series_1, 21);
    lv_chart_set_next_value(chart, series_1, 28);
    lv_chart_set_next_value(chart, series_1, 17);
    lv_chart_set_next_value(chart, series_1, 5);
    lv_chart_set_next_value(chart, series_1, 9);
    lv_chart_set_next_value(chart, series_1, 10);

    lv_chart_set_next_value(chart, series_2, 35);
    lv_chart_set_next_value(chart, series_2, 0);
    lv_chart_set_next_value(chart, series_2, 28);
    lv_chart_set_next_value(chart, series_2, 31);
    lv_chart_set_next_value(chart, series_2, 10);
    lv_chart_set_next_value(chart, series_2, 28);
    lv_chart_set_next_value(chart, series_2, 9);

    lv_chart_refresh(chart);

}

static void ui_destory_cb(void)
{
}

static void event_setup_cb(void)
{
}

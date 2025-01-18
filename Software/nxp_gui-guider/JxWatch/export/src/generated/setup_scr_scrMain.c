/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_scrMain(lv_ui *ui)
{
	//Write codes scrMain
	ui->scrMain = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrMain, 240, 320);
	lv_obj_set_scrollbar_mode(ui->scrMain, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_tileview
	ui->scrMain_tileview = lv_tileview_create(ui->scrMain);
	ui->scrMain_tileview_tileMain = lv_tileview_add_tile(ui->scrMain_tileview, 0, 0, LV_DIR_RIGHT);
	ui->scrMain_tileview_tileWeather = lv_tileview_add_tile(ui->scrMain_tileview, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->scrMain_tileview_tileSettings = lv_tileview_add_tile(ui->scrMain_tileview, 2, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->scrMain_tileview_tileMenu = lv_tileview_add_tile(ui->scrMain_tileview, 3, 0, LV_DIR_LEFT);
	lv_obj_set_pos(ui->scrMain_tileview, 0, 0);
	lv_obj_set_size(ui->scrMain_tileview, 240, 320);
	lv_obj_set_scrollbar_mode(ui->scrMain_tileview, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrMain_tileview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrMain_tileview, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain_tileview, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain_tileview, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_tileview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_tileview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrMain_tileview, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrMain_tileview, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain_tileview, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain_tileview, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_tileview, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



	//Write codes scrMain_labelTime
	ui->scrMain_labelTime = lv_label_create(ui->scrMain_tileview_tileMain);
	lv_label_set_text(ui->scrMain_labelTime, "08:08");
	lv_label_set_long_mode(ui->scrMain_labelTime, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_labelTime, 6, 9);
	lv_obj_set_size(ui->scrMain_labelTime, 193, 59);

	//Write style for scrMain_labelTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_labelTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelTime, &lv_font_montserratMedium_63, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_labelTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_labelTime, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_labelTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_labelTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_labelDate
	ui->scrMain_labelDate = lv_label_create(ui->scrMain_tileview_tileMain);
	lv_label_set_text(ui->scrMain_labelDate, "09/12");
	lv_label_set_long_mode(ui->scrMain_labelDate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_labelDate, 0, 69);
	lv_obj_set_size(ui->scrMain_labelDate, 157, 60);

	//Write style for scrMain_labelDate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_labelDate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelDate, &lv_font_montserratMedium_48, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_labelDate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_labelDate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_labelDate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_chartHeart
	ui->scrMain_chartHeart = lv_chart_create(ui->scrMain_tileview_tileMain);
	lv_chart_set_type(ui->scrMain_chartHeart, LV_CHART_TYPE_LINE);
	lv_chart_set_div_line_count(ui->scrMain_chartHeart, 7, 7);
	lv_chart_set_point_count(ui->scrMain_chartHeart, 5);
	lv_chart_set_range(ui->scrMain_chartHeart, LV_CHART_AXIS_PRIMARY_Y, 0, 300);
	lv_chart_set_range(ui->scrMain_chartHeart, LV_CHART_AXIS_SECONDARY_Y, 0, 300);
	lv_chart_set_zoom_x(ui->scrMain_chartHeart, 256);
	lv_chart_set_zoom_y(ui->scrMain_chartHeart, 256);
	lv_obj_set_pos(ui->scrMain_chartHeart, 21, 180);
	lv_obj_set_size(ui->scrMain_chartHeart, 201, 124);
	lv_obj_set_scrollbar_mode(ui->scrMain_chartHeart, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrMain_chartHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrMain_chartHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrMain_chartHeart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrMain_chartHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrMain_chartHeart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrMain_chartHeart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_chartHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->scrMain_chartHeart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->scrMain_chartHeart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->scrMain_chartHeart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_chartHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrMain_chartHeart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->scrMain_chartHeart, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_chartHeart, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_chartHeart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->scrMain_chartHeart, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->scrMain_chartHeart, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->scrMain_chartHeart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write codes scrMain_textprogressBattery
	ui->scrMain_textprogressBattery = lv_textprogress_create(ui->scrMain_tileview_tileMain);
	lv_textprogress_set_range_value(ui->scrMain_textprogressBattery, 0, 100, 0, 0);
	lv_textprogress_set_decimal(ui->scrMain_textprogressBattery, 2);
	lv_textprogress_set_value(ui->scrMain_textprogressBattery, 80);
	lv_obj_set_pos(ui->scrMain_textprogressBattery, 36, 118);
	lv_obj_set_size(ui->scrMain_textprogressBattery, 81, 32);

	//Write style for scrMain_textprogressBattery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->scrMain_textprogressBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_textprogressBattery, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_textprogressBattery, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_textprogressBattery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_textprogressBattery, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_textprogressBattery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_textprogressBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_textprogressBattery, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_textprogressBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_textprogressBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_textprogressBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_img_2
	ui->scrMain_img_2 = lv_img_create(ui->scrMain_tileview_tileMain);
	lv_obj_add_flag(ui->scrMain_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrMain_img_2, &_Lightning_alpha_18x18);
	lv_img_set_pivot(ui->scrMain_img_2, 50,50);
	lv_img_set_angle(ui->scrMain_img_2, 0);
	lv_obj_set_pos(ui->scrMain_img_2, 17, 124);
	lv_obj_set_size(ui->scrMain_img_2, 18, 18);

	//Write style for scrMain_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrMain_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrMain_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrMain_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes scrMain_cont_1
	ui->scrMain_cont_1 = lv_obj_create(ui->scrMain_tileview_tileWeather);
	lv_obj_set_pos(ui->scrMain_cont_1, 14, 14);
	lv_obj_set_size(ui->scrMain_cont_1, 214, 100);
	lv_obj_set_scrollbar_mode(ui->scrMain_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrMain_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrMain_cont_1, 161, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrMain_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrMain_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_cont_1, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_cont_1, 213, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain_cont_1, lv_color_hex(0x191919), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_tableWeatherInfo
	ui->scrMain_tableWeatherInfo = lv_table_create(ui->scrMain_tileview_tileWeather);
	lv_table_set_col_cnt(ui->scrMain_tableWeatherInfo,2);
	lv_table_set_row_cnt(ui->scrMain_tableWeatherInfo,4);
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,0,0,"Name");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,1,0,"Apple");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,2,0,"Banana");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,3,0,"Citron");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,0,1,"Price");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,1,1,"$1");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,2,1,"$2");
	lv_table_set_cell_value(ui->scrMain_tableWeatherInfo,3,1,"$3");
	lv_obj_set_pos(ui->scrMain_tableWeatherInfo, 14, 160);
	lv_obj_set_scrollbar_mode(ui->scrMain_tableWeatherInfo, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrMain_tableWeatherInfo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain_tableWeatherInfo, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrMain_tableWeatherInfo, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrMain_tableWeatherInfo, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrMain_tableWeatherInfo, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0x393c41), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_tableWeatherInfo, &lv_font_montserratMedium_12, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_tableWeatherInfo, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_tableWeatherInfo, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrMain_tableWeatherInfo, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0xd5dee6), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrMain_tableWeatherInfo, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write codes scrMain_imageWeather
	ui->scrMain_imageWeather = lv_img_create(ui->scrMain_tileview_tileWeather);
	lv_obj_add_flag(ui->scrMain_imageWeather, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrMain_imageWeather, &_weather_alpha_50x50);
	lv_img_set_pivot(ui->scrMain_imageWeather, 50,50);
	lv_img_set_angle(ui->scrMain_imageWeather, 0);
	lv_obj_set_pos(ui->scrMain_imageWeather, 148, 38);
	lv_obj_set_size(ui->scrMain_imageWeather, 50, 50);

	//Write style for scrMain_imageWeather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrMain_imageWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrMain_imageWeather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_imageWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrMain_imageWeather, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_labelSubWeather
	ui->scrMain_labelSubWeather = lv_label_create(ui->scrMain_tileview_tileWeather);
	lv_label_set_text(ui->scrMain_labelSubWeather, "32°/26°");
	lv_label_set_long_mode(ui->scrMain_labelSubWeather, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_labelSubWeather, 22, 72);
	lv_obj_set_size(ui->scrMain_labelSubWeather, 100, 32);

	//Write style for scrMain_labelSubWeather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_labelSubWeather, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelSubWeather, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_labelSubWeather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_labelSubWeather, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_labelSubWeather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_labelWeather
	ui->scrMain_labelWeather = lv_label_create(ui->scrMain_tileview_tileWeather);
	lv_label_set_text(ui->scrMain_labelWeather, "29°");
	lv_label_set_long_mode(ui->scrMain_labelWeather, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_labelWeather, 15, 29);
	lv_obj_set_size(ui->scrMain_labelWeather, 100, 32);

	//Write style for scrMain_labelWeather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_labelWeather, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelWeather, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_labelWeather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_labelWeather, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_labelWeather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_labelWeather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrMain_label_8
	ui->scrMain_label_8 = lv_label_create(ui->scrMain_tileview_tileWeather);
	lv_label_set_text(ui->scrMain_label_8, "15-day forecast");
	lv_label_set_long_mode(ui->scrMain_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_label_8, 10, 141);
	lv_obj_set_size(ui->scrMain_label_8, 152, 31);

	//Write style for scrMain_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_label_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrMain_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);





	//The custom code of scrMain.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrMain);

	//Init events for screen.
	events_init_scrMain(ui);
}

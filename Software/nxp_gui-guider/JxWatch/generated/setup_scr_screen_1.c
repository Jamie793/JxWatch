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



void setup_scr_screen_1(lv_ui *ui)
{
	//Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_1, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_8
	ui->screen_1_img_8 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_8, &_time_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_8, 50,50);
	lv_img_set_angle(ui->screen_1_img_8, 0);
	lv_obj_set_pos(ui->screen_1_img_8, 395, 261);
	lv_obj_set_size(ui->screen_1_img_8, 30, 30);

	//Write style for screen_1_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_7
	ui->screen_1_img_7 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_7, &_timer_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_7, 50,50);
	lv_img_set_angle(ui->screen_1_img_7, 0);
	lv_obj_set_pos(ui->screen_1_img_7, 410, 212);
	lv_obj_set_size(ui->screen_1_img_7, 30, 30);

	//Write style for screen_1_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_6
	ui->screen_1_img_6 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_6, &_weather_qing_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_6, 50,50);
	lv_img_set_angle(ui->screen_1_img_6, 0);
	lv_obj_set_pos(ui->screen_1_img_6, 525, 179);
	lv_obj_set_size(ui->screen_1_img_6, 30, 30);

	//Write style for screen_1_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_5
	ui->screen_1_img_5 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_5, &_Bed_alpha_40x40);
	lv_img_set_pivot(ui->screen_1_img_5, 50,50);
	lv_img_set_angle(ui->screen_1_img_5, 0);
	lv_obj_set_pos(ui->screen_1_img_5, 456, 101);
	lv_obj_set_size(ui->screen_1_img_5, 40, 40);

	//Write style for screen_1_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_4
	ui->screen_1_img_4 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_4, &_calculator_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_4, 50,50);
	lv_img_set_angle(ui->screen_1_img_4, 0);
	lv_obj_set_pos(ui->screen_1_img_4, 380, 55);
	lv_obj_set_size(ui->screen_1_img_4, 30, 30);

	//Write style for screen_1_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_3
	ui->screen_1_img_3 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_3, &_alarm_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_3, 50,50);
	lv_img_set_angle(ui->screen_1_img_3, 0);
	lv_obj_set_pos(ui->screen_1_img_3, 304, 55);
	lv_obj_set_size(ui->screen_1_img_3, 30, 30);

	//Write style for screen_1_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_2
	ui->screen_1_img_2 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_2, &_heart_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_2, 50,50);
	lv_img_set_angle(ui->screen_1_img_2, 0);
	lv_obj_set_pos(ui->screen_1_img_2, 291, 240);
	lv_obj_set_size(ui->screen_1_img_2, 30, 30);

	//Write style for screen_1_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_1
	ui->screen_1_img_1 = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_1, &_calender_alpha_30x30);
	lv_img_set_pivot(ui->screen_1_img_1, 50,50);
	lv_img_set_angle(ui->screen_1_img_1, 0);
	lv_obj_set_pos(ui->screen_1_img_1, 317, 141);
	lv_obj_set_size(ui->screen_1_img_1, 30, 30);

	//Write style for screen_1_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_1_img_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_1_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_label_1
	ui->screen_1_label_1 = lv_label_create(ui->screen_1);
	lv_label_set_text(ui->screen_1_label_1, "我试试");
	lv_label_set_long_mode(ui->screen_1_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_1_label_1, 558, -99);
	lv_obj_set_size(ui->screen_1_label_1, 132, 76);

	//Write style for screen_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_label_1, &lv_font_huawenkaiti_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_1_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_ddlist_1
	ui->screen_1_ddlist_1 = lv_dropdown_create(ui->screen_1);
	lv_dropdown_set_options(ui->screen_1_ddlist_1, "2017年\n2015\n2016");
	lv_obj_set_pos(ui->screen_1_ddlist_1, 0, 0);
	lv_obj_set_size(ui->screen_1_ddlist_1, 77, 36);

	//Write style for screen_1_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_1_ddlist_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_ddlist_1, &lv_font_huawenkaiti_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_ddlist_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ddlist_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_1_ddlist_1_extra_list_selected_checked
	static lv_style_t style_screen_1_ddlist_1_extra_list_selected_checked;
	ui_init_style(&style_screen_1_ddlist_1_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_1_ddlist_1_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_1_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_1_ddlist_1_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_1_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_1_ddlist_1_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_1_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_1_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_1), &style_screen_1_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_1_ddlist_1_extra_list_main_default
	static lv_style_t style_screen_1_ddlist_1_extra_list_main_default;
	ui_init_style(&style_screen_1_ddlist_1_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_1_ddlist_1_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_1_ddlist_1_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_1_ddlist_1_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_1_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_1_ddlist_1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_1_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_1_ddlist_1_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_1_ddlist_1_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_1_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_1_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_1_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_1), &style_screen_1_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_1_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_screen_1_ddlist_1_extra_list_scrollbar_default;
	ui_init_style(&style_screen_1_ddlist_1_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_1_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_1_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_screen_1_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_1), &style_screen_1_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_1_ddlist_2
	ui->screen_1_ddlist_2 = lv_dropdown_create(ui->screen_1);
	lv_dropdown_set_options(ui->screen_1_ddlist_2, "1月\nlist2\nlist3");
	lv_obj_set_pos(ui->screen_1_ddlist_2, 83, 111);
	lv_obj_set_size(ui->screen_1_ddlist_2, 60, 30);

	//Write style for screen_1_ddlist_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_1_ddlist_2, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_ddlist_2, &lv_font_huawenkaiti_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_ddlist_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_ddlist_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_ddlist_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_ddlist_2, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_ddlist_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_ddlist_2, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_ddlist_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_ddlist_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ddlist_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_ddlist_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ddlist_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_ddlist_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_ddlist_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_1_ddlist_2_extra_list_selected_checked
	static lv_style_t style_screen_1_ddlist_2_extra_list_selected_checked;
	ui_init_style(&style_screen_1_ddlist_2_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_1_ddlist_2_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_1_ddlist_2_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_1_ddlist_2_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_1_ddlist_2_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_1_ddlist_2_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_2_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_2_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_1_ddlist_2_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_2), &style_screen_1_ddlist_2_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_1_ddlist_2_extra_list_main_default
	static lv_style_t style_screen_1_ddlist_2_extra_list_main_default;
	ui_init_style(&style_screen_1_ddlist_2_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_1_ddlist_2_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_1_ddlist_2_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_1_ddlist_2_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_1_ddlist_2_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_1_ddlist_2_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_1_ddlist_2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_1_ddlist_2_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_1_ddlist_2_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_1_ddlist_2_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_2_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_2_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_1_ddlist_2_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_2), &style_screen_1_ddlist_2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_1_ddlist_2_extra_list_scrollbar_default
	static lv_style_t style_screen_1_ddlist_2_extra_list_scrollbar_default;
	ui_init_style(&style_screen_1_ddlist_2_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_1_ddlist_2_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_2_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_2_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_screen_1_ddlist_2_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_2), &style_screen_1_ddlist_2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_1_label_2
	ui->screen_1_label_2 = lv_label_create(ui->screen_1);
	lv_label_set_text(ui->screen_1_label_2, "10:14");
	lv_label_set_long_mode(ui->screen_1_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_1_label_2, 135, 0);
	lv_obj_set_size(ui->screen_1_label_2, 100, 32);

	//Write style for screen_1_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_label_2, &lv_font_huawenkaiti_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_1_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_label_2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_label_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_1.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_1);

}

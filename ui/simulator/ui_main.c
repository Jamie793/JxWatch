/**
 * @file ui_main.c
 * @author Jamiexu (doxm@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ui_main.h"
#include "ui.h"
#include "anim.h"
#include "ui_main_menu.h"
#include "ui_main_weather.h"

LV_IMG_DECLARE(_tianqi_alpha_25x25);
LV_IMG_DECLARE(_Heart_rate_alpha_25x25);
LV_IMG_DECLARE(_BloodOxygen_alpha_25x25);
LV_IMG_DECLARE(_steps1_alpha_25x25);
LV_IMG_DECLARE(_Lightning_alpha_25x25);


lv_ui_page_t lv_ui_page_main = {
	.id = LV_PAGE_MAIN,
	.page = NULL,
	.ui_setup_cb = ui_setup_cb,
	.ui_destory_cb = ui_destory_cb,
	.event_setup_cb = event_setup_cb
};

LV_IMG_DECLARE(_Lightning_alpha_18x18)

extern void ui_main_menu_load(lv_obj_t *tile);

static void bar_event_cb(lv_event_t *e){
	lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    if(dsc->part != LV_PART_INDICATOR) return;

    lv_obj_t * obj = lv_event_get_target(e);

    lv_draw_label_dsc_t label_dsc;
    lv_draw_label_dsc_init(&label_dsc);
    label_dsc.font = &lv_font_montserrat_12;

    char buf[4];
    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_bar_get_value(obj));

    lv_point_t txt_size;
    lv_txt_get_size(&txt_size, buf, label_dsc.font, label_dsc.letter_space, label_dsc.line_space, LV_COORD_MAX,
                    label_dsc.flag);

    lv_area_t txt_area;
    /*If the indicator is long enough put the text inside on the right*/
    if(lv_area_get_width(dsc->draw_area) > txt_size.x + 20) {
        txt_area.x2 = dsc->draw_area->x2 - 5;
        txt_area.x1 = txt_area.x2 - txt_size.x + 1;
        label_dsc.color = lv_color_white();
    }
    /*If the indicator is still short put the text out of it on the right*/
    else {
        txt_area.x1 = dsc->draw_area->x2 + 5;
        txt_area.x2 = txt_area.x1 + txt_size.x - 1;
        label_dsc.color = lv_color_black();
    }

    txt_area.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - txt_size.y) / 2;
    txt_area.y2 = txt_area.y1 + txt_size.y - 1;

    lv_draw_label(dsc->draw_ctx, &label_dsc, &txt_area, buf, NULL);
}

static void ui_setup_cb(void)
{
	lv_obj_t *page;
	lv_ui_page_main.page = lv_obj_create(NULL);
	page = lv_ui_page_main.page;

	lv_obj_set_size(page, MY_DISP_HOR_RES, MY_DISP_VER_RES);
	lv_obj_set_scrollbar_mode(page, LV_SCROLLBAR_MODE_OFF);

	lv_obj_set_style_bg_color(page, lv_color_hex(0x000000), LV_PART_MAIN);
	lv_obj_set_style_bg_opa(page, LV_OPA_100, LV_PART_SCROLLBAR);
	

	lv_obj_t *tileview = lv_tileview_create(page);
	lv_obj_t *tileview_settings = lv_tileview_add_tile(tileview, 0, 0, LV_DIR_RIGHT);
	lv_obj_t *tileview_main = lv_tileview_add_tile(tileview, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT | LV_DIR_BOTTOM);
	lv_obj_t *tileview_weather = lv_tileview_add_tile(tileview, 2, 0, LV_DIR_LEFT);
	lv_obj_t *tileview_menu = lv_tileview_add_tile(tileview, 1, 1, LV_DIR_TOP);
	lv_obj_set_tile_id(tileview, 1, 0, LV_ANIM_OFF);
	lv_obj_set_pos(tileview, 0, 0);
	lv_obj_set_size(tileview, 240, 320);
	lv_obj_set_scrollbar_mode(tileview, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_scrollbar_mode(tileview_main, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_scrollbar_mode(tileview_weather, LV_SCROLLBAR_MODE_OFF);


	lv_obj_set_style_radius(tileview_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(tileview_main, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(tileview_main, lv_color_hex(0x000000), LV_PART_MAIN);
	lv_obj_set_style_bg_grad_dir(tileview_main, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);


	lv_obj_set_style_radius(tileview, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(tileview, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(tileview, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(tileview, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);


	lv_obj_t *time = lv_label_create(tileview_main);
	lv_label_set_text(time, "08:08");
	lv_label_set_long_mode(time, LV_LABEL_LONG_WRAP);
	lv_obj_set_size(time, 200, 60);
	lv_obj_align_to(time, tileview_main, LV_ALIGN_TOP_MID, 0, 10);
	// lv_obj_center(time);


	lv_obj_set_style_text_align(time, LV_ALIGN_CENTER, LV_PART_MAIN);
	lv_obj_set_style_border_width(time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(time, &lv_font_montserratMedium_63, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(time, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	
	lv_obj_t *date = lv_label_create(tileview_main);
	lv_label_set_text(date, "Fri. 10 Dec.");
	lv_label_set_long_mode(date, LV_LABEL_LONG_WRAP);
	lv_obj_set_size(date, 160, 60);
	lv_obj_align_to(date, time, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

	lv_obj_set_style_text_align(date, LV_ALIGN_CENTER, LV_PART_MAIN);
	lv_obj_set_style_border_width(date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(date, lv_color_hex3(0xEEE), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(date, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(date, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);


	lv_obj_t *weather = lv_label_create(tileview_main);
	lv_label_set_text(weather, "Shenzhen Longgang. 26°");
	lv_label_set_long_mode(weather, LV_LABEL_LONG_SCROLL_CIRCULAR);
	lv_obj_set_size(weather, 160, 60);
	lv_obj_align_to(weather, date, LV_ALIGN_OUT_BOTTOM_MID, 0, -30);

	lv_obj_set_style_text_align(weather, LV_ALIGN_CENTER, LV_PART_MAIN);
	lv_obj_set_style_text_color(weather, lv_color_hex3(0xEEE), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(weather, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(weather, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(weather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);



	lv_obj_t *img1 = lv_img_create(tileview_main);
	lv_img_set_src(img1, &_BloodOxygen_alpha_25x25);

	lv_obj_align_to(img1, weather, LV_ALIGN_OUT_BOTTOM_MID, -80, -30);

	lv_obj_set_style_text_color(img1, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);
	lv_obj_set_style_img_recolor(img1, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);
	lv_obj_set_style_img_recolor_opa(img1, LV_OPA_100, LV_PART_MAIN);



	lv_obj_t *blood = lv_bar_create(tileview_main);
	lv_bar_set_range(blood, 0, 100);
	lv_bar_set_value(blood, 90, LV_ANIM_ON);

	lv_obj_set_width(blood, LV_PCT(60));
	lv_obj_clear_flag(blood, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align_to(blood, img1, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
	lv_obj_add_event_cb(blood, bar_event_cb, LV_EVENT_DRAW_PART_END, NULL);

	lv_obj_set_style_bg_color(blood, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);


	lv_obj_t *img2 = lv_img_create(tileview_main);
	lv_img_set_src(img2, &_Lightning_alpha_25x25);

	lv_obj_align_to(img2, img1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);

	lv_obj_set_style_text_color(img2, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);

	lv_obj_t *battery = lv_bar_create(tileview_main);
	lv_bar_set_range(battery, 0, 100);
	lv_bar_set_value(battery, 50, LV_ANIM_ON);

	lv_obj_set_width(battery, LV_PCT(60));
	lv_obj_clear_flag(battery, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align_to(battery, img2, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
	lv_obj_add_event_cb(battery, bar_event_cb, LV_EVENT_DRAW_PART_END, NULL);
	

	lv_obj_set_style_bg_color(battery, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);




	lv_obj_t *steps = lv_arc_create(tileview_main);
	lv_obj_set_size(steps, 60, 60);
	lv_obj_clear_flag(steps, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_remove_style(steps, NULL, LV_PART_KNOB);
	lv_obj_align_to(steps, img2, LV_ALIGN_OUT_BOTTOM_MID, 30, 30);

	lv_obj_set_style_arc_width(steps, 6, LV_PART_MAIN);
	lv_obj_set_style_arc_width(steps, 6, LV_PART_INDICATOR);
	lv_obj_set_style_arc_color(steps, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
	

	lv_obj_t *steps_label = lv_label_create(tileview_main);
	lv_label_set_text(steps_label, "50000");
	lv_obj_align_to(steps_label, steps, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(steps_label, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);

	
	lv_obj_t *img3 = lv_img_create(tileview_main);
	lv_img_set_src(img3, &_steps1_alpha_25x25);
	lv_obj_align_to(img3, steps_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);



	lv_obj_t *heart = lv_arc_create(tileview_main);
	lv_obj_set_size(heart, 60, 60);
	lv_obj_align_to(heart, img2, LV_ALIGN_OUT_BOTTOM_MID, 130, 30);
	lv_obj_clear_flag(heart, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_remove_style(heart, NULL, LV_PART_KNOB);

	lv_obj_set_style_arc_width(heart, 6, LV_PART_MAIN);
	lv_obj_set_style_arc_width(heart, 6, LV_PART_INDICATOR);
	lv_obj_set_style_arc_color(heart, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
	

	lv_obj_t *heart_label = lv_label_create(tileview_main);
	lv_label_set_text(heart_label, "165");
	lv_obj_align_to(heart_label, heart, LV_ALIGN_CENTER, 0, 0);

	lv_obj_set_style_text_color(heart_label, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);

	
	lv_obj_t *img4 = lv_img_create(tileview_main);
	lv_img_set_src(img4, &_Heart_rate_alpha_25x25);
	lv_obj_align_to(img4, heart_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);







	// Write codes chart
	// heart = lv_chart_create(tileview_main);
	// lv_chart_set_type(heart, LV_CHART_TYPE_LINE);
	// lv_chart_set_div_line_count(heart, 7, 7);
	// lv_chart_set_point_count(heart, 5);
	// lv_chart_set_range(heart, LV_CHART_AXIS_PRIMARY_Y, 0, 300);
	// lv_chart_set_range(heart, LV_CHART_AXIS_SECONDARY_Y, 0, 300);
	// lv_chart_set_zoom_x(heart, 256);
	// lv_chart_set_zoom_y(heart, 256);
	// lv_obj_set_size(heart, 201, 124);
	// lv_obj_set_scrollbar_mode(heart, LV_SCROLLBAR_MODE_OFF);

	// // Write style for chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	// lv_obj_set_style_bg_opa(heart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_border_width(heart, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_border_opa(heart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_border_color(heart, lv_color_hex(0xe8e8e8), LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_border_side(heart, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_radius(heart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_line_width(heart, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_line_color(heart, lv_color_hex(0xe8e8e8), LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_line_opa(heart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	// // Write style for chart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	// lv_obj_set_style_text_color(heart, lv_color_hex(0x151212), LV_PART_TICKS | LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(heart, &lv_font_montserratMedium_12, LV_PART_TICKS | LV_STATE_DEFAULT);
	// lv_obj_set_style_text_opa(heart, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
	// lv_obj_set_style_line_width(heart, 2, LV_PART_TICKS | LV_STATE_DEFAULT);
	// lv_obj_set_style_line_color(heart, lv_color_hex(0xe8e8e8), LV_PART_TICKS | LV_STATE_DEFAULT);
	// lv_obj_set_style_line_opa(heart, 255, LV_PART_TICKS | LV_STATE_DEFAULT);

	// // Write codes battery
	// battery = lv_label_create(tileview_main);
	// lv_label_set_text(battery, "80%");
	// lv_obj_set_pos(battery, 36, 125);
	// lv_obj_set_size(battery, 81, 32);

	// // Write style for battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	// lv_obj_set_style_text_color(battery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_text_font(battery, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

	// // Write codes scrMain_img_2
	// scrMain_img_2 = lv_img_create(tileview_main);
	// lv_obj_add_flag(scrMain_img_2, LV_OBJ_FLAG_CLICKABLE);
	// lv_img_set_src(scrMain_img_2, &_Lightning_alpha_18x18);
	// lv_img_set_pivot(scrMain_img_2, 50, 50);
	// lv_img_set_angle(scrMain_img_2, 0);
	// lv_obj_set_pos(scrMain_img_2, 17, 127);
	// lv_obj_set_size(scrMain_img_2, 18, 18);

	// // Write style for scrMain_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	// lv_obj_set_style_img_recolor_opa(scrMain_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_img_opa(scrMain_img_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_radius(scrMain_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	// lv_obj_set_style_clip_corner(scrMain_img_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_t *scrMain_Notif = lv_obj_create(page);
	lv_obj_set_pos(scrMain_Notif, 0, -MY_DISP_VER_RES);
	lv_obj_set_size(scrMain_Notif, MY_DISP_HOR_RES, MY_DISP_VER_RES);
	lv_obj_set_style_border_opa(scrMain_Notif, LV_OPA_0, LV_PART_MAIN);

	lv_obj_set_style_bg_color(scrMain_Notif, lv_color_hex(0x000000), LV_PART_MAIN);

	lv_obj_t *scrMain_Notif_tips = lv_label_create(scrMain_Notif);
	lv_label_set_text(scrMain_Notif_tips, "Nothing");
	lv_obj_set_pos(scrMain_Notif_tips, 0, 0);
	lv_obj_center(scrMain_Notif_tips);

	lv_obj_set_style_text_font(scrMain_Notif_tips, &lv_font_montserrat_28, LV_PART_MAIN);
	lv_obj_set_style_text_color(scrMain_Notif_tips, lv_color_hex(0xffffff), LV_PART_MAIN);

	ui_main_menu_load(tileview_menu);

}

static void my_gesture_event_cb(lv_event_t *e)
{

	// lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
	// lv_obj_t *scr = lv_event_get_user_data(e);
	// lv_anim_t anim;

	// lv_anim_init(&anim);
	// switch (dir)
	// {
	// case LV_DIR_LEFT:
	// case LV_DIR_RIGHT:
	// 	break;
	// case LV_DIR_TOP:
	// 	if (lv_obj_get_y(scr) == 0)
	// 	{
	// 		lv_anim_set_var(&anim, scr);
	// 		lv_anim_set_values(&anim, lv_obj_get_y(scr), -MY_DISP_VER_RES);
	// 		lv_anim_set_time(&anim, 500);
	// 		lv_anim_set_exec_cb(&anim, anim_set_y_cb);
	// 		lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);
	// 		lv_anim_start(&anim);
	// 	}
	// 	break;
	// case LV_DIR_BOTTOM:
	// 	if (lv_obj_get_y(scr) == -MY_DISP_VER_RES)
	// 	{
	// 		lv_anim_init(&anim);
	// 		lv_anim_set_var(&anim, scr);
	// 		lv_anim_set_values(&anim, lv_obj_get_y(scr), 0);
	// 		lv_anim_set_time(&anim, 100);
	// 		lv_anim_set_exec_cb(&anim, anim_set_y_cb);
	// 		lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);
	// 		lv_anim_start(&anim);
	// 	}
	// 	break;
	// }
	
}

static void ui_destory_cb(void)
{
    lv_obj_del(lv_ui_page_main.page);
}

static void event_setup_cb(void)
{
	// lv_obj_add_event_cb(ui_main.scr_main, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_main.scrMain_Notif);
	// lv_obj_add_event_cb(ui_main.scrMain_Notif, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_main.scrMain_Notif);
	// lv_obj_add_event_cb(ui_main.scrMain_Notif, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_main.scrMain_Notif);
}

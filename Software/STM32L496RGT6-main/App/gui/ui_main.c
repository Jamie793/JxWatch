#include "ui_main.h"
#include "lv_conf.h"
#include "ui_main_menu.h"
#include "ui_main_weather.h"

lv_ui_main_t ui_main;

LV_IMG_DECLARE(_Lightning_alpha_18x18)

static void ui_init(lv_ui_main_t *ui)
{
	// Write codes scrMain
	ui->scrMain = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrMain, 240, 320);
	lv_obj_set_scrollbar_mode(ui->scrMain, LV_SCROLLBAR_MODE_OFF);

	// Write style for scrMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes scrMain_tileview
	ui->scrMain_tileview = lv_tileview_create(ui->scrMain);
	ui->scrMain_tileview_tileSettings = lv_tileview_add_tile(ui->scrMain_tileview, 0, 0, LV_DIR_RIGHT);
	ui->scrMain_tileview_tileMain = lv_tileview_add_tile(ui->scrMain_tileview, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT | LV_DIR_BOTTOM);
	ui->scrMain_tileview_tileWeather = lv_tileview_add_tile(ui->scrMain_tileview, 2, 0, LV_DIR_LEFT);
	ui->scrMain_tileview_tileMenu = lv_tileview_add_tile(ui->scrMain_tileview, 1, 1, LV_DIR_TOP);
	lv_obj_set_pos(ui->scrMain_tileview, 0, 0);
	lv_obj_set_size(ui->scrMain_tileview, 240, 320);
	lv_obj_set_scrollbar_mode(ui->scrMain_tileview, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_tile_id(ui->scrMain_tileview, 1, 0, LV_ANIM_OFF);

	// Write style for scrMain_tileview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->scrMain_tileview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_tileview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain_tileview, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain_tileview, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for scrMain_tileview, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->scrMain_tileview, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_tileview, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrMain_tileview, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrMain_tileview, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

	// Write codes scrMain_labelTime
	ui->scrMain_labelTime = lv_label_create(ui->scrMain_tileview_tileMain);
	lv_label_set_text(ui->scrMain_labelTime, "08:08");
	lv_label_set_long_mode(ui->scrMain_labelTime, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_labelTime, 6, 9);
	lv_obj_set_size(ui->scrMain_labelTime, 193, 59);

	// Write style for scrMain_labelTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_labelTime, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelTime, &lv_font_montserratMedium_63, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_labelTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_labelTime, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_labelTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_labelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes scrMain_labelDate
	ui->scrMain_labelDate = lv_label_create(ui->scrMain_tileview_tileMain);
	lv_label_set_text(ui->scrMain_labelDate, "09/12");
	lv_label_set_long_mode(ui->scrMain_labelDate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrMain_labelDate, 0, 69);
	lv_obj_set_size(ui->scrMain_labelDate, 157, 60);

	// Write style for scrMain_labelDate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrMain_labelDate, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelDate, &lv_font_montserratMedium_48, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_labelDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrMain_labelDate, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrMain_labelDate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrMain_labelDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes scrMain_chartHeart
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

	// Write style for scrMain_chartHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrMain_chartHeart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrMain_chartHeart, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrMain_chartHeart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrMain_chartHeart, lv_color_hex(0xe8e8e8), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrMain_chartHeart, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_chartHeart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->scrMain_chartHeart, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->scrMain_chartHeart, lv_color_hex(0xe8e8e8), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->scrMain_chartHeart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for scrMain_chartHeart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->scrMain_chartHeart, lv_color_hex(0x151212), LV_PART_TICKS | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_chartHeart, &lv_font_montserratMedium_12, LV_PART_TICKS | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrMain_chartHeart, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->scrMain_chartHeart, 2, LV_PART_TICKS | LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->scrMain_chartHeart, lv_color_hex(0xe8e8e8), LV_PART_TICKS | LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->scrMain_chartHeart, 255, LV_PART_TICKS | LV_STATE_DEFAULT);

	// Write codes scrMain_labelBattery
	ui->scrMain_labelBattery = lv_label_create(ui->scrMain_tileview_tileMain);
	lv_label_set_text(ui->scrMain_labelBattery, "80%");
	lv_obj_set_pos(ui->scrMain_labelBattery, 36, 125);
	lv_obj_set_size(ui->scrMain_labelBattery, 81, 32);

	// Write style for scrMain_labelBattery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->scrMain_labelBattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrMain_labelBattery, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes scrMain_img_2
	ui->scrMain_img_2 = lv_img_create(ui->scrMain_tileview_tileMain);
	lv_obj_add_flag(ui->scrMain_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrMain_img_2, &_Lightning_alpha_18x18);
	lv_img_set_pivot(ui->scrMain_img_2, 50, 50);
	lv_img_set_angle(ui->scrMain_img_2, 0);
	lv_obj_set_pos(ui->scrMain_img_2, 17, 127);
	lv_obj_set_size(ui->scrMain_img_2, 18, 18);

	// Write style for scrMain_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrMain_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrMain_img_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrMain_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrMain_img_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui->scrMain_Notif = lv_obj_create(ui->scrMain);
	lv_obj_set_pos(ui->scrMain_Notif, 0, -MY_DISP_VER_RES);
	lv_obj_set_size(ui->scrMain_Notif, MY_DISP_HOR_RES, MY_DISP_VER_RES);
	lv_obj_set_style_border_opa(ui->scrMain_Notif, LV_OPA_0, LV_PART_MAIN);

	lv_obj_set_style_bg_color(ui->scrMain_Notif, lv_color_hex(0x000000), LV_PART_MAIN);

	ui->scrMain_Notif_tips = lv_label_create(ui->scrMain_Notif);
	lv_label_set_text(ui->scrMain_Notif_tips, "Nothing");
	lv_obj_set_pos(ui->scrMain_Notif_tips, 0, 0);
	lv_obj_center(ui->scrMain_Notif_tips);

	lv_obj_set_style_text_font(ui->scrMain_Notif_tips, &lv_font_montserrat_28, LV_PART_MAIN);
	lv_obj_set_style_text_color(ui->scrMain_Notif_tips, lv_color_hex(0xffffff), LV_PART_MAIN);
}

static void anim_y_cb(void *var, int32_t v)
{
	lv_obj_set_y(var, v);
}

lv_point_t touchXY;
static void my_gesture_event_cb(lv_event_t *e)
{

	lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
	lv_obj_t *scr = lv_event_get_user_data(e);
	lv_anim_t anim;

	lv_anim_init(&anim);
	switch (dir)
	{
	case LV_DIR_LEFT:
		break;
	case LV_DIR_RIGHT:
		break;
	case LV_DIR_TOP:
		if (lv_obj_get_y(scr) == 0)
		{
			lv_anim_set_var(&anim, scr);
			lv_anim_set_values(&anim, lv_obj_get_y(scr), -MY_DISP_VER_RES);
			lv_anim_set_time(&anim, 500);
			lv_anim_set_exec_cb(&anim, anim_y_cb);
			lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);
			lv_anim_start(&anim);
		}
		break;
	case LV_DIR_BOTTOM:
		if (lv_obj_get_y(scr) == -MY_DISP_VER_RES)
		{
			lv_anim_init(&anim);
			lv_anim_set_var(&anim, scr);
			lv_anim_set_values(&anim, lv_obj_get_y(scr), 0);
			lv_anim_set_time(&anim, 100);
			lv_anim_set_exec_cb(&anim, anim_y_cb);
			lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);
			lv_anim_start(&anim);
		}
		break;
	}
}

void ui_main_init(void)
{
	ui_init(&ui_main);
	ui_main_menu_init((lv_ui_main_t *)&ui_main);
	ui_main_weather_init((lv_ui_main_t *)&ui_main);
	lv_scr_load(ui_main.scrMain);
	lv_obj_add_event_cb(ui_main.scrMain, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_main.scrMain_Notif);
	lv_obj_add_event_cb(ui_main.scrMain_Notif, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_main.scrMain_Notif);
	lv_obj_add_event_cb(ui_main.scrMain_Notif, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_main.scrMain_Notif);
}
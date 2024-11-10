#include "ui_main.h"

lv_ui ui_main;

static void setup_scr_screen_main(lv_ui *ui)
{
    // Write codes screen_main
    ui->screen_main = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_main, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_main, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_tileview
    ui->screen_main_tileview = lv_tileview_create(ui->screen_main);
    ui->screen_main_tileview_tile = lv_tileview_add_tile(ui->screen_main_tileview, 0, 0, LV_DIR_RIGHT);
    ui->screen_main_tileview_tile_1 = lv_tileview_add_tile(ui->screen_main_tileview, 1, 0, LV_DIR_LEFT);
    lv_obj_set_pos(ui->screen_main_tileview, 0, 0);
    lv_obj_set_size(ui->screen_main_tileview, 240, 320);
    // lv_obj_set_scrollbar_mode(ui->screen_main_tileview, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_main_tileview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_tileview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_tileview, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_tileview, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_tileview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_tileview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for screen_main_tileview, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_tileview, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_tileview, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_tileview, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_tileview, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write codes screen_main_label_time
    ui->screen_main_label_time = lv_label_create(ui->screen_main_tileview_tile);
    lv_label_set_text(ui->screen_main_label_time, "08:08");
    lv_label_set_long_mode(ui->screen_main_label_time, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_time, 7, 10);
    lv_obj_set_size(ui->screen_main_label_time, 193, 59);

    // Write style for screen_main_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_time, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_time, &lv_font_Acme_Regular_68, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_time, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_label_date
    ui->screen_main_label_date = lv_label_create(ui->screen_main_tileview_tile);
    lv_label_set_text(ui->screen_main_label_date, "09/12");
    lv_label_set_long_mode(ui->screen_main_label_date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_date, 2, 75);
    lv_obj_set_size(ui->screen_main_label_date, 157, 60);

    // Write style for screen_main_label_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_date, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_date, &lv_font_Acme_Regular_48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_date, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_meter_battery
    ui->screen_main_meter_battery = lv_meter_create(ui->screen_main_tileview_tile);
    // add scale ui->screen_main_meter_battery_scale_0
    ui->screen_main_meter_battery_scale_0 = lv_meter_add_scale(ui->screen_main_meter_battery);
    lv_meter_set_scale_ticks(ui->screen_main_meter_battery, ui->screen_main_meter_battery_scale_0, 20, 3, 10, lv_color_hex(0xffffff));
    lv_meter_set_scale_range(ui->screen_main_meter_battery, ui->screen_main_meter_battery_scale_0, 0, 100, 180, 180);

    // add needle line for ui->screen_main_meter_battery_scale_0.
    ui->screen_main_meter_battery_scale_0_ndline_0 = lv_meter_add_needle_line(ui->screen_main_meter_battery, ui->screen_main_meter_battery_scale_0, 3, lv_color_hex(0xffffff), -15);
    lv_meter_set_indicator_value(ui->screen_main_meter_battery, ui->screen_main_meter_battery_scale_0_ndline_0, 95);
    lv_obj_set_pos(ui->screen_main_meter_battery, 11, 119);
    lv_obj_set_size(ui->screen_main_meter_battery, 100, 100);

    // Write style for screen_main_meter_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_meter_battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_meter_battery, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_meter_battery, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_meter_battery, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_main_meter_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_meter_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for screen_main_meter_battery, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_main_meter_battery, lv_color_hex(0xff0000), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_meter_battery, &lv_font_montserratMedium_12, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_meter_battery, 255, LV_PART_TICKS | LV_STATE_DEFAULT);

    // Write style for screen_main_meter_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_meter_battery, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_meter_battery, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_meter_battery, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write codes screen_main_chart_heart
    ui->screen_main_chart_heart = lv_chart_create(ui->screen_main_tileview_tile);
    lv_chart_set_type(ui->screen_main_chart_heart, LV_CHART_TYPE_BAR);
    lv_chart_set_div_line_count(ui->screen_main_chart_heart, 0, 0);
    lv_chart_set_point_count(ui->screen_main_chart_heart, 22);
    lv_chart_set_range(ui->screen_main_chart_heart, LV_CHART_AXIS_PRIMARY_Y, 0, 200);
    lv_chart_set_axis_tick(ui->screen_main_chart_heart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 3, false, 39);
    lv_chart_set_range(ui->screen_main_chart_heart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_axis_tick(ui->screen_main_chart_heart, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 4, false, 40);
    lv_chart_set_zoom_x(ui->screen_main_chart_heart, 256);
    lv_chart_set_zoom_y(ui->screen_main_chart_heart, 256);
    ui->screen_main_chart_heart_0 = lv_chart_add_series(ui->screen_main_chart_heart, lv_color_hex(0xffffff), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 1);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 20);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 30);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 40);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 50);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 60);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 70);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 80);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 90);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 100);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 110);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 100);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 90);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 80);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 70);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 60);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 50);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 40);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 30);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 20);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 0);
    lv_chart_set_next_value(ui->screen_main_chart_heart, ui->screen_main_chart_heart_0, 0);
#endif
    lv_obj_set_pos(ui->screen_main_chart_heart, 20, 232);
    lv_obj_set_size(ui->screen_main_chart_heart, 195, 79);
    lv_obj_set_scrollbar_mode(ui->screen_main_chart_heart, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_main_chart_heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_chart_heart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_chart_heart, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_chart_heart, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_main_chart_heart, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_main_chart_heart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_main_chart_heart, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_main_chart_heart, LV_BORDER_SIDE_FULL | LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_chart_heart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_main_chart_heart, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_main_chart_heart, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_main_chart_heart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_chart_heart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for screen_main_chart_heart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_main_chart_heart, lv_color_hex(0x151212), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_chart_heart, &lv_font_montserratMedium_12, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_chart_heart, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_main_chart_heart, 2, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_main_chart_heart, lv_color_hex(0xe8e8e8), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_main_chart_heart, 255, LV_PART_TICKS | LV_STATE_DEFAULT);

    // Write codes screen_main_label_info
    ui->screen_main_label_info = lv_label_create(ui->screen_main_tileview_tile);
    lv_label_set_text(ui->screen_main_label_info, "96Times/m  7mins ago");
    lv_label_set_long_mode(ui->screen_main_label_info, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_info, 22, 211);
    lv_obj_set_size(ui->screen_main_label_info, 161, 12);

    // Write style for screen_main_label_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_info, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_info, &lv_font_Acme_Regular_13, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_info, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_info, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_info, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_label_bluetooth
    ui->screen_main_label_bluetooth = lv_label_create(ui->screen_main_tileview_tile);
    lv_label_set_text(ui->screen_main_label_bluetooth, "BL\n");
    lv_label_set_long_mode(ui->screen_main_label_bluetooth, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_bluetooth, 111, 152);
    lv_obj_set_size(ui->screen_main_label_bluetooth, 30, 20);

    // Write style for screen_main_label_bluetooth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_bluetooth, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_main_label_bluetooth, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_main_label_bluetooth, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_main_label_bluetooth, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_bluetooth, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_bluetooth, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_bluetooth, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_bluetooth, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_bluetooth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_bluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_label_wifi
    ui->screen_main_label_wifi = lv_label_create(ui->screen_main_tileview_tile);
    lv_label_set_text(ui->screen_main_label_wifi, "W");
    lv_label_set_long_mode(ui->screen_main_label_wifi, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_wifi, 144, 152);
    lv_obj_set_size(ui->screen_main_label_wifi, 30, 20);

    // Write style for screen_main_label_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_wifi, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_main_label_wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_main_label_wifi, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_main_label_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_wifi, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_wifi, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_wifi, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_cont_1
    ui->screen_main_cont_1 = lv_obj_create(ui->screen_main_tileview_tile_1);
    lv_obj_set_pos(ui->screen_main_cont_1, 14, 14);
    lv_obj_set_size(ui->screen_main_cont_1, 214, 100);
    lv_obj_set_scrollbar_mode(ui->screen_main_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_main_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_main_cont_1, 161, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_main_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_main_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_cont_1, 17, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_cont_1, 213, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_cont_1, lv_color_hex(0x191919), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_list_1
    ui->screen_main_list_1 = lv_list_create(ui->screen_main_cont_1);
    ui->screen_main_list_1_item0 = lv_list_add_btn(ui->screen_main_list_1, &_weather_duoyun_alpha_20x20, "9/15____________33°/25°");
    ui->screen_main_list_1_item1 = lv_list_add_btn(ui->screen_main_list_1, &_weather_baoyu_alpha_20x20, "9/16____________30°/21°");
    ui->screen_main_list_1_item2 = lv_list_add_btn(ui->screen_main_list_1, &_weather_zhenyu_alpha_20x20, "9/17____________31°/23°");
    ui->screen_main_list_1_item3 = lv_list_add_btn(ui->screen_main_list_1, &_weather_yin_alpha_20x20, "9/18____________31°/22°");
    ui->screen_main_list_1_item4 = lv_list_add_btn(ui->screen_main_list_1, &_weather4_alpha_20x20, "9/19____________33°/23°");
    lv_obj_set_pos(ui->screen_main_list_1, 1, 145);
    lv_obj_set_size(ui->screen_main_list_1, 210, 147);
    lv_obj_set_scrollbar_mode(ui->screen_main_list_1, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for &style_screen_main_list_1_main_main_default
    static lv_style_t style_screen_main_list_1_main_main_default;
    ui_init_style(&style_screen_main_list_1_main_main_default);

    lv_style_set_pad_top(&style_screen_main_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_screen_main_list_1_main_main_default, 5);
    lv_style_set_pad_right(&style_screen_main_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_main_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_screen_main_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_screen_main_list_1_main_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_screen_main_list_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_main_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_screen_main_list_1_main_main_default, 0);
    lv_style_set_border_color(&style_screen_main_list_1_main_main_default, lv_color_hex(0x000000));
    lv_style_set_border_side(&style_screen_main_list_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_main_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_screen_main_list_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_main_list_1, &style_screen_main_list_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_screen_main_list_1_main_scrollbar_default
    static lv_style_t style_screen_main_list_1_main_scrollbar_default;
    ui_init_style(&style_screen_main_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_screen_main_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_main_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_main_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_main_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_main_list_1, &style_screen_main_list_1_main_scrollbar_default, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_screen_main_list_1_extra_btns_main_default
    static lv_style_t style_screen_main_list_1_extra_btns_main_default;
    ui_init_style(&style_screen_main_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_screen_main_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_screen_main_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_screen_main_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_main_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_screen_main_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_screen_main_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_main_list_1_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_main_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_screen_main_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_screen_main_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_main_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_main_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_main_list_1_item4, &style_screen_main_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_main_list_1_item3, &style_screen_main_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_main_list_1_item2, &style_screen_main_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_main_list_1_item1, &style_screen_main_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_main_list_1_item0, &style_screen_main_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_screen_main_list_1_extra_texts_main_default
    static lv_style_t style_screen_main_list_1_extra_texts_main_default;
    ui_init_style(&style_screen_main_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_screen_main_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_screen_main_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_screen_main_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_main_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_screen_main_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_screen_main_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_main_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_main_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_screen_main_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_screen_main_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_screen_main_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_screen_main_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_main_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

    // Write codes screen_main_img_1
    ui->screen_main_img_1 = lv_img_create(ui->screen_main_tileview_tile_1);
    lv_obj_add_flag(ui->screen_main_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_main_img_1, &_weather_alpha_50x50);
    lv_img_set_pivot(ui->screen_main_img_1, 50, 50);
    lv_img_set_angle(ui->screen_main_img_1, 0);
    lv_obj_set_pos(ui->screen_main_img_1, 148, 38);
    lv_obj_set_size(ui->screen_main_img_1, 50, 50);

    // Write style for screen_main_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_main_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_main_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_main_img_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_label_weather_sub
    ui->screen_main_label_weather_sub = lv_label_create(ui->screen_main_tileview_tile_1);
    lv_label_set_text(ui->screen_main_label_weather_sub, "32°/26°");
    lv_label_set_long_mode(ui->screen_main_label_weather_sub, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_weather_sub, 22, 72);
    lv_obj_set_size(ui->screen_main_label_weather_sub, 100, 32);

    // Write style for screen_main_label_weather_sub, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_weather_sub, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_weather_sub, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_weather_sub, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_weather_sub, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_weather_sub, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_weather_sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_label_weather_main
    ui->screen_main_label_weather_main = lv_label_create(ui->screen_main_tileview_tile_1);
    lv_label_set_text(ui->screen_main_label_weather_main, "29°");
    lv_label_set_long_mode(ui->screen_main_label_weather_main, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_weather_main, 15, 29);
    lv_obj_set_size(ui->screen_main_label_weather_main, 100, 32);

    // Write style for screen_main_label_weather_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_weather_main, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_weather_main, &lv_font_montserratMedium_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_weather_main, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_weather_main, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_weather_main, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_weather_main, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_label_8
    ui->screen_main_label_8 = lv_label_create(ui->screen_main_tileview_tile_1);
    lv_label_set_text(ui->screen_main_label_8, "15-day forecast");
    lv_label_set_long_mode(ui->screen_main_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_8, 10, 141);
    lv_obj_set_size(ui->screen_main_label_8, 152, 31);

    // Write style for screen_main_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_8, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_8, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of screen_main.

    // Update current screen layout.
    lv_obj_update_layout(ui->screen_main);

    // Init events for screen.
    //  events_init_screen_main(ui);
}

static void screen_main_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCROLL:
    {
        break;
    }
    default:
        break;
    }
}

void ui_main_init(void)
{
    setup_scr_screen_main(&ui_main);
    lv_scr_load(ui_main.screen_main);
    lv_obj_add_event_cb(ui_main.screen_main, screen_main_event_handler, LV_EVENT_ALL, ui_main.screen_main);
}
#include "ui_main_weather.h"

LV_IMG_DECLARE(_weather_alpha_50x50)

void ui_main_weather_init(lv_ui_main_t *ui)
{
    // Write codes scrMain_cont_1
    ui->scrMain_cont_1 = lv_obj_create(ui->scrMain_tileview_tileWeather);
    lv_obj_set_pos(ui->scrMain_cont_1, 14, 14);
    lv_obj_set_size(ui->scrMain_cont_1, 214, 100);
    lv_obj_set_scrollbar_mode(ui->scrMain_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for scrMain_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrMain_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrMain_cont_1, 161, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrMain_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrMain_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrMain_cont_1, 17, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrMain_cont_1, 213, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrMain_cont_1, lv_color_hex(0x191919), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrMain_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrMain_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrMain_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrMain_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrMain_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes scrMain_tableWeatherInfo
    ui->scrMain_tableWeatherInfo = lv_table_create(ui->scrMain_tileview_tileWeather);
    lv_table_set_col_cnt(ui->scrMain_tableWeatherInfo, 2);
    lv_table_set_row_cnt(ui->scrMain_tableWeatherInfo, 4);
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 0, 0, "Name");
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 1, 0, "Apple");
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 2, 0, "Banana");
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 3, 0, "Citron");

    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 0, 1, "Price");
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 1, 1, "$1");
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 2, 1, "$2");
    lv_table_set_cell_value(ui->scrMain_tableWeatherInfo, 3, 1, "$3");
    lv_obj_set_pos(ui->scrMain_tableWeatherInfo, 10, 165);
    lv_obj_set_size(ui->scrMain_tableWeatherInfo, 210, 200);
    lv_obj_set_scrollbar_mode(ui->scrMain_tableWeatherInfo, LV_SCROLLBAR_MODE_OFF);

    // Write style for scrMain_tableWeatherInfo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrMain_tableWeatherInfo, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrMain_tableWeatherInfo, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0xd5dee6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrMain_tableWeatherInfo, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrMain_tableWeatherInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for scrMain_tableWeatherInfo, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0x393c41), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrMain_tableWeatherInfo, &lv_font_montserratMedium_12, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrMain_tableWeatherInfo, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrMain_tableWeatherInfo, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrMain_tableWeatherInfo, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrMain_tableWeatherInfo, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrMain_tableWeatherInfo, lv_color_hex(0xd5dee6), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrMain_tableWeatherInfo, LV_BORDER_SIDE_FULL, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrMain_tableWeatherInfo, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);

    // Write codes scrMain_imageWeather
    ui->scrMain_imageWeather = lv_img_create(ui->scrMain_tileview_tileWeather);
    lv_obj_add_flag(ui->scrMain_imageWeather, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrMain_imageWeather, &_weather_alpha_50x50);
    lv_img_set_pivot(ui->scrMain_imageWeather, 50, 50);
    lv_img_set_angle(ui->scrMain_imageWeather, 0);
    lv_obj_set_pos(ui->scrMain_imageWeather, 148, 38);
    lv_obj_set_size(ui->scrMain_imageWeather, 50, 50);

    // Write style for scrMain_imageWeather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrMain_imageWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrMain_imageWeather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrMain_imageWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrMain_imageWeather, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes scrMain_labelSubWeather
    ui->scrMain_labelSubWeather = lv_label_create(ui->scrMain_tileview_tileWeather);
    lv_label_set_text(ui->scrMain_labelSubWeather, "32°/26°");
    lv_label_set_long_mode(ui->scrMain_labelSubWeather, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrMain_labelSubWeather, 22, 72);
    lv_obj_set_size(ui->scrMain_labelSubWeather, 100, 32);

    // Write style for scrMain_labelSubWeather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrMain_labelSubWeather, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrMain_labelSubWeather, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrMain_labelSubWeather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrMain_labelSubWeather, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrMain_labelSubWeather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrMain_labelSubWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes scrMain_labelWeather
    ui->scrMain_labelWeather = lv_label_create(ui->scrMain_tileview_tileWeather);
    lv_label_set_text(ui->scrMain_labelWeather, "29°");
    lv_label_set_long_mode(ui->scrMain_labelWeather, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrMain_labelWeather, 15, 29);
    lv_obj_set_size(ui->scrMain_labelWeather, 100, 32);

    // Write style for scrMain_labelWeather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrMain_labelWeather, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrMain_labelWeather, &lv_font_montserratMedium_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrMain_labelWeather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrMain_labelWeather, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrMain_labelWeather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrMain_labelWeather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes scrMain_label_8
    ui->scrMain_label_8 = lv_label_create(ui->scrMain_tileview_tileWeather);
    lv_label_set_text(ui->scrMain_label_8, "15-day forecast");
    lv_label_set_long_mode(ui->scrMain_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrMain_label_8, 10, 141);
    lv_obj_set_size(ui->scrMain_label_8, 152, 31);

    // Write style for scrMain_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrMain_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrMain_label_8, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrMain_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrMain_label_8, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrMain_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrMain_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

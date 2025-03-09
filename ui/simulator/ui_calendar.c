// /**
//  * @file ui_calendar.c
//  * @author Jamiexu (doxm@foxmail.com)
//  * @brief 
//  * @version 0.1
//  * @date 2024-11-12
//  * 
//  * @copyright Copyright (c) 2024
//  * 
//  */
// #include "ui_calendar.h"
// #include "anim.h"

// #define ROW_WIDTH 20
// #define COL_WIDTH 20

// #define ROW_DIV_WIDTH 20
// #define COL_DIW_HEIGHT 20

// #define COL_NUMS 7
// #define ROW_NUMS 5

// static lv_coord_t cols[COL_NUMS + 1] = {20, 20, 20, 20, 20, 20, 20, LV_GRID_TEMPLATE_LAST};
// static lv_coord_t rows[COL_NUMS + 1] = {20, 20, 20, 20, 20, 20, 20, LV_GRID_TEMPLATE_LAST};

// static lv_ui_calendar_t ui_calendar;
// static lv_ui_page_t ui_calendar_cb;

// static lv_calendar_date_t today = {
//     .year = 2024,
//     .month = 11,
//     .day = 12};

// lv_calendar_date_t highlightedDays[1] = {
//     {.year = 2024,
//      .month = 11,
//      .day = 12}};

// static void ui_setup_cb(lv_ui_calendar_t *ui)
// {
//     if (ui == NULL)
//         ui = &ui_calendar;

//     // Write codes scrCalendar
//     ui->scrCalendar = lv_obj_create(NULL);
//     lv_obj_set_size(ui->scrCalendar, 240, 320);
//     lv_obj_set_scrollbar_mode(ui->scrCalendar, LV_SCROLLBAR_MODE_OFF);
//     lv_obj_set_layout(ui->scrCalendar, LV_LAYOUT_GRID);
//     lv_obj_set_grid_dsc_array(ui->scrCalendar, cols, rows);

//     // Write style for scrCalendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
//     lv_obj_set_style_bg_opa(ui->scrCalendar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui->scrCalendar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_dir(ui->scrCalendar, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     ui->scrCalendar_calendar = widget_calendar_create(ui->scrCalendar);
// }

// static void ui_load_cb(void)
// {
//     lv_scr_load(ui_calendar.scrCalendar);
// }

// static void ui_destory_cb(void)
// {
//     lv_obj_del(ui_calendar.scrCalendar);
// }

// static void anim_ready_cb(lv_anim_t *a)
// {
//     ui_stack_pop();
//     ui_stack_top()->ui_load_cb();
//     ui_destory_cb();
// }

// static void my_gesture_event_cb(lv_event_t *e)
// {
//     lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
//     lv_obj_t *scr = lv_event_get_user_data(e);
//     lv_anim_t anim;

//     lv_anim_init(&anim);
//     switch (dir)
//     {
//     case LV_DIR_LEFT:
//     case LV_DIR_TOP:
//     case LV_DIR_BOTTOM:
//         break;
//     case LV_DIR_RIGHT:
//         lv_anim_set_var(&anim, scr);
//         lv_anim_set_values(&anim, lv_obj_get_x(scr), MY_DISP_HOR_RES + 10);
//         lv_anim_set_time(&anim, 100);
//         lv_anim_set_exec_cb(&anim, anim_set_x_cb);
//         lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);
//         lv_anim_set_ready_cb(&anim, anim_ready_cb);
//         lv_anim_start(&anim);
//         break;
//     }
// }

// static void event_setup_cb(void)
// {
//     lv_obj_add_event_cb(ui_calendar.scrCalendar, (lv_event_cb_t)my_gesture_event_cb, LV_EVENT_GESTURE, ui_calendar.scrCalendar);
// }

// void ui_calendar_init(void)
// {
//     ui_calendar_cb.ui_setup_cb = (void (*)(void *))ui_setup_cb;
//     ui_calendar_cb.ui_load_cb = ui_load_cb;
//     ui_calendar_cb.ui_destory_cb = ui_destory_cb;
//     ui_calendar_cb.event_setup_cb = event_setup_cb;
//     ui_stack_push(&ui_calendar_cb);
//     ui_setup_cb(&ui_calendar);
//     ui_load_cb();
//     event_setup_cb();
// }
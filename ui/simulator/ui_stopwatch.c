/**
 * @file ui_stopwatch.c
 * @author Jamiexu (doxm@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ui_stopwatch.h"

LV_IMG_DECLARE(_flag_alpha_35x35)
LV_IMG_DECLARE(_proceed_alpha_35x35)
LV_IMG_DECLARE(_start_icon_alpha_35x35)
LV_IMG_DECLARE(_stop_circle_filled_alpha_35x35)

typedef struct
{
    lv_obj_t *time;
    lv_obj_t *btn1;
    lv_obj_t *btn2;
    lv_obj_t *btn2_label;
    lv_obj_t *btn3;
    lv_obj_t *flags;
} component_t, *component_ptr;

typedef struct
{
    uint32_t count;
    enum
    {
        TIMER_STATE_STOPPED = 0,
        TIMER_STATE_RUNNING,
        TIMER_STATE_PAUSED,
    } state;
    lv_timer_t *timer;
} timer_manager_t;

static component_t comp;
static timer_manager_t timer;

lv_ui_page_t lv_ui_page_stopwatch = {
    .id = LV_PAGE_STOPWATCH,
    .page = NULL,
    .ui_setup_cb = ui_setup_cb,
    .ui_destory_cb = ui_destory_cb,
    .event_setup_cb = event_setup_cb};

static void ui_setup_cb(void)
{
    lv_obj_t *page;
    lv_ui_page_stopwatch.page = lv_obj_create(NULL);
    page = lv_ui_page_stopwatch.page;

    lv_obj_set_style_bg_color(page, lv_color_hex3(0x000), LV_PART_MAIN);

    lv_obj_set_style_pad_all(page, 20, LV_PART_MAIN);

    lv_obj_t *cont = lv_obj_create(page);
    lv_obj_set_size(cont, LV_PCT(100), 100);
    lv_obj_set_style_bg_opa(cont, LV_OPA_0, LV_PART_MAIN);

    comp.time = lv_label_create(cont);
    lv_label_set_text(comp.time, "00:00:00");
    lv_obj_set_size(comp.time, LV_PCT(80), 50);
    lv_obj_align_to(comp.time, cont, LV_ALIGN_CENTER, 5, -10);
    lv_obj_set_style_text_color(comp.time, lv_color_hex3(0xFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(comp.time, &lv_font_montserrat_30, LV_PART_MAIN);

    comp.btn1 = lv_btn_create(page);
    lv_obj_set_size(comp.btn1, 50, 35);
    lv_obj_align_to(comp.btn1, comp.time, LV_ALIGN_OUT_BOTTOM_MID, -65, -10);
    lv_obj_clear_flag(comp.btn1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(comp.btn1, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
    lv_obj_add_event_cb(comp.btn1, btn_flag_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *label1 = lv_label_create(comp.btn1);
    lv_label_set_text(label1, "Flag");
    lv_obj_set_style_text_color(label1, lv_color_hex3(0xFFF), LV_PART_MAIN);
    lv_obj_center(label1);

    comp.btn2 = lv_btn_create(page);
    lv_obj_set_size(comp.btn2, 50, 35);
    lv_obj_align_to(comp.btn2, comp.btn1, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_add_event_cb(comp.btn2, btn_start_cb, LV_EVENT_CLICKED, NULL);

    comp.btn2_label = lv_label_create(comp.btn2);
    lv_label_set_text(comp.btn2_label, "Start");
    lv_obj_set_style_text_color(comp.btn2_label, lv_color_hex3(0xFFF), LV_PART_MAIN);
    lv_obj_center(comp.btn2_label);

    comp.btn3 = lv_btn_create(page);
    lv_obj_set_size(comp.btn3, 50, 35);
    lv_obj_align_to(comp.btn3, comp.btn2, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_clear_flag(comp.btn3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(comp.btn3, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
    lv_obj_add_event_cb(comp.btn3, btn_stop_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *label3 = lv_label_create(comp.btn3);
    lv_label_set_text(label3, "Stop");
    lv_obj_set_style_text_color(label3, lv_color_hex3(0xFFF), LV_PART_MAIN);
    lv_obj_center(label3);

    comp.flags = lv_textarea_create(page);
    lv_obj_set_size(comp.flags, LV_PCT(100), LV_PCT(60));
    lv_obj_align_to(comp.flags, cont, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_obj_set_style_bg_opa(comp.flags, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_text_font(comp.flags, &lv_font_montserratMedium_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(comp.flags, lv_color_white(), LV_PART_MAIN);
}

static void ui_destory_cb(void)
{
}

static void event_setup_cb(void)
{
}

static void btn_flag_cb(lv_event_t *e)
{
    lv_textarea_add_text(comp.flags, lv_label_get_text(comp.time));
    lv_textarea_add_text(comp.flags, "\n\n");
}

static void btn_start_cb(lv_event_t *e)
{
    if (timer.state == TIMER_STATE_RUNNING)
    {
        lv_label_set_text(comp.btn2_label, "Res.");
        timer.state = TIMER_STATE_PAUSED;
        lv_timer_pause(timer.timer);
    }
    else if (timer.state == TIMER_STATE_STOPPED)
    {
        lv_obj_add_flag(comp.btn1, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(comp.btn3, LV_OBJ_FLAG_CLICKABLE);
        lv_label_set_text(comp.btn2_label, "Pause");
        if (timer.timer == NULL)
            timer.timer = lv_timer_create(timer_cb, 16, NULL);

        timer.count = 0;
        timer.state = TIMER_STATE_RUNNING;
        lv_textarea_set_text(comp.flags, "");
        lv_timer_reset(timer.timer);
        lv_timer_resume(timer.timer);
    }
    else if (timer.state == TIMER_STATE_PAUSED)
    {
        lv_label_set_text(comp.btn2_label, "Pause");
        lv_timer_resume(timer.timer);
        timer.state = TIMER_STATE_RUNNING;
    }
}

static void btn_stop_cb(lv_event_t *e)
{
    if (timer.state == TIMER_STATE_STOPPED)
        return;
    timer.state = TIMER_STATE_STOPPED;

    lv_obj_add_flag(comp.btn2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(comp.btn1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(comp.btn3, LV_OBJ_FLAG_CLICKABLE);


    lv_label_set_text(comp.btn2_label, "Start");
    lv_timer_pause(timer.timer);
}

static void timer_cb(lv_timer_t *e)
{
    timer.count += 1;
    lv_label_set_text_fmt(comp.time, "%02d:%02d:%02d", timer.count / 60 / 60, timer.count / 60, timer.count % 60);
}

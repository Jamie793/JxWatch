#ifndef __UI_JAMIEXU_H__
#define __UI_JAMIEXU_H__
#include "lvgl.h"
#include "widget_calendar.h"

#define LV_PAGE_SIZE_MAX 5
#define LV_PAGE_STACK_SIZE_MAX 5

typedef enum
{
    LV_PAGE_MAIN = 0,
    LV_PAGE_WEATHER = 1,
    LV_PAGE_CALENDAR = 2,
    LV_PAGE_CALCULATOR = 3,
    LV_PAGE_STOPWATCH = 4
} lv_ui_page_index_t;

typedef struct
{
    lv_ui_page_index_t id;
    lv_obj_t *page;
    void (*ui_setup_cb)(void);
    void (*ui_destory_cb)(void);
    void (*event_setup_cb)(void);
} lv_ui_page_t;

typedef struct
{
    uint8_t size;
    int8_t pos;
    lv_ui_page_t *data[LV_PAGE_STACK_SIZE_MAX];
} ui_stack_t;

void ui_init(void);

void ui_stack_init(void);

lv_ui_page_t *ui_stack_top(void);

lv_ui_page_t *ui_stack_pop(void);

void ui_stack_clear(void);

void ui_stack_push(lv_ui_page_t *ui);

void ui_load(lv_ui_page_index_t page_id);

void ui_swtich(lv_ui_page_index_t page_id);

void ui_back(void);

#endif
#include "ui.h"
#include "ui_main.h"
#include "anim.h"

static ui_stack_t ui_stack;

extern lv_ui_page_t lv_ui_page_main;
extern lv_ui_page_t lv_ui_page_weather;
extern lv_ui_page_t lv_ui_page_calculator;
extern lv_ui_page_t lv_ui_page_stopwatch;

static lv_ui_page_t *lv_page_tables[LV_PAGE_SIZE_MAX] = {&lv_ui_page_main, &lv_ui_page_weather, NULL, &lv_ui_page_calculator, &lv_ui_page_stopwatch};

void ui_init(void)
{
    ui_stack_init();
    ui_load(LV_PAGE_MAIN);
}

void ui_stack_init(void)
{
    ui_stack.pos = -1;
    ui_stack.size = LV_PAGE_STACK_SIZE_MAX;
}

lv_ui_page_t *ui_stack_top(void)
{
    if (ui_stack.pos == -1)
        return NULL;
    return ui_stack.data[ui_stack.pos];
}

lv_ui_page_t *ui_stack_pop(void)
{
    if (ui_stack.pos == -1)
        return NULL;

    return ui_stack.data[ui_stack.pos--];
}

void ui_stack_clear(void)
{
    while (ui_stack.pos != -1)
    {
        lv_obj_del(ui_stack_pop()->page);
    }
}

void ui_stack_push(lv_ui_page_t *ui)
{
    if ((ui == NULL) || (ui_stack.pos == ui_stack.size - 1))
        return;

    ui_stack.data[++ui_stack.pos] = ui;
}

void ui_load(lv_ui_page_index_t page_id)
{
    if (page_id > LV_PAGE_SIZE_MAX)
        return;
    lv_ui_page_t *page = lv_page_tables[page_id];
    if (page->page == NULL){
        page->ui_setup_cb();
        page->event_setup_cb();
    }
    lv_scr_load(page->page);
    // lv_scr_load_anim();
    anim_resize_cb(page->page, 0);
    // anim_load_page(page->page);
    ui_stack_push(page);
}

void ui_swtich(lv_ui_page_index_t page_id)
{
    // if (page_id > LV_PAGE_SIZE_MAX)
    //     return;
    // ui_stack_clear();
    // ui_load(page_id);
}

void ui_back(void)
{
    lv_ui_page_t *page;
    if (ui_stack.pos == -1)
        return;
    page = ui_stack_pop();
    lv_obj_del(page->page);
    page->page = NULL;

    page = ui_stack_top();
    lv_scr_load(page->page);
}
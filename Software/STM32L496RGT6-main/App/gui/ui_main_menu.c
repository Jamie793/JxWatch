#include "ui_main_menu.h"

LV_IMG_DECLARE(calender);
LV_IMG_DECLARE(time);
LV_IMG_DECLARE(heart);

static lv_coord_t gridToolsCols[] = {60, 60, 60, LV_GRID_TEMPLATE_LAST};
static lv_coord_t gridToolsRows[] = {60, 60, 60, LV_GRID_TEMPLATE_LAST};

// static lv_ui_menu_item_t menuItem[] = {
//     {.row = 0,
//      .col = 0,
//      .img = &calender},
//     {.row = 0,
//      .col = 1,
//      .img = &time},
//     {.row = 0,
//      .col = 2,
//      .img = &heart},
// };

void ui_main_menu_init(lv_ui_main_t *ui)
{
    ui->gridTools = lv_obj_create(ui->scrMain_tileview_tileMenu);
    lv_obj_set_style_grid_column_dsc_array(ui->gridTools, gridToolsCols, 0);
    lv_obj_set_style_grid_row_dsc_array(ui->gridTools, gridToolsRows, 0);
    lv_obj_set_pos(ui->gridTools, 10, 0);
    lv_obj_set_size(ui->gridTools, MY_DISP_HOR_RES - 20, MY_DISP_VER_RES);
    lv_obj_set_layout(ui->gridTools, LV_LAYOUT_GRID);
    lv_obj_set_scrollbar_mode(ui->gridTools, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_bg_color(ui->gridTools, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_border_opa(ui->gridTools, LV_OPA_0, LV_PART_MAIN);


    // lv_obj_t *img;
    // lv_ui_menu_item_t *item;
    // for (uint16_t i = 0; i < 3; i++)
    // {
    //     item = &menuItem[i];
    //     img = lv_img_create(ui->gridTools);
    //     lv_img_set_src(img, item->img);

    //     lv_obj_set_grid_cell(img, LV_GRID_ALIGN_STRETCH, item->col, 1,
    //                          LV_GRID_ALIGN_STRETCH, item->row, 1);
    // }
}

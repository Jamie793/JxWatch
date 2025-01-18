#ifndef __UI_MAIN_MENU_JAMIEXU_H__
#define __UI_MAIN_MENU_JAMIEXU_H__
#include "ui_main.h"

typedef struct
{
    uint16_t row;
    uint16_t col;
    lv_img_dsc_t *img;
} lv_ui_menu_item_t;

void ui_main_menu_init(lv_ui_main_t *ui);

#endif
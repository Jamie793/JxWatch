#ifndef __UI_MAIN_MENU_JAMIEXU_H__
#define __UI_MAIN_MENU_JAMIEXU_H__
#include "ui.h"

typedef struct
{
    void *icon;
    char *name;
} ui_main_menu_item_t;

void ui_main_menu_load(lv_obj_t *tile);

#endif
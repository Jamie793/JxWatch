#ifndef __ANIM_JAMIEXU_H__
#define __ANIM_JAMIEXU_H__
#include "lvgl.h"
#include "ui.h"

void anim_set_x_cb(void *var, int32_t v);

void anim_set_y_cb(void *var, int32_t v);

void anim_set_width_cb(void *var, int32_t v);

void anim_set_height_cb(void *var, int32_t v);

void anim_resize_cb(void *var, int32_t v);

void anim_load_page(lv_obj_t *page);

#endif
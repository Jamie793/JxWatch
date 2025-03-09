#include "anim.h"

void anim_set_x_cb(void *var, int32_t v)
{
    lv_obj_set_x(var, v);
}

void anim_set_y_cb(void *var, int32_t v)
{
    lv_obj_set_y(var, v);
}

void anim_set_width_cb(void *var, int32_t v)
{
    lv_obj_set_width(var, v);
}

void anim_set_height_cb(void *var, int32_t v)
{
    lv_obj_set_height(var, v);
}

void anim_resize_cb(void *var, int32_t v)
{
    lv_obj_set_size(var, (int16_t)((int16_t)(v * MY_DISP_HOR_RES) / 100.0), (int16_t)((int16_t)(v * MY_DISP_VER_RES) / 100.0));
}

void anim_load_page(lv_obj_t *page)
{
    lv_anim_t a;
     lv_anim_init(&a);
    lv_anim_set_var(&a, page);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_playback_time(&a, 300);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);

    lv_anim_set_exec_cb(&a, anim_resize_cb);
    lv_anim_start(&a);
}
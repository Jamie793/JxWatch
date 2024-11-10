#include "ui.h"

void ui_init(){
    ui_main_init();
}

void ui_init_style(lv_style_t * style)
{
	if (style->prop_cnt > 1)
		lv_style_reset(style);
	else
		lv_style_init(style);
}
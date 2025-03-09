#include "widget_calendar.h"
#include "stdlib.h"
#include "stdio.h"

#ifndef WIDGET_CALENDAR_EN
#define WIDGET_CALENDAR_EN 0
#endif

#define ROW_WIDTH_WEIGHT 16
#define COL_WIDTH_WEIGHT 12.5

#define OFFSET_X 0
#define OFFSET_Y 150

// #define ROW_DIV_WEIGHT 0.01
// #define COL_DIW_WEIGHT 1

#define COL_NUMS 7
#define ROW_NUMS 8

#define YEARS "2024年"

#define MONTHS "1月\n2月\n3月\n4月\n5月\n6月\n7月\n8月\n9月\n10月\n11月\n12月"

// static lv_coord_t cols[COL_NUMS + 1] = {23, 23, 23, 23, 23, 23, 23, LV_GRID_TEMPLATE_LAST};
// static lv_coord_t rows[ROW_NUMS + 1] = {30, 30, 30, 30, 30, 30, LV_GRID_TEMPLATE_LAST};
static const char *weeksDispCn[7] = {"日", "一", "二", "三", "四", "五", "六"};
static const char *weeksDispEn[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
static uint8_t monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *btnMap[COL_NUMS * ROW_NUMS];
static char dayNum[COL_NUMS * ROW_NUMS][10];
static lv_obj_t *btnMatrix;
static lv_calendar_date_t currentDate = {
    .year = 2024,
    .month = 11,
    .day = 19};

static lv_calendar_date_t today = {
    .year = 2024,
    .month = 11,
    .day = 19};

lv_obj_t *currentDateLabel;

static void month_event_cb(lv_event_t *e)
{
    uint8_t index = (uint8_t)lv_event_get_user_data(e);
    if (index == 0)
    {
        if (--currentDate.month == 0)
        {
            currentDate.year--;
            currentDate.month = 12;
        }
    }
    else if (index == 1)
    {
        if (++currentDate.month > 12)
        {
            currentDate.year++;
            currentDate.month = 1;
        }
    }
    lv_label_set_text_fmt(currentDateLabel, "%d年%02d月", currentDate.year, currentDate.month);
    load_date(currentDate);
}

static uint8_t is_leap_year(uint16_t year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1; // 闰年
    }
    return 0; // 平年
}

static uint8_t get_day_of_week(uint16_t year, uint8_t month, uint8_t day)
{
    uint8_t y = year % 100;
    uint8_t c = year / 100 % 100;
    uint8_t w = (y + (y / 4) + (c / 4) - (2 * c) + (26 * (month + 1) / 10) + day - 1);
    w = (w % 7 + 7) % 7;
    return w;
}

static void load_date(lv_calendar_date_t date)
{
    uint8_t i;
    uint8_t countMonth;
    uint8_t preCountMonth = monthDays[(((date.month - 1) == 0) ? 12 : date.month - 1) - 1];
    uint8_t firstDay = get_day_of_week(date.year, date.month, 1);
    if (date.month == 2)
        countMonth = monthDays[date.month - 1] + is_leap_year(date.year);
    else
        countMonth = monthDays[date.month - 1];

    lv_btnmatrix_clear_btn_ctrl_all(btnMatrix, LV_BTNMATRIX_CTRL_DISABLED);
    lv_btnmatrix_clear_btn_ctrl_all(btnMatrix, LV_BTNMATRIX_CTRL_CHECKED);
    for (i = 0; i < firstDay; i++)
    {
        lv_btnmatrix_set_btn_ctrl(btnMatrix, i + 7, LV_BTNMATRIX_CTRL_DISABLED);
        lv_snprintf(dayNum[i], sizeof(dayNum[0]), "%d", preCountMonth - firstDay + i + 1);
    }

    for (; i < firstDay + countMonth; i++)
    {
        if ((i - firstDay + 1) == today.day && date.year == today.year && date.month == today.month)
            lv_btnmatrix_set_btn_ctrl(btnMatrix, i + 7, LV_BTNMATRIX_CTRL_CHECKED);
        lv_snprintf(dayNum[i], sizeof(dayNum[0]), "%d", i - firstDay + 1);
    }

    for (; i < 7 * 8; i++)
    {
        lv_btnmatrix_set_btn_ctrl(btnMatrix, i + 7, LV_BTNMATRIX_CTRL_DISABLED);
        lv_snprintf(dayNum[i], sizeof(dayNum[0]), "%d", (i - (firstDay + countMonth)) + 1);
    }

    lv_obj_invalidate(btnMatrix);
}

lv_obj_t *widget_calendar_create(lv_obj_t *parent)
{
    lv_obj_t *obj = lv_obj_create(parent);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(obj, MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_style_border_opa(obj, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN);

    currentDateLabel = lv_label_create(obj);
    lv_obj_align_to(currentDateLabel, obj, LV_ALIGN_TOP_MID, -25, 10);
    lv_label_set_text_fmt(currentDateLabel, "%d年%02d月", currentDate.year, currentDate.month);
    lv_obj_set_style_text_font(currentDateLabel, &lv_customer_font_huawenkaiti_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(currentDateLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t *arrowLeft = lv_btn_create(obj);
    lv_obj_align_to(arrowLeft, currentDateLabel, LV_ALIGN_OUT_LEFT_MID, -10, -8);
    lv_obj_add_event_cb(arrowLeft, month_event_cb, LV_EVENT_CLICKED, (void *)0);
    lv_obj_set_style_bg_opa(arrowLeft, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_border_opa(arrowLeft, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_shadow_opa(arrowLeft, LV_OPA_0, LV_PART_MAIN);

    lv_obj_t *arrowLeftLabel = lv_label_create(arrowLeft);
    lv_label_set_text(arrowLeftLabel, LV_SYMBOL_LEFT);
    lv_obj_set_style_text_color(arrowLeftLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t *arrowRight = lv_btn_create(obj);
    lv_obj_align_to(arrowRight, currentDateLabel, LV_ALIGN_OUT_RIGHT_MID, 0, -8);
    lv_obj_add_event_cb(arrowRight, month_event_cb, LV_EVENT_CLICKED, (void *)1);
    lv_obj_set_style_bg_opa(arrowRight, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_border_opa(arrowRight, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_shadow_opa(arrowRight, LV_OPA_0, LV_PART_MAIN);

    lv_obj_t *arrowRightLabel = lv_label_create(arrowRight);
    lv_label_set_text(arrowRightLabel, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_color(arrowRightLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t *time = lv_label_create(obj);
    lv_label_set_text(time, "11:57");
    lv_obj_align(time, LV_ALIGN_TOP_RIGHT, -10, 10);
    lv_obj_set_style_text_color(time, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    btnMatrix = lv_btnmatrix_create(obj);
    lv_obj_set_size(btnMatrix, MY_DISP_HOR_RES - 5, MY_DISP_VER_RES - 30);
    lv_obj_align_to(btnMatrix, obj, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_set_scrollbar_mode(btnMatrix, LV_SCROLLBAR_MODE_OFF);
    lv_btnmatrix_set_btn_ctrl_all(btnMatrix, LV_BTNMATRIX_CTRL_CLICK_TRIG | LV_BTNMATRIX_CTRL_NO_REPEAT);

    lv_obj_set_style_border_opa(btnMatrix, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_style_text_font(btnMatrix, &lv_customer_font_huawenkaiti_14, LV_PART_MAIN | LV_PART_ITEMS);
    lv_obj_set_style_text_color(btnMatrix, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_PART_ITEMS);
    lv_obj_set_style_bg_opa(btnMatrix, LV_OPA_0, LV_PART_ITEMS);
    lv_obj_set_style_bg_color(btnMatrix, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(btnMatrix, LV_OPA_10, LV_PART_MAIN);
    lv_obj_set_style_shadow_opa(btnMatrix, LV_OPA_0, LV_PART_ITEMS);

    uint8_t i, j = 0;
    for (i = 0; i < COL_NUMS * ROW_NUMS; i++)
    {
        if (i < 7)
            btnMap[i] = weeksDispCn[i];
        else if (i != 0 && (i + 1) % 8 == 0)
            btnMap[i] = "\n";
        else
        {
            dayNum[j][0] = 'x';
            btnMap[i] = dayNum[j];
            j++;
        }
    }

    btnMap[COL_NUMS * ROW_NUMS - 1] = "";

    lv_btnmatrix_set_map(btnMatrix, (const char **)btnMap);

    lv_btnmatrix_clear_btn_ctrl_all(btnMatrix, LV_BTNMATRIX_CTRL_DISABLED);
    for (i = 0; i < 7; i++)
        lv_btnmatrix_set_btn_ctrl(btnMatrix, i, LV_BTNMATRIX_CTRL_DISABLED);

    load_date(currentDate);
    return obj;
}

void widget_calendar_set_today(lv_calendar_date_t date)
{
    memcpy(&today, &date, sizeof(lv_calendar_date_t));
}
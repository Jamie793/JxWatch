/**
 * @file ui_calculator.c
 * @author Jamiexu (doxm@foxmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "ui_calculator.h"
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define EXPRESSION_MAX 255
#define MATH_SYMBOL_MAX 6
#define MATH_SYMBOL_NAME_MAX 10
#define STACK_MAX 16

#define PI 3.141592653
#define E 2.7182818284

lv_ui_page_t lv_ui_page_calculator = {
    .id = LV_PAGE_CALCULATOR,
    .page = NULL,
    .ui_setup_cb = ui_setup_cb,
    .ui_destory_cb = ui_destory_cb,
    .event_setup_cb = event_setup_cb
};

static const char *keyMap[] = {
    "2nd", "deg(", "sin(", "cos(", "tan(", "\n",
    "^", "lg(", "ln(", "(", ")", "\n",
    "sqrt(", "AC", "Del", "%", "/", "\n",
    "!", "7", "8", "9", "*", "\n",
    "1/x", "4", "5", "6", "-", "\n",
    "Pi", "1", "2", "3", "+", "\n",
    "Noting", "e", "0", ".", "=", ""};

static const char *mathSymbols[MATH_SYMBOL_MAX] = {
    "sin(",
    "cos(",
    "tan(",
    "sqrt(",
    "ln(",
    "lg(",
};

// static const char *op[] = {
//     "+", "-", "*", "/", "e", "%", "Pi"};

static char expression[EXPRESSION_MAX] = "Input expression...\0";

static uint16_t expressionPos = 0;

static int16_t find_math_symbol(void)
{
    uint8_t i;
    uint8_t symbolLen;
    for (i = 0; i < MATH_SYMBOL_MAX; i++)
    {
        symbolLen = strlen(mathSymbols[i]);
        if (expressionPos < symbolLen)
            continue;
        if (strncmp(expression + expressionPos - symbolLen, mathSymbols[i], symbolLen) == 0)
            return expressionPos - symbolLen;
    }
    return -1;
}

inline static double exec_op(double left, double right, char op)
{
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    default:
        return 0;
    }
}

inline static double exec_symbol_op(double val, char *op)
{
    if (strncmp(op, "sin", 3) == 0)
        return sin(val);
    else if (strncmp(op, "cos", 3) == 0)
        return cos(val);
    else if (strncmp(op, "tan", 3) == 0)
        return tan(val);
    else if (strncmp(op, "sqrt", 4) == 0)
        return sqrt(val);
    else if (strncmp(op, "ln", 2) == 0)
        return log(val); // natural log (base e)
    else if (strncmp(op, "lg", 2) == 0)
        return log10(val); // log base 10
    else
        return 0;
}

inline static uint8_t is_operator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    return 0;
}

inline static uint8_t is_symbol_op(char *op)
{
    if (strncmp(op, "sin", 3) == 0 || strncmp(op, "cos", 3) == 0 || strncmp(op, "tan", 3) == 0 || strncmp(op, "sqrt", 4) == 0 ||
        strncmp(op, "ln", 3) == 0 || strncmp(op, "lg", 2) == 0)
        return 1;
    return 0;
}

inline static uint8_t priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '%')
        return 3;
    else if (op == '^')
        return 4;
    return 0;
}

/**
 * @brief Check the expression if they are illegal
 *        e.g 1*(2-3  1*2-3) 1+-2 and so on. these are illegal
 *
 * @param expr
 * @return uint8_t 1:error 0:no error
 */
static uint8_t check_error(char *expr)
{
    int16_t opTop = -1;
    uint16_t i = 0;
    while (expr[i] != '\0')
    {
        if (expr[i] == '(')
            opTop++;
        else if (expr[i] == ')')
            opTop--;
        i++;
    }

    if (opTop != -1)
        return 1;

    i = 0;
    while (expr[i] != '\0')
    {
        if (i == 0 && is_operator(expr[i]) && !(expr[i] == '-' || expr[i] == '+'))
            return 1;
        else if (i != 0 && is_operator(expr[i]) && is_operator(expr[i - 1]))
            return 1;
        i++;
    }

    return 0;
}

/**
 * @brief Turn to suffix expression
 * e.g: 12*3+sin(6-5)+6 -> 12 3 * 6 5 - sin + 6 +
 *      12+3*sin(6-5)+6 -> 12 3 6 5 - sin * + 6 +
 *
 */
static void turn_to_suffix(char *expr)
{
    char opStack[STACK_MAX][MATH_SYMBOL_NAME_MAX] = {0};
    char suffix[EXPRESSION_MAX] = {0};
    char symbol[MATH_SYMBOL_NAME_MAX] = {0};

    int16_t opTop = -1;
    uint16_t i = 0, j = 0;
    uint8_t k = 0;

    // Testing
    // memset(expression, 0, EXPRESSION_MAX);
    // strncpy(expression, "(1.2+3.4-6.5*7.1/8.9-(sin(Pi/2)+(2^8-6)-(6-cos(16-7-(8-1)))))%\0", strlen("(1.2+3.4-6.5*7.1/8.9-(sin(Pi/2)+(2^8-6)-(6-cos(16-7-(8-1)))))%\0"));
    // strncpy(expression, "1 + 2 - 3 * 4 / 5 + sin(Pi/2) - 6 / cos(1 + 3 * 9) * (13 * e - (9 + 3))", strlen("1 + 2 - 3 * 4 / 5 + sin(Pi/2) - 6 / cos(1 + 3 * 9) * (13 * e - (9 + 3))"));
    // strncpy(expression, "sin(30) + 3 * cos(45) - 4.5 / 2", strlen("sin(30) + 3 * cos(45) - 4.5 / 2"));

    while (expr[i] != '\0')
    {
        if (expr[i] == ' ')
        {
            i++;
            continue;
        }
        // Is math symbol
        if (isalpha(expr[i]) && expr[i] != 'e' && expr[i] != 'P')
        {
            k = 0;
            while (isalpha(expr[i]))
            {
                symbol[k++] = expr[i++];
            }
            symbol[k] = '\0';
            suffix[j++] = ' ';
            strncpy(opStack[++opTop], symbol, strlen(symbol));
            i--;
        }
        else if (isalpha(expr[i]) && (expr[i] == 'e' || expr[i] == 'P'))
        {
            suffix[j++] = ' ';
            if (expr[i] == 'e')
            {
                suffix[j++] = 'e';
            }
            else
            {
                suffix[j++] = 'P';
                suffix[j++] = 'i';
                i++;
            }
        }
        // Is + - * /
        else if (is_operator(expr[i]))
        {
            // If the opStack symbol of opTop greater than current symbol
            suffix[j++] = ' ';
            while (opTop != -1 && strlen(opStack[opTop]) == 1 && priority(opStack[opTop][0]) >= priority(expr[i]))
            {
                strncpy(&suffix[j++], &opStack[opTop--][0], 1);
            }
            // Push current symbol
            opStack[++opTop][0] = expr[i];
            opStack[opTop][1] = '\0';
        }
        else if (expr[i] == '%')
        {
            opStack[++opTop][0] = '%';
            opStack[opTop][1] = '\0';
        }
        else if (expr[i] == '(')
        {
            opStack[++opTop][0] = '(';
            opStack[opTop][1] = '\0';
        }
        else if (expr[i] == ')')
        {
            // Pop all op
            while (opTop != -1 && strlen(opStack[opTop]) == 1 && opStack[opTop][0] != '(')
            {
                suffix[j++] = ' ';
                strncpy(&suffix[j++], &opStack[opTop--][0], 1);
            }
            // Pop "("
            opTop--;
            if (is_symbol_op(opStack[opTop]))
            {
                suffix[j++] = ' ';
                strncpy(&suffix[j], opStack[opTop], strlen(opStack[opTop]));
                j += strlen(opStack[opTop]);
                opTop--;
            }
        }
        else if (isdigit(expr[i]))
        {
            suffix[j++] = ' ';
            while (isdigit(expr[i]) || expr[i] == '.')
                strncpy(&suffix[j++], &expr[i++], 1);
            i--;
        }
        i++;
    }

    // Pop remaining op dong'g
    while (opTop != -1)
    {
        suffix[j++] = ' ';
        strncpy(&suffix[j++], &opStack[opTop--][0], 1);
    }

    memset(expr, 0, strlen(expr));
    strncpy(expr, suffix, strlen(suffix));
}

static double evaluate(char *expr)
{
    double valStack[STACK_MAX];
    char symbol[MATH_SYMBOL_NAME_MAX];
    uint8_t point = 0;
    double tmpVal = 0.0f;
    double tmpVal2 = 0.0f;
    int16_t valTop = -1;
    uint16_t i = 0;

    turn_to_suffix(expr); // turn to suffix expression
    while (*expr != '\0')
    {
        if (*expr == ' ')
        {
            expr++;
            continue;
        }
        else if (isdigit(*expr) || (*expr == '-' && isdigit(*(expr + 1))))
        {
            point = 0;
            tmpVal = 0.0f;
            tmpVal2 = 0.0f;
            while (isdigit(*expr) || (*expr == '-' && isdigit(*(expr + 1))) || *expr == '.')
            {
                if (*expr == ' ')
                {
                    expr++;
                    continue;
                }
                else if (*expr == '.')
                {
                    if (point == 1)
                        return 0;
                    point = 1;
                    expr++;
                    continue;
                }
                if (point == 0)
                    tmpVal = tmpVal * 10 + (*expr - '0');
                else
                    tmpVal2 = (tmpVal2 + (*expr - '0')) / 10;
                expr++;
            }
            tmpVal += tmpVal2;
            valStack[++valTop] = tmpVal;
        }
        else if (valTop >= 1 && is_operator(*expr) && *expr != '^')
        {
            tmpVal = valStack[valTop - 1];
            tmpVal2 = valStack[valTop];
            valTop -= 2;
            tmpVal = exec_op(tmpVal, tmpVal2, *expr);
            valStack[++valTop] = tmpVal;
            expr++;
        }
        else if (*expr == '+' || *expr == '-')
        {
            if (*expr == '-')
            {
                tmpVal = valStack[valTop--];
                valStack[++valTop] = -1 * tmpVal;
            }
            expr++;
        }
        else if (isalpha(*expr) && (*expr != 'e' && *expr != 'P'))
        {
            i = 0;
            symbol[0] = '\0';
            while (isalpha(*expr))
            {
                symbol[i++] = *expr;
                expr++;
            }
            symbol[i] = '\0';
            if (is_symbol_op(symbol))
            {
                tmpVal = valStack[valTop--];
                valStack[++valTop] = exec_symbol_op(tmpVal, symbol);
            }
        }
        else if (*expr == '%')
        {
            tmpVal = valStack[valTop--];
            valStack[++valTop] = tmpVal / 100.0f;
            expr++;
        }
        else if (*expr == '^')
        {
            tmpVal = valStack[valTop - 1];
            tmpVal2 = valStack[valTop];
            valTop -= 2;
            valStack[++valTop] = pow(tmpVal, tmpVal2);
            expr++;
        }
        else if (isalpha(*expr) && (*expr == 'e' || *expr == 'P'))
        {
            if (*expr == 'e')
                valStack[++valTop] = E;
            else
            {
                valStack[++valTop] = PI;
                expr++;
            }
            expr++;
        }
    }
    if (valTop != -1)
        return valStack[valTop--];
    return 0;
}

static void all_clear(lv_obj_t *input)
{
    expressionPos = 0;
    memset(expression, 0, EXPRESSION_MAX);
    strncpy(expression, "Input expression...", 20);
    lv_textarea_set_text(input, "Input expression...");
}

static void btn_event_cb(lv_event_t *e)
{
    int16_t index;
    double result = 0.0f;
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *input = (lv_obj_t *)lv_event_get_user_data(e);
    uint8_t id = lv_btnmatrix_get_selected_btn(obj);
    if (strncmp(expression, "Input expression...", 20) == 0)
    {
        memset(expression, 0, EXPRESSION_MAX);
        lv_textarea_set_text(input, "");
    }

    char *text = lv_btnmatrix_get_btn_text(obj, id);

    if (strncmp(text, "AC", 2) == 0)
        all_clear(input);
    else if (strncmp(text, "Del", 3) == 0)
    {
        if (expressionPos == 0)
            return;
        index = find_math_symbol();
        if (index != -1)
        {
            expressionPos = index;
            expression[expressionPos] = '\0';
        }
        else
        {
            expressionPos--;
            expression[expressionPos] = '\0';
        }
        lv_textarea_set_text(input, expression);
    }
    else if (strncmp(text, "=", 1) == 0)
    {
        if (check_error(expression))
        {
            all_clear(input);
            strncpy(expression, "Error\0", 6);
        }
        else
        {
            result = evaluate(expression);
            all_clear(input);
            if (result > 1e10 || result < 1e-10)
                sprintf(expression, "%e", result);
            else
                sprintf(expression, "%f", result);
        }
        expressionPos = strlen(expression);
        lv_textarea_set_text(input, expression);
    }
    else
    {
        if (expressionPos > EXPRESSION_MAX - 1)
            return;

        // if (strlen(text) > (21 - (expressionPos % 21)))
        //     expression[expressionPos++] = '\n';

        lv_textarea_add_text(input, text);
        strcpy(expression, lv_textarea_get_text(input));
        expressionPos = strlen(expression);
    }

    lv_obj_invalidate(input);
}

void ui_setup_cb(void)
{
    lv_obj_t *page;
    lv_ui_page_calculator.page = lv_obj_create(NULL);
    page = lv_ui_page_calculator.page;
    lv_obj_set_size(page, 240, 320);
    lv_obj_set_pos(page, 0, 0);
    lv_obj_set_style_bg_color(page, lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(page, LV_OPA_100, LV_PART_MAIN);

    lv_obj_t *input = lv_textarea_create(page);
    lv_obj_set_pos(input, 0, 0);
    lv_obj_set_size(input, LV_PCT(100), 70);
    lv_obj_set_style_text_color(input, lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_align(input, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_textarea_set_text(input, "Input expression...");
    lv_obj_set_style_pad_all(input, 20, LV_PART_MAIN);
    lv_obj_set_style_text_align(input, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN);
    lv_obj_set_style_bg_color(input, lv_color_hex3(0xEEE), LV_PART_MAIN);
    lv_obj_set_style_border_width(input, 1, LV_PART_MAIN);

    lv_obj_t *keys = lv_btnmatrix_create(page);
    lv_btnmatrix_set_map(keys, keyMap);
    lv_btnmatrix_set_one_checked(keys, true);
    lv_btnmatrix_set_btn_ctrl_all(keys, LV_BTNMATRIX_CTRL_RECOLOR);
    lv_btnmatrix_set_btn_ctrl_all(keys, LV_BTNMATRIX_CTRL_CLICK_TRIG);

    lv_obj_set_size(keys, 240, 250);
    lv_obj_align_to(keys, input, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_add_event_cb(keys, btn_event_cb, LV_EVENT_VALUE_CHANGED, input);

    lv_obj_set_style_text_color(keys, lv_color_hex3(0x000), LV_PART_ITEMS);
    lv_obj_set_style_bg_color(keys, lv_color_hex(0xFFFFFF), LV_PART_ITEMS);
    lv_obj_set_style_text_font(keys, &lv_font_montserrat_12, LV_PART_ITEMS);
    lv_obj_set_style_shadow_opa(keys, LV_OPA_0, LV_PART_ITEMS);
    lv_obj_set_style_bg_opa(keys, LV_OPA_80, LV_PART_MAIN | LV_PART_ITEMS);
    lv_obj_set_style_bg_color(keys, lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_opa(keys, LV_OPA_0, LV_PART_MAIN);
}

void ui_destory_cb(void)
{
}

void event_setup_cb(void)
{
}

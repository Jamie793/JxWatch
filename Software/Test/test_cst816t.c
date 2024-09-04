#include "cst816t.h"
void test_cst816t(void){
    volatile uint8_t reg = cst816t_read_reg(0xA7);
    reg = 2;
}
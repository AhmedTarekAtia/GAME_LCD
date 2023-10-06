#ifndef BIT_MATH_H
#define BIT_MATH_H
#define SET_BIT(num,bitnum) num = num | (1 << bitnum)
#define CLR_BIT(num,bitnum) num = num & (~(1 << bitnum))
#define TOGGLE_BIT(num,bitnum) num = num ^ (1 << bitnum)
#define GET_BIT(num,bitnum)  ((num >> bitnum) & 1)
#endif

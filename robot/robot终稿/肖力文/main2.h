#ifndef main_process.h
#define main_process.h
#include "typstrct.h"

//功能：实现功能的主进程
//输入：鼠标的坐标和按键状态
//输出：无
extern void mainprocess(int *x,int *y, int *pbutton);




//功能：将一位数字的分钟数调整成2位数字
//输入：分钟的字符串的首地址
//输出：无
extern void minute_adjust(char *s_minute);




//功能：点击“下一事件”后根据事件来调整时间
//输入：时间，事件，和事件是否发生变量的地址
//输出：无
extern void time_adjust_plus(int *time, int *times, int *wht_happen);

#endif // main_process

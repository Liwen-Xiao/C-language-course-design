#ifndef manbody.h
#define manbody.h

#include "typstrct.h"

extern void paint_man(CASE case_state, int identity);   //第一次画人的时候调用，会画出人的正面

void man_forebody(CASE case_state, int identity);   //人的正面，包括主人与陌生人

void man_backbody(CASE case_state);                 //人的背面

void man_leftbody(CASE case_state);                 //人的右面

void man_rightbody(CASE case_state);                //人的左面

void man_sleep(CASE case_state);                    //睡觉时的人像

void man_getup(CASE case_state);                    //起床

void sit_1(CASE case_state);                        //背面坐姿，工作和吃饭时调用

void sit_2(CASE case_state);                        //侧面坐姿，娱乐时调用

#endif

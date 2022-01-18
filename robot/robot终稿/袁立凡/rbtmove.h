#ifndef rbtmove.h
#define rbtmove.h

#include "typstrct.h"

void dmove(CASE *case_state, int casetype);//改变坐标点

void move0(CASE *case_state,int casetype);//坐标的改变与动作叠加

int aimmove(CASE *case_state,int x0,int y0,int xt,int yt, const Graph G, const int n, int casetype); //让机器人移动时需要直接调用的函数

#endif

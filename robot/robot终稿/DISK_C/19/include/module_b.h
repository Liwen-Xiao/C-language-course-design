#include "typstrct.h"
#ifndef module_box.h
#define module_box.h

/**************************************************
function:        overflow_box

description:     堆分配内存失败提示框

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void overflow_box(int x,int y);

/**************************************************
function:        phone_module

description:     手机的功能外框

Input:           x,y(坐标)

out:

quote:           advancegf.h
**************************************************************/
extern void phone_module(int x,int y);

/**************************************************
function:        phone_back

description:     iphone的home键

Input:           x,y(坐标)

out:

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void phone_back(int x,int y);

/**************************************************
function:        null_box

description:     寻找文件失败提示框

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void null_box(int x,int y);

extern void gg_bar();

/**************************************************
function:        FindWay_error

description:     寻路失败提示框

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void FindWay_error(int x,int y);

/**************************************************
function:        space_box

description:     显示堆区剩余内存空间（调试）

Input:           x,y(坐标)

out:             提示框

quote:           coreleft(alloc.h),advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void space_box(int x,int y);

/**************************************************
function:        trap

description:     机器人行走失败提示框(周围有障碍物)

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void trap(int x,int y);

/**************************************************
function:        pop_error

description:     栈弹出元素失败提示框(栈已空)

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void pop_error(int x,int y);

#endif

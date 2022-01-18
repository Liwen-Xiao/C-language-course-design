
#include "typstrct.h"
#ifndef color1.h
#define color1.h

/**************************************************
function:        transcolor

description:     颜色转换

Input:           rgb

out:             64k颜色值

quote:
**************************************************************/
extern int transcolor(int r,int g,int b);

/**************************************************
function:        linelevel_color

description:     水平线性渐变

Input:           x1,y1（左上角坐标）,x2,y2（右下角坐标）,r1,g1,b1（出发颜色）,r2,g2,b2（结束颜色）

out:

quote:
**************************************************************/
extern void linelevel_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2);

/**************************************************
function:        linever_color

description:     竖直线性渐变

Input:           x1,y1（左上角坐标）,x2,y2（右下角坐标）,r1,g1,b1（出发颜色）,r2,g2,b2（结束颜色）

out:

quote:
**************************************************************/
extern void linever_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2);

/**************************************************
function:        circle_color

description:     轴向渐变

Input:           x0,y0（圆心坐标）,r1,g1,b1（出发颜色）,r2,g2,b2（结束颜色）,r（渐变圆半径）

out:

quote:
**************************************************************/
extern void circle_color(int x0,int y0,int r1,int g1,int b1,int r2,int g2,int b2,int r);


#endif

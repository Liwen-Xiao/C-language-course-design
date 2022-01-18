#include "typstrct.h"
#ifndef input.h
#define input.h
/**************************************************
function:       put_English

description :    在指定的地方输出英文

Input :          x1,y1 输出位置坐标，ascii为该英文的ASCII码

out :           在指定位置输出英文字母

*************************************************************/
extern void putEnglish(int x1,int y1,int ascii,int mx,int my,int color);
/**************************************************
function:        outtextxy

description :    输出整个字符串

Input :          x,y（输出位置）,c（要输出的字符串）,mx,my（字母尺寸，横向/纵向）,mar（字符之间间距）,color

out :           图形模式下输出英文及数字

*************************************************************/
extern void outtextxy(int x,int y,char *c,int mx,int my,int mar,int color);
/*************************************************
Function: searchKeyValue
Description: 根据键值返回表中其对应字符
Calls:
Return: 若有则返回对应字符；若表中无此键值，则返回'\0'
*************************************************/
extern char searchKeyValue(int value);
#endif

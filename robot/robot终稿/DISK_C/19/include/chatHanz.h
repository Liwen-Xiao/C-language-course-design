#ifndef chatHanzi.h
#define chatHanzi.h
#include "typstrct.h"

/**************************************************
function:        extern int ShowChinese(int *qhwh,int num_chinese,int color,Area show_area,int size,char *hzk_dir);

description:     打印汉字

Input:           int *qhwh,int num_chinese,int color,Area show_area,int size,char *hzk_dir

output:
**************************************************************/
extern int ShowChinese(int *qhwh,int num_chinese,int color,Area show_area,int size,char *hzk_dir);

/**************************************************
function:        extern int ShowPerCharacter(int qhwh,Area show_area,Coordinate * current_position,int color,int size,char *hzk_dir);

description:     每个汉字打印

Input:           int qhwh,Area show_area,Coordinate * current_position,int color,int size,char *hzk_dir

output:
**************************************************************/
extern int ShowPerCharacter(int qhwh,Area show_area,Coordinate * current_position,int color,int size,char *hzk_dir);

/**************************************************
function:        extern int GetBit(int num,char ch);

description:     每位的像素点get

Input:           int num,char ch

output:
**************************************************************/
extern int GetBit(int num,char ch);

/**************************************************
function:        extern void CheckArea(Area position,Coordinate *current_position,int size);

description:     检验是否在聊天区域内，是否需要换行

Input:           Area position,Coordinate *current_position,int size

output:
**************************************************************/
extern void CheckArea(Area position,Coordinate *current_position,int size);



#endif


#ifndef chatInput.h
#define chatInput.h
#include "typstrct.h"

/**************************************************
function:        extern void CursorWhite(Coordinate current_show_position,int show_size);

description:     白色光标（盖住黑色光标）

Input:           Coordinate current_show_position,int show_size

output:
**************************************************************/
extern void CursorWhite(Coordinate current_show_position,int show_size);

/**************************************************
function:        extern void CursorBlack(Coordinate current_show_position,int show_size);

description:     黑色光标，短暂停留

Input:           Coordinate current_show_position,int show_size

output:
**************************************************************/
extern void CursorBlack(Coordinate current_show_position,int show_size);

/**************************************************
function:        extern void DeleteShow(Area show_area,Coordinate * current_show_position,int show_size );

description:     删掉汉字

Input:           Area show_area,Coordinate * current_show_position,int show_size

output:
**************************************************************/
extern void DeleteShow(Area show_area,Coordinate * current_show_position,int show_size );

/**************************************************
function:        extern void ShowWhite(Coordinate * current_show_position,int show_size);

description:     盖住删掉汉字的界面

Input:           Coordinate * current_show_position,int show_size

output:
**************************************************************/
extern void ShowWhite(Coordinate * current_show_position,int show_size);

/**************************************************
function:        extern void DeleteTab(Coordinate * current_en_position,CH* ch,EN* en,char *temp ,int * num_tab,int *ch_qhwh);

description:     在输入框删拼音

Input:           Coordinate * current_en_position,CH* ch,EN* en,char *temp ,int * num_tab,int *ch_qhwh

output:
**************************************************************/
extern void DeleteTab(Coordinate * current_en_position,CH* ch,EN* en,char *temp ,int * num_tab,int *ch_qhwh);

/**************************************************
function:        extern void ShowTxt(int *qhwh, Area show_area,Coordinate* current_show_position,int show_size);

description:     打印整段话

Input:           int *qhwh, Area show_area,Coordinate* current_show_position,int show_size

output:
**************************************************************/
extern void ShowTxt(int *qhwh, Area show_area,Coordinate* current_show_position,int show_size);

/**************************************************
function:        extern int ShowChTab(Area show_area,Coordinate current_show_position, int show_size,int *qhwh);

description:     汉字输入法主逻辑

Input:           Area show_area,Coordinate current_show_position, int show_size,int *qhwh

output:
**************************************************************/
extern int ShowChTab(Area show_area,Coordinate current_show_position/*现在正在码的字的左上角坐标*/, int show_size/*有48，36，28*/,int *qhwh);


#endif

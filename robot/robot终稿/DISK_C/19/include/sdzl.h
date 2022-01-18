#ifndef shou_dong_zhi_ling.h
#define shou_dong_zhi_ling.h
#include "typstrct.h"

//功能：手动指令的主函数
//输入：鼠标的状态指针，机器人的结构体指针，人的结构体指针，图的信息
//输出：无
void sdzl_main(int *x, int *y, int *button, CASE *robot, CASE *man, Graph G, int n, int times, int choice);


//功能；送水
//输入：机器人的结构体指针，人的坐标，图
//输出：无
void water(CASE *robot, int x, int y, Graph G, int n, int times, int choice) ;	//送水
#endif // shou_dong_zhi_ling

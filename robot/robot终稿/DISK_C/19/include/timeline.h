#ifndef time_line.h
#define time_line.h
#include "typstrct.h"

//功能：主人回家函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
extern void come_home(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[], VType G[], int n);



//功能：晚餐函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
extern void dinner(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n);



//功能：娱乐工作函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
extern void entertain_and_work(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n);



//功能：洗澡函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
extern void bath(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n);



//功能：早餐函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
extern void breakfast(CASE *robot, CASE *man,VType G[], int n);



#endif // time_line

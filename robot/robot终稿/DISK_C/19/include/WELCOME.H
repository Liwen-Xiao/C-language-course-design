#ifndef welcome.h
#define welcome.h
#include "typstrct.h"

//功能：欢迎静止界面
//输入：无
//输出：无
extern void outwelcome(void);




//功能：goodbye界面
//输入：无
//输出：无
extern void good_bye(void);




//功能：机器人logo输出
//输入：机器人的状态变量
//输出：无
extern void logo_robot(CASE robot_position);

#endif // welcome

#ifndef rbtbody.h
#define rbtbody.h

#include "typstrct.h"

void paint_robot(CASE case_state);      //第一次画机器人时调用，将画机器人处的背景储存，并画出机器人正面

void forebodyhead(CASE case_state);              //机器人正面

void backbodyhead(CASE case_state);              //机器人背面

void robot_left(CASE case_state);                //机器人左面

void robot_right(CASE case_state);               //机器人右面

void robot_hand_right(int x,int y,int theta);    //机器人的手，指向右侧，封装后在上面所述的几个函数中调用

void robot_hand_left(int x,int y,int theta);     //机器人的手，指向左侧，封装后在上面所述的几个函数中调用

void right_hold(CASE case_state);                //机器人手持物品向右走

void left_hold(CASE case_state);                 //机器人手持物品向左走

void front_hold(CASE case_state);               //机器人手持物品向下走（即正面）

void back_hold(CASE case_state);                //机器人手持物品向上走（即背面）

#endif

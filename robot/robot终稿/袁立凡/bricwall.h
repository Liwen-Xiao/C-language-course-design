#ifndef bricwall.h
#define bricwall.h

///地板砖
extern void wood_ver(int x, int y);//木质条纹地板

extern void glass(int x, int y);//浴室地砖

void green_kitchen(int x, int y);//厨房地砖

void green_bedroom(int x, int y);//卧室地砖

///	各种墙
void w_blue(int x, int y);  //正面看上去最大的那堵大墙

void w_right(int x,int y);	//在指定x，y代表的格子的右侧画墙壁

void w_left(int x, int y);//；	//在指定x，y代表的格子的左侧画墙壁

void w_down(int x, int y);	//在指定x，y代表的格子的下面画墙壁

#endif

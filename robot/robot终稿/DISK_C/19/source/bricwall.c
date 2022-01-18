#include "title.h"
#define YG 40
#define M 4
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define UP_DOWN 5
#define LEFT_RIGHT 6
/*****************************************************
地板瓷砖和墙壁
入口参数均为左上角坐标（40*40的大坐标）
******************************************************/

//客厅
void wood_ver(int x, int y)     //覆盖一个40*40的块
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,64908);		//	蜜橙色背景
	linever(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,1,31331);	//	五条竖线
	linever(x*YG+10,y*YG+M,(x+1)*YG+10,(y+1)*YG+M,1,31331); //隔十个像素点画一条
	linever(x*YG+20,y*YG+M,(x+1)*YG+20,(y+1)*YG+M,1,31331); //即40*40单位块上细分
	linever(x*YG+30,y*YG+M,(x+1)*YG+30,(y+1)*YG+M,1,31331);
	linever(x*YG+40,y*YG+M,(x+1)*YG+40,(y+1)*YG+M,1,31331);
}

//浴室
void glass(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,48797);		//	蓝色背景
	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+2,55070);	//	浅色边框
	bar(x*YG,y*YG+M,x*YG+2,(y+1)*YG+M,55070);
	bar(x*YG,(y+1)*YG+M-2,(x+1)*YG,(y+1)*YG+M,46651);			//	深色边框
	bar((x+1)*YG-2,y*YG+M,(x+1)*YG,(y+1)*YG+M,46651);

	bar(x*YG+2,y*YG+M+18,(x+1)*YG-2,y*YG+M+20,46651);			//中间十字
	bar(x*YG+2,y*YG+M+20,(x+1)*YG-2,y*YG+M+22,55070);
	bar(x*YG+18,y*YG+M+2,x*YG+20,(y+1)*YG+M-2,46651);
	bar(x*YG+20,y*YG+M+2,x*YG+22,(y+1)*YG+M-2,55070);
}

//	厨房
void green_kitchen(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,42552);		//	绿色背景

	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+1,31922);	//	深色边框
	bar(x*YG,y*YG+M,x*YG+1,(y+1)*YG+M,31922);
	bar(x*YG,(y+1)*YG+M-1,(x+1)*YG,(y+1)*YG+M,31922);
	bar((x+1)*YG-1,y*YG+M,(x+1)*YG,(y+1)*YG+M,31922);

	bar(x*YG+1,y*YG+M+19,(x+1)*YG-1,y*YG+M+20,31922);			//中间十字
	bar(x*YG+1,y*YG+M+20,(x+1)*YG-1,y*YG+M+21,31922);
	bar(x*YG+19,y*YG+M+1,x*YG+20,(y+1)*YG+M-1,31922);
	bar(x*YG+20,y*YG+M+1,x*YG+21,(y+1)*YG+M-1,31922);
}

//  卧室
void green_bedroom(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,65502);		//	白色背景
	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+2,52720);	//	深色边框
	bar(x*YG,y*YG+M,x*YG+2,(y+1)*YG+M,52720);
	bar(x*YG,(y+1)*YG+M-2,(x+1)*YG,(y+1)*YG+M,57010);			//	浅色边框
	bar((x+1)*YG-2,y*YG+M,(x+1)*YG,(y+1)*YG+M,57010);
}

//walls
//正面看上去最大的那堵大墙
void w_blue(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,42260);
	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+5,31625);
}

//在指定x，y代表的格子的右侧画墙壁
void w_right(int x,int y)           //w_开头的就是细细的边框
{                                   //right是在指定格子的右边画
	bar((x+1)*YG,y*YG+M,(x+1)*YG+4,(y+1)*YG+M,31625);
}

//在指定x，y代表的格子的左侧画墙壁
void w_left(int x, int y)           //left在指定格子的左边
{
	bar(x*YG,y*YG+M,x*YG+5,(y+1)*YG+M,31625);
}

void w_down(int x, int y)
{
	bar(x*YG,(y+1)*YG+M-2,(x+1)*YG,(y+1)*YG+M,31625);
}

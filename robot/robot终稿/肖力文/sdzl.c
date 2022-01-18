#include "title.h"
/*******************************************************************************************************************************************
函数列表：
    1.void  sdzl_main(int *x, int *y, int *button, CASE *robot, CASE *man, Graph G, int n, int times, int choice)   //选择具体哪种手动指令
    2.void water(CASE *robot, int x, int y, Graph G, int n, int times)      //给主人送水
********************************************************************************************************************************************/
/*
函数功能：对鼠标点击进行分析，选择不同种类的手动指令服务（打扫卫生，聊天，默认设置修改）
入口参数：*x，*y，*button是鼠标操作所需，*robot，*man分别是代表机器人和人的结构体指针，用于传给函数后续要用的aimmove
          图G和G的元素个数n也是寻路要用的，times和choice来自main2，分别表示目前表示的事件，以及人是否去了医院
*/
void  sdzl_main(int *x, int *y, int *button, CASE *robot, CASE *man, Graph G, int n, int times, int choice)
{
    int click=0;
	int wht_happen=0;
    iph_page_2();
    while (1)
    {
        newxy(x, y, button);//在新的位置画鼠标

        if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+54 && *y <=ORIGINY+171&& *button)    //打扫卫生
        {
            click=1;
			wht_happen=0;
			break;
        }
        if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+171 && *y <=ORIGINY+286&& *button)    //倒水
        {
            click=2;
			wht_happen=0;
			break;
        }
        if (*x>=ORIGINX && *x <=FINALX&& *y>=FINALY-30 && *y <=FINALY&& *button)    //返回主页面
        {
            click=3;
			wht_happen=0;
			break;
        }
    }
	if(wht_happen==0)
	{
		switch (click)
		{
			case 1:
			    if(times == 1 || times == 5)            //做饭时不能打扫卫生
                {
                    return;
                }
				clean(robot, man, G, n);
				wht_happen=1;
				break;

			case 2:
				water(robot, man->x, man->y, G, n, times, choice);   //送到人处
				wht_happen=1;
				break;

			if (click==3)
			{
			    mousehide(*x, *y);
				return ;
			}
		}
	}
}

/*
函数功能：送水，并且根据不同情况
入口参数：*robot是代表机器人的结构体指针，用于传给函数后续要用的aimmove
          图G和G的元素个数n也是寻路要用的，times和choice来自main2，分别
          表示目前表示的事件，以及人是否去了医院
*/
void water(CASE *robot, int x, int y, Graph G, int n, int times, int choice)    //入口是送水的终点，times是事件，来自time_line
{
    if(times==-1 || times == 0 || times == 1 || times == 5 || choice)            //人还没回家，或者做饭时，或者经过treatment以后去了医院，都不能送水
    {
        return;
    }

    aimmove(robot, robot->x, robot->y, 14.5, 2, G, n, ROBOT);//移动到水杯处
    robot->catch_th = WITH_BOTTLE;   //拿水杯，改变了这个量以后，画图就用fore_hold等持水杯的函数了
	water_dispenser(15, 1);          //重画饮水机，原来的上面覆盖有水杯，现在水杯被拿走了，画空的饮水机

	//人工作时送水送到电脑桌
	if(x == 2 && y == 15)
	{
	    aimmove(robot, robot->x, robot->y, 2, 15, G, n, ROBOT);   //走到电脑桌旁
	}
	else if(x == 2 && y == 10)      //人在睡觉
    {
        aimmove(robot, robot->x, robot->y, 2, 8, G, n, ROBOT);   //走到床头
        water_bottle(3*40+5, 8*40);                //水杯放在床头的桌上
    }
    else
    {
        aimmove(robot, robot->x, robot->y, x, y, G, n, ROBOT);   //走到人所在的地方
    }

	robot->catch_th = WITHOUT_THING;    //手上没东西了
	aimmove(robot, robot->x, robot->y, 13, 3, G, n, ROBOT);      //回到常待的点
}

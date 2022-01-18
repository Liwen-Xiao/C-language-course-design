/********************************
系统主进程，调用各种功能
void mainprocess(int *x,int *y);
********************************/
#include "title.h"
void mainprocess(int *x,int *y, int *pbutton)
{
	int button=*pbutton;    //鼠标按键
	int click=0;            //手动指令模块选择判断变量
	int i;
	int judge=0;            //时间线模块选择判断变量
	int temp;				//用于存储键盘输入。用于esc的点击

	int air_t=24;			//空调温度初始化
	int bath_t=38;			//洗澡水温初始化

	int n;
	VType G[166];           //后期计算发现，只有不到166个点可走

	int time=15*60;			//时间初始化
	int hour;
	int minute;
	char s_hour[3];			//小时的字符串数组
	char s_minute[3];		//分钟的字符的数组
	int times=-1;  			//事件是什么
	int wht_happen=0;		//事件是否发生        *********作用：当时间线上的函数执行过一遍之后这个变量就变成1，在循环中就不会无限调用该函数
	int wht_happen2=0;		//事件是否发生        *********作用：当手动指令上的函数执行过一遍之后这个变量就变成1，在循环中就不会无限调用该函数

    int choice[5]={0};		//选择数组定义及其初始化

	CASE robot,man;  		//人和机器人的变量的初始化

	BUTTONS esc1;			//退出按钮
	esc_init(&esc1);		//退出按钮初始化
	mouseInit(x, y,&button);//鼠标初始化

	n = CreateGraph(G);    //建图


    //初始化机器人位置方向，四肢状态
	robot.x = 13;
	robot.y = 3;
	robot.direction = 4;

	robot.hand = 0;
	robot.hand_left = 0;
	robot.hand_right = 0;
	robot.xpixel=robot.x*40;
	robot.ypixel=robot.y*40;



	//初始化人位置方向，四肢状态
	man.x = 4;
	man.y = 1;
	man.direction = 4;
	man.hand = 0;
	man.hand_left = 0;
	man.hand_right = 0;
	man.xpixel=man.x*40;
	man.ypixel=man.y*40;

    //绘制地图，手机主界面
	mousehide(*x,*y);
	paint_house();							//画房子
	iph_page_1();							//手机主界面
	time_page();							//时间静态界面
	hour=time/60;							//小时
	minute=time%60;							//分钟
	itoa(hour,s_hour,10);					//小时的信息存入字符串数组
	itoa(minute,s_minute,10);				//分钟的信息存入字符串数组
	minute_adjust(s_minute);				//分钟全部调为2位数
	outtextxy(810,615,s_hour,3,3,20,0);
	outtextxy(874,607,":",3,3,0,0);
	outtextxy(920,615,s_minute,3,3,20,0);	    //时间静态界面

	paint_robot(robot);						//画机器人

	//重置鼠标
	reset_mouse(x,y);

	while(1)
	{

		newxy(x,y,&button);					//刷新鼠标位置和状态

		//检查是否点击退出按钮
		judge = esc_check(&esc1,x,y,&button);
		
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}



		if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+54 && *y <=ORIGINY+209&& button)    //手动指令按钮
        {
            click=1;
			wht_happen2=0;
        }

        if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+209 && *y <=ORIGINY+363&& button)   //聊天按钮
        {
            click=2;
			wht_happen2=0;
        }
        if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+363 && *y <=ORIGINY+515&& button)   //默认设置修改按钮
        {
            click=3;
			wht_happen2=0;
        }
        if (*x>=0 && *x <=20&& *y>=0 && *y <=20&& button)                                //退出按钮
        {
            click=4;
        }
        if (*x>=764 && *x <=1020&& *y>=690 && *y <=764&& button)
        {
			time_adjust_plus(&time, &times, &wht_happen);	//时间随事件调整
            hour=time/60;
            minute=time%60;
            itoa(hour,s_hour,10);
            itoa(minute,s_minute,10);
			minute_adjust(s_minute);

            bar(794,597,990,665,65535);//时间显示框
            outtextxy(810,615,s_hour,3,3,20,0);
			outtextxy(874,607,":",3,3,0,0);
			outtextxy(920,615,s_minute,3,3,20,0);
        }



        if (wht_happen==0 && times==0)
        {
            rbtguard(man, robot, INTRADER, x, y, &button); 			//安保功能实现
            wht_happen=1;
        }
        if (wht_happen==0 && times==1)
        {
			iph_page_1();
            come_home(&robot, &man, x, y, &button, choice,G, n);	//回家后功能实现
            wht_happen=1;
        }
        if (wht_happen==0 && times==2)
        {
            dinner(&robot, &man, x, y, &button, choice,G, n);		//晚饭功能实现
            wht_happen=1;
        }
        if (wht_happen==0 && times==3)
        {
            bath(&robot, &man, x, y, &button, choice,G, n);			//洗澡功能实现
            wht_happen=1;
        }
        if (wht_happen==0 && times==4)
        {
            treatment(&man, &robot, G, n, x, y, &button, choice);			//生病救援功能实现
            wht_happen=1;
        }
        if (wht_happen==0 && times==5  && choice[4]==0)  			//choice[4]==0表示没有去医院
        {
            breakfast(&robot, &man, G, n);			//早餐功能实现
			wht_happen=1;
        }
		if (times==6)
		{
			good_bye();												//结束界面
		}


		if (wht_happen2==0)
		{
			switch(click)
			{
				case 0:
				{
					break;
				}
				//手动指令
				case 1:
				{
					sdzl_main(x,y,&button,&robot,&man, G, n, times, choice[4]);  	 //进入手动指令功能函数
					iph_page_1();							  	 //退出手动指令后画主界面
					wht_happen2=1;							  	 //已经跑了一遍，避免一直循环
					break;
				}
				//聊天功能
				case 2:
				{
					chatmain(&robot);							//进入聊天界面
					//click=0;
					iph_page_1();								//退出聊天后画主界面
					wht_happen2=1;								//已经跑了一遍，避免一直循环
					break;
				}
				//默认设置修改
				case 3:
				{
					set_change(&air_t, &bath_t);				//进入默认设置修改界面
					//click=0;
					iph_page_1();								//退出默认设置修改后画主界面
					wht_happen2=1;								//已经跑了一遍，避免一直循环
					break;
				}
			}
		}
		//若点击退出系统，则跳出循环
		if(judge==4)
		{
			break;
		}
    }

}

//功能：将一位数字的分钟数调整成2位数字
void minute_adjust(char *s_minute)
{
	if(strcmp(s_minute,"0")==0)
		strcpy(s_minute,"00");
	if(strcmp(s_minute,"1")==0)
		strcpy(s_minute,"01");
	if(strcmp(s_minute,"2")==0)
		strcpy(s_minute,"02");
	if(strcmp(s_minute,"3")==0)
		strcpy(s_minute,"03");
	if(strcmp(s_minute,"4")==0)
		strcpy(s_minute,"04");
	if(strcmp(s_minute,"5")==0)
		strcpy(s_minute,"05");
	if(strcmp(s_minute,"6")==0)
		strcpy(s_minute,"06");
	if(strcmp(s_minute,"7")==0)
		strcpy(s_minute,"07");
	if(strcmp(s_minute,"8")==0)
		strcpy(s_minute,"08");
	if(strcmp(s_minute,"9")==0)
		strcpy(s_minute,"09");
}

//功能：根据事件来调整时间
void time_adjust_plus(int *time, int *times, int *wht_happen)
{
	(*times)++;
	*wht_happen=0;
	if (*times==0)				//当事件为0，则说明是16点，调整相应时间
	{
		*time=60*16;
	}
	if (*times==1)				//当事件为1，则说明是18点，调整相应时间
	{
		*time=60*18;
	}
	if (*times==2)				//当事件为2，则说明是18点半，调整相应时间
	{
		*time=60*18+30;
	}
	if (*times==3)				//当事件为3，则说明是21点，调整相应时间
	{
		*time=60*21;
	}
	if (*times==4)				//当事件为4，则说明是1点，调整相应时间
	{
		*time=1*60;
	}
	if (*times==5)				//当事件为5，则说明是6点，调整相应时间
	{
		*time=6*60;
	}
}

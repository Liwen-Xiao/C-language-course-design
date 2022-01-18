/******************函数清单***************************
1.  void show_order(int *qhwh,int *y);
2.	void get_str(int *qhwh, char *incode);
3.	void reply_match(char * str,char *order,char *reply);
4.	void show_reply(char *incode, int * y);
5.	void show_main(int *qhwh);
*****************************************************/
#include "title.h"



/**************

	打印命令

**************/
void show_order(int *qhwh,int *y)
{
	int num_qhwh;	//字符数
	int num_line;	//需打印的行数
	int box_top;	//输入框上沿

	Area order_box;
	Coordinate order_begin;

	/***************
	检查有几个字并画对话框底
	***************/
	num_qhwh = CheckQhwhNum(qhwh);	//得到字符数
	num_line = num_qhwh/10+1;		//确认打印行数
	box_top = 345-20*num_line;		//确认对话框上沿

	if(num_qhwh<=10)
	{
		bar_round_2(ORIGINX+239-num_qhwh*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);   //打印对话框
	}
	else
	{
		bar_round_2(ORIGINX+239-10*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);
	}

	/***************
	打印汉字并打印用户姓名
	***************/
	if(num_qhwh<=10)
	{
		order_box.lt.x = ORIGINX+239-num_qhwh*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-num_qhwh*16;
		order_begin.y = ORIGINY+box_top+2;

		ShowTxt(qhwh, order_box, &order_begin,16);
	}
	else{
		order_box.lt.x = ORIGINX+239-10*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-10*16;
		order_begin.y = ORIGINY+box_top+2;

		ShowTxt(qhwh, order_box, &order_begin,16);
	}

	fdhz(ORIGINX+243-16*2,ORIGINY+box_top-20,1,1,"主",65535);
	fdhz(ORIGINX+243-16*1,ORIGINY+box_top-20,1,1,"人",65535);

	/*************
	改变回复区域的占位记录值
	*************/
	//*y = ORIGINY+box_top-25;
	*y = ORIGINY+50+20*num_line+25;
}

/**************

	真正得到用户输入的字符串

**************/
void get_str(int *qhwh, char *incode)
{
	char *p=incode;	//incode的位置指针
	int num_qhwh = CheckQhwhNum(qhwh);
	int i;

	for(i=0;i<num_qhwh;i++)
	{
		qhwh2incode(*qhwh,p);
		p+=2;
		qhwh++;
	}
	*p = 0;
	*(p+1)=0;
}


void reply_match(char * str,char *reply, CASE* robot)
{
	int k;
	char *t_str=str;
	srand((unsigned int)time(0));
	while (*t_str!=0)                                           
	{
		if (!strncmp(t_str,"吃",2))
		{
			k=rand()%4;
			if (k==0)
				reply="火锅怎么样";
			else if (k==1)
				reply="我觉得还是牛排最好吃";
			else if (k==2)
				reply="还是推荐蔬菜沙拉";
			else if (k==3)
				reply="你都这么胖了还想吃";
		}
		else if (!strncmp(t_str,"气",2))
		{
			k=rand()%4;
			if (k==0)
				reply="阳光明媚，适合泡妹";
			else if (k==1)
				reply="外面下着小雨，建议出门带伞";
			else if (k==2)
				reply="大暴雨，还是开车吧";
			else if (k==3)
				reply="阴天，凉爽舒适，是个户外运动的好日子";
		}
		else if (!strncmp(t_str,"你",2))
		{
			k=rand()%3;
			if (k==0)
				reply="我是靠谱的智能机器人，让我来协助你生活是个明智的选择";
			else if (k==1)
				reply="我是智能机器人，请放心地将你的生活交给我";
			else if (k==2)
				reply="我是一个体贴的机器人，而且很智能";
		}
		else if (!strncmp(t_str,"游",2))
		{
			k=rand()%3;
			if (k==0)
				reply="我不具有游戏功能，去蒸汽游戏平台吧";
			else if (k==1)
				reply="你玩游戏玩得太多啦，今天还是歇歇吧";
			else if (k==2)
				reply="听说最近他们都在玩吃鸡呢，你要去试试吗？";
		}
		else if (!strncmp(t_str,"人",2))
		{
			k=rand()%1;
			if (k==0)
				reply="除了你我只认识肖力文和袁立凡他们是所有人里最帅的";
		}
		else
			reply=NULL;
		t_str+=2;
		if (reply!=NULL)
		{
			saveimage_chat(robot->x*40+40,robot->y*40);
			show_reply(reply,robot);	//开始显示回复消息
			getch();
			putsave_chat(robot->x*40+40,robot->y*40);
		}
		reply=NULL;
	}
	if (no_keyword(str))
	{
		reply="嗯嗯";
        saveimage_chat(robot->x*40+40,robot->y*40);
        show_reply(reply,robot);	//开始显示回复消息
        getch();
        putsave_chat(robot->x*40+40,robot->y*40);
	}
}


void show_reply(char *incode,CASE* robot)
{
	int x=robot->x*40+40+10,y;	//打印回复汉字的位置
	int box_top;	//对话框底顶部的纵坐标
	int i;			//temp
	int num_word=0;	//需要回复的字数
	int num_line;	//回复几行
	char *p_incode=incode;	//incode的位置指针

	//检查有几个字
	while(*p_incode!=NULL)
	{
		p_incode+=2;
		num_word++;
	}


	//画对话框底
	
	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+240,robot->y*40+80,5,2,65535);

	//打印回复的汉字
	
	i = 0;	//作字数标记
	y = robot->y*40+5;
	while(*incode!=NULL)
	{
		while( (i<10)&&(*incode!=NULL) )
		{
			dishz(x,y,1,1,incode,0);
			i++;
			x+=16*1;
			incode+=2;
		}
		i=0;
		x=robot->x*40+40+10;
		y+=20*1;
	}


}




void show_main(int *qhwh, CASE* robot)
{
	int num_qhwh;	//统计输入的字符数量
	int begin_y;	//标记每次对话框输出时的顶端y坐标以确定putimage的范围
	char *reply =NULL;	//之后标记到文件中的答句部分
	char incode[30] ={0};

	//显示用户输入部分
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1,ORIGINY+345+1);
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,54938);	//清空要显示用户输入消息的区域
	show_order(qhwh,&begin_y);	//开始显示用户输入消息
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);

	delay(500);	//等待机器人回复

	//显示机器人回复部分
	//寻找匹配句
	get_str( qhwh, incode);
	reply_match( incode, reply,robot);
}

int no_keyword(char *str)
{
	int p=1;
	char *t_str=str;
	while (*t_str!=0)
	{
		if (!strncmp(t_str,"吃",2)  ||  !strncmp(t_str,"气",2)  ||  !strncmp(t_str,"你",2)  ||  !strncmp(t_str,"游",2)  ||  !strncmp(t_str,"人",2)  )
			p=0;
		t_str+=2;
	}
	return  p;
}


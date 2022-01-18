#include "title.h"

/***************************************************
错误提示模块及组件
void overflow_box(int x,int y);
void null_box(int x,int y);
void space_box(int x,int y);
void phone_module(int x,int y);
void phone_back(int x,int y);
void gg_bar();
void FindWay_error(int x,int y);
void trap(int x,int y);
void pop_error(int x,int y);
***************************************************/

/**************************************************
这个文件里面有用栈实现的部分，要改成用图
**************************************************/



void overflow_box(int x,int y)//当malloc分配空间失败时提示，回车退出系统
{
	bar(x-350,y-100,x+350,y-70,255);
	bar(x-350,y-70,x+350,y+100,46651);
	bar_round(x+335,y-85,28,28,2,1,63488);

	fdhz(x-75,y+10,2,2,"内",0);
	fdhz(x-30,y+10,2,2,"存",0);
	fdhz(x+15,y+10,2,2,"溢",0);
	fdhz(x+60,y+10,2,2,"出",0);

	fdhz(x-75,y+53,2,2,"回",0);
	fdhz(x-45,y+53,2,2,"车",0);
	fdhz(x,y+53,2,2,"以",0);
	fdhz(x+45,y+53,2,2,"退",0);
	fdhz(x+75,y+53,2,2,"出",0);
}

void null_box(int x,int y)//当找不到相应文件路径时显示，回车退出系统
{
	bar(x-350,y-100,x+350,y-70,255);
	bar(x-350,y-70,x+350,y+100,46651);
	bar_round(x+335,y-85,28,28,2,1,63488);

	fdhz(x-115,y-20,2,2,"找",0);
	fdhz(x-75,y-20,2,2,"不",0);
	fdhz(x-30,y-20,2,2,"到",0);
	fdhz(x+15,y-20,2,2,"该",0);
	fdhz(x+60,y-20,2,2,"路",0);
	fdhz(x+100,y-20,2,2,"径",0);


	fdhz(x-75,y+23,2,2,"回",0);
	fdhz(x-45,y+23,2,2,"车",0);
	fdhz(x,y+23,2,2,"以",0);
	fdhz(x+45,y+23,2,2,"退",0);
	fdhz(x+75,y+23,2,2,"出",0);
}

void space_box(int x,int y)//显示堆区当前可分配空间
{
    unsigned long i,ki;
	int mi,gi;
	char a[8];          //a是以b为单位的数值，ki是k为单位的数值，mi是M为单位的数值，gi是G
	i = coreleft();
	ki = i/1024;
	mi = ki/1024;
	gi = mi/1024;
	if(gi)
	{
		itoa(gi,a,10);
	    bar(x-350,y-100,x+350,y-70,255);
	    bar(x-350,y-70,x+350,y+100,46651);
	    bar_round(x+335,y-85,28,28,2,1,63488);
	    fdhz(x-135,y+10,2,2,"剩余内存：",0);
	    outtextxy(x+100,y+10,&a,1,1,10,0);
	    outtextxy(x+300,y+10,"G",1,1,10,0);
	    fdhz(x-75,y+53,2,2,"回",0);
	    fdhz(x-45,y+53,2,2,"车",0);
	    fdhz(x,y+53,2,2,"以",0);
	    fdhz(x+45,y+53,2,2,"退",0);
	    fdhz(x+75,y+53,2,2,"出",0);
	}
	else
	{
		if(mi)
		{
			itoa(mi,a,10);
	        bar(x-350,y-100,x+350,y-70,255);
	        bar(x-350,y-70,x+350,y+100,46651);
	        bar_round(x+335,y-85,28,28,2,1,63488);
	        fdhz(x-135,y+10,2,2,"剩余内存：",0);
	        outtextxy(x+100,y+10,&a,1,1,10,0);
	        outtextxy(x+300,y+10,"M",1,1,10,0);
	        fdhz(x-75,y+53,2,2,"回",0);
	        fdhz(x-45,y+53,2,2,"车",0);
	        fdhz(x,y+53,2,2,"以",0);
	        fdhz(x+45,y+53,2,2,"退",0);
	        fdhz(x+75,y+53,2,2,"出",0);
		}
		else
		{
			if(ki)
			{
				itoa(ki,a,10);
	            bar(x-350,y-100,x+350,y-70,255);
	            bar(x-350,y-70,x+350,y+100,46651);
	            bar_round(x+335,y-85,28,28,2,1,63488);
	            fdhz(x-135,y+10,2,2,"剩余内存：",0);
	            outtextxy(x+100,y+10,&a,1,1,10,0);
	            outtextxy(x+300,y+10,"k",1,1,10,0);
	            fdhz(x-75,y+53,2,2,"回",0);
	            fdhz(x-45,y+53,2,2,"车",0);
	            fdhz(x,y+53,2,2,"以",0);
	           fdhz(x+45,y+53,2,2,"退",0);
	            fdhz(x+75,y+53,2,2,"出",0);
			}
			else
			{
				itoa((int)i,a,10);
	            bar(x-350,y-100,x+350,y-70,255);
	            bar(x-350,y-70,x+350,y+100,46651);
	            bar_round(x+335,y-85,28,28,2,1,63488);
	            fdhz(x-135,y+10,2,2,"剩余内存：",0);
	            outtextxy(x+100,y+10,&a,1,1,10,0);
	            outtextxy(x+300,y+10,"b",1,1,10,0);
	            fdhz(x-75,y+53,2,2,"回",0);
	            fdhz(x-45,y+53,2,2,"车",0);
	            fdhz(x,y+53,2,2,"以",0);
	            fdhz(x+45,y+53,2,2,"退",0);
	            fdhz(x+75,y+53,2,2,"出",0);
			}
		}
	}


}


void phone_module(int x,int y)//手机功能模块外框
{
	bar_round_with_shadow(x,y,120,120,30,1,1788);
}
/*home键不想要了，改*/
void phone_back(int x,int y)//home键
{
	FillCircle(x,y,40,65535);
    circle(x,y,35,0);
	circle(x,y,40,0);
}

void gg_bar()
{
	bar(0,0,1024,768,65535);
	fdhz(200,200,3,3,"啥也没有，再见",0);
	getch();
	exit(1);
}

void FindWay_error(int x,int y)//寻路失败提示（退出）
{
	bar(x-350,y-100,x+350,y-70,255);
	bar(x-350,y-70,x+350,y+100,46651);
	bar_round(x+335,y-85,28,28,2,1,63488);
	fdhz(x-115,y-20,2,2,"寻",0);
	fdhz(x-75,y-20,2,2,"找",0);
	fdhz(x-30,y-20,2,2,"路",0);
	fdhz(x+15,y-20,2,2,"径",0);
	fdhz(x+60,y-20,2,2,"出",0);
	fdhz(x+100,y-20,2,2,"错",0);

	fdhz(x-75,y+23,2,2,"回",0);
	fdhz(x-45,y+23,2,2,"车",0);
	fdhz(x,y+23,2,2,"以",0);
	fdhz(x+45,y+23,2,2,"退",0);
	fdhz(x+75,y+23,2,2,"出",0);
}

void trap(int x,int y)//被障碍物挡住提示
{
	bar(x-350,y-100,x+350,y-70,255);
	bar(x-350,y-70,x+350,y+100,46651);
	bar_round(x+335,y-85,28,28,2,1,63488);
	fdhz(x-50,y-70,2,2,"被挡住了",0);
	fdhz(x-115,y,2,2,"请移开障碍物",0);
	fdhz(x-75,y+30,2,2,"回车以继续",0);
}
/*改成图的，别用栈了*/
void pop_error(int x,int y)//弹出栈顶元素失败（栈空）
{
	bar(x-350,y-100,x+350,y-70,255);
	bar(x-350,y-70,x+350,y+100,46651);
	bar_round(x+335,y-85,28,28,2,1,63488);
	fdhz(x-50,y-30,2,2,"栈已为空",0);
	fdhz(x-115,y,2,2,"取栈顶失败",0);


	fdhz(x-75,y+23,2,2,"回",0);
	fdhz(x-45,y+23,2,2,"车",0);
	fdhz(x,y+23,2,2,"以",0);
	fdhz(x+45,y+23,2,2,"退",0);
	fdhz(x+75,y+23,2,2,"出",0);
}


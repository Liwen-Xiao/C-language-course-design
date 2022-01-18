#include "title.h"

//功能：默认设置修改函数
//输入：空调温度和水温的指针
//输出：无
void set_change(int *air_t, int *bath_t)
{
	int x,y,button; 		//鼠标的变量
	char at[3]={0};			//空调温度字符串
	char bt[3]={0};			//洗澡水温字符串
	mouseInit(&x, &y,&button); //鼠标初始化
	mousehide(x,y);			//隐藏鼠标
	reset_mouse(&x,&y);		//设置鼠标
	itoa(*air_t,at,10);		//将空调温度转换成字符串
	itoa(*bath_t,bt,10);	//将洗澡水温度转换成字符串
	iph_page_4(at,bt);		//画默认设置修改界面
	while(1)
	{
		newxy(&x,&y,&button);//刷新鼠标
		if (x>=FINALX-120 && y>=ORIGINY+136  &&  x<=FINALX-95  &&  y<=ORIGINY+161  &&  button)  //点击了空调温度减温
		{
			if (*air_t>=16)
			{
				(*air_t)--;
				itoa(*air_t,at,10);
				iph_page_4(at,bt);
			}
		}
		if (x>=FINALX-35 && y>=ORIGINY+136  &&  x<=FINALX-10  &&  y<=ORIGINY+161  &&  button)  //点击了空调温度升温
		{
			if (*air_t<=30)
			{
				(*air_t)++;
				itoa(*air_t,at,10);
				iph_page_4(at,bt);
			}
		}
		if(x>=FINALX-120 && y>=ORIGINY+251  &&  x<=FINALX-95  &&  y<=ORIGINY+276  &&  button )  //点击了洗澡水温温度减温
		{
			if (*bath_t>=25)
			{
				(*bath_t)--;
				itoa(*bath_t,bt,10);
				iph_page_4(at,bt);
			}
		}
		if(x>=FINALX-35 && y>=ORIGINY+251  &&  x<=FINALX-10  &&  y<=ORIGINY+276  &&  button )	//点击了洗澡水温升温
		{
			if (*bath_t<=50)
			{
				(*bath_t)++;
				itoa(*bath_t,bt,10);
				iph_page_4(at,bt);
			}
		}
		if(x>=ORIGINX && y>=FINALY-30  &&  x<=FINALX  &&  y<=FINALY  &&  button )
			break;
	}
}
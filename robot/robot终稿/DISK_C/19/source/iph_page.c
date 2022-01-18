#include "title.h"



//功能：手机外框等固定元素，任何界面都需要显示
void iph_frame()
{
	bar_round_2(ORIGINX,ORIGINY,FINALX,FINALY,30,1,65534);
	linelevel(ORIGINX+30,2,FINALX-30,2,2,0);
	linelevel(ORIGINX+30,FINALY,FINALX-30,547,2,0);
	linever(ORIGINX,ORIGINY+30,ORIGINX,FINALY-30,2,0);
	linever(FINALX,ORIGINY+30,FINALX,FINALY-30,2,0);
	bow_left_down(ORIGINX+30,FINALY-30,31,0);
	bow_left_down(ORIGINX+30,FINALY-30,32,0);
	bow_left_up(ORIGINX+30,ORIGINY+30,31,0);
	bow_left_up(ORIGINX+30,ORIGINY+30,32,0);
	bow_right_down(FINALX-30,FINALY-30,31,0);
	bow_right_down(FINALX-30,FINALY-30,32,0);
	bow_right_up(FINALX-30,ORIGINY+30,31,0);
	bow_right_up(FINALX-30,ORIGINY+30,32,0);
	bar (MIDDLEX-6,4,MIDDLEX+6,9,0);
	FillCircle(MIDDLEX,9,6,0);
	FillCircle(MIDDLEX,9,2,4523);												//	RGB＿0 52 91
	//	信号&电源
	bar(FINALX-52,24,FINALX-49,32,0);
	bar(FINALX-48,21,FINALX-45,32,0);
	bar(FINALX-44,18,FINALX-41,32,0);
	bar(FINALX-40,15,FINALX-37,32,0);																//	RGB: 10 10 10
	bar_round(FINALX-20,21,20,12,2,1,0);

}

//功能：手机界面附加元素
void iph_frame_plus()
{
    linelevel(ORIGINX,ORIGINY+56,FINALX,ORIGINY+56,1,0);                                   //页面名称
    bar_round_2(ORIGINX,ORIGINY,FINALX,ORIGINY+56,30,1,54938);
    bar(ORIGINX,ORIGINY+26,FINALX,ORIGINY+56,54938);
    bar (MIDDLEX-6,ORIGINY,MIDDLEX+6,ORIGINY+5,0);
	FillCircle(MIDDLEX,ORIGINY+5,6,0);
	FillCircle(MIDDLEX,ORIGINY+5,2,4523);
	bar(FINALX-52,24,FINALX-49,32,0);
	bar(FINALX-48,21,FINALX-45,32,0);
	bar(FINALX-44,18,FINALX-41,32,0);
	bar(FINALX-40,15,FINALX-37,32,0);																//	RGB: 10 10 10
	bar_round(FINALX-20,21,20,12,2,1,0);
}

//功能：手机主界面
void iph_page_1()
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-30,ORIGINY+18,1,1,"主界面",0);

	linelevel(ORIGINX,ORIGINY+209,FINALX,ORIGINY+209,1,0);                           //手动指令按钮
	fdhz(MIDDLEX-80,ORIGINY+116,2,2,"手动指令",0);

	linelevel(ORIGINX,ORIGINY+363,FINALX,ORIGINY+363,1,0);
	fdhz(MIDDLEX-40,ORIGINY+269,2,2,"聊天",0);                               //聊天按钮

	linelevel(ORIGINX,ORIGINY+515,FINALX,ORIGINY+515,1,0);                          //默认设置修改按钮
	fdhz(MIDDLEX-120,ORIGINY+422,2,2,"默认设置修改",0);
}

//功能：手动指令界面
void iph_page_2()                                                                   //手动指令界面
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-40,ORIGINY+18,1,1,"手动指令",0);

	linelevel(ORIGINX,ORIGINY+171,FINALX,ORIGINY+171,1,0);                         //打扫卫生按钮
	fdhz(MIDDLEX-80,ORIGINY+116,2,2,"打扫卫生",0);

	linelevel(ORIGINX,ORIGINY+286,FINALX,ORIGINY+286,1,0);
	fdhz(MIDDLEX-60,ORIGINY+231,2,2,"倒水",0);

}

//功能：聊天界面
void iph_page_3()                                                    //聊天界面
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-20,22,1,1,"聊天",0);

	/***************
	输入框
	**************/
	bar_round_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+468,5,1,54938);
	bar_round_2(ORIGINX+13,ORIGINY+363,ORIGINX+243,ORIGINY+468,5,1,65535);
	bar(ORIGINX+13,ORIGINY+384,ORIGINX+243,ORIGINY+403,48631);		//191 191 191

	saveimage_box(ORIGINX+25, ORIGINY+365);

	/********
	界面背景
	********/
	FillCircle(ORIGINX+200,ORIGINY+157,40,54938);	//138 198 210
	fill_bow_right_up(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	fill_bow_right_down(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204


}

//功能：默认设置修改界面
void iph_page_4(char *at,char *bt)                                             //默认设置修改界面
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-60,ORIGINY+18,1,1,"默认设置修改",0);

    fdhz(MIDDLEX-100,ORIGINY+138,1,1,"空调温度",0);
    bar(FINALX-120,ORIGINY+136,FINALX-95,ORIGINY+161,33808);//900，140，925，165   减号
    bar(FINALX-117,ORIGINY+146,FINALX-98,ORIGINY+151,65535);

    bar(FINALX-85,ORIGINY+128,FINALX-45,ORIGINY+168,65535);  //温度显示区域
    outtextxy(FINALX-75,ORIGINY+138,at,1,1,10,0);

    bar(FINALX-35,ORIGINY+136,FINALX-10,ORIGINY+161,33808); //加号
    bar(FINALX-32,ORIGINY+146,FINALX-13,ORIGINY+151,65535);
    bar(FINALX-25,ORIGINY+139,FINALX-20,ORIGINY+158,65535);

    fdhz(MIDDLEX-100,ORIGINY+253,1,1,"洗澡水温",0);
    bar(FINALX-120,ORIGINY+251,FINALX-95,ORIGINY+276,33808);//900，140，925，165   减号
    bar(FINALX-117,ORIGINY+261,FINALX-98,ORIGINY+266,65535);

    bar(FINALX-85,ORIGINY+243,FINALX-45,ORIGINY+283,65535);  //温度显示区域
    outtextxy(FINALX-75,ORIGINY+253,bt,1,1,10,0);

    bar(FINALX-35,ORIGINY+251,FINALX-10,ORIGINY+276,33808); //加号
    bar(FINALX-32,ORIGINY+261,FINALX-13,ORIGINY+266,65535);
    bar(FINALX-25,ORIGINY+254,FINALX-20,ORIGINY+273,65535);
}

//功能：时间界面
void time_page()
{
    bar(764,572,1020,764,50712);//银色大框
    linelevel(764,690,1020,690,3,0);
    bar(794,597,990,665,65535);//时间显示框
    fdhz(894-40,727-8,1,1,"下一事件",0);
}

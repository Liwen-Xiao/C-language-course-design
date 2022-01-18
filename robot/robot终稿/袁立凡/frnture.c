#include "title.h"
/*************************************************************************************
该源文件中存放所有家具的源代码
入口参数：1. 均为都是要画的地方的左上角，但很多函数中都有根据具体情况赋予一定的偏移量
           2. 为寻路方便，大部分家具的入口参数是40*40的大坐标，刚好占据一个block坐标块
           3. 很多函数里的 x *= 40 和 y *= 40的操作都是将大坐标转化为小坐标。入口是像素点小坐标的部分会额外强调
函数列表：     void trashbin(int x,int y)      //垃圾桶
                void bed(int x,int y)           //床
                void window_close(int x,int y)      //窗户
                void cupboard(int x,int y)          //衣柜
                void aircon(int x,int y,int open)   //空调
                void WashMach(int x,int y)          //40*40，洗衣机
                void bookshelf(int x,int y)         //40*80，书架
                void desk(int x,int y)              //80*40，小方桌
                void seat(int x,int y)              //40*40，小板凳
                void trash1(int x,int y)            //40*40，纸张
                void trash2(int x,int y)            //40*40，菜叶
                void trash3(int x,int y)            //40*40，果核
                void pc(int x,int y)                //电脑
                void TV(int x,int y)                //电视
                void rect_table(int x,int y)        //条纹方卓
                void sofa_main(int x, int y)        //沙发主要部分
                void sofa_up(int x, int y)          //沙发，屏幕上面的那组
                void sofa_down(int x, int y)        //沙发，屏幕下面的那组
                void toilet(int x, int y)           //40*40，马桶
                void water_dispenser(int x, int y)  //40*80，饮水机
                void zaotai(int x, int y)           //灶台
                void water_bottle(int x, int y)     //水杯，入口是像素点小坐标
                void clothes(int x, int y)          //衣服（机器人去衣柜拿到浴室）
                void plate(int x,int y)             //盘子
                void medical_kit(int x, int y)      //医疗包
                void TV_on(void)                    //电视打开状态
                void TV_off(void)                   //电视关闭（和上面TV的不同之处是，要做额外绘画去恢复客厅模样）
                void music_on(int x, int y)         //音符
                void music_off( int x, int y)       //去除音符
**************************************************************************************/

void trashbin(int x,int y)      //垃圾桶，入口参数是垃圾桶的左上角
{
	x = x*40;
	y = y*40+4;
	bar(x+15,y,x+35,y+40,65187);
	ever_Fillellipse(x+23,y,x+27,y,8,65187);
	ever_Fillellipse(x+23,y,x+27,y,6,0);
	ever_Fillellipse(x+23,y,x+27,y,5,65535);
}

void bed(int x,int y)       //床
{
	x = x*40+10;            //为防止图像溢出屏幕，多给10个偏移量
	y = y*40+4+30;          //+30
	theta_bar(x-5,y-48,30,4,-45,62604);
	theta_bar(x+20,y-50,32,4,45,62604);
	lean_line(x,y-48,4,-45,0);
	lean_line(x+48,y-50,4,45,0);
	bar(x-5,y-48,x+55,y-32,52263);
	bar(x-5,y-32,x+55,y+42,65535);
	bar(x+4,y-35,x+46,y-15,0);
	bar(x+5,y-35,x+45,y-15,65535);
	fill_bow_right_down(x+25,y-48,20,52263);
	fill_bow_left_down(x+25,y-48,20,52263);
	fill_bow_up(x+25,y+21,43,64950);
	bar(x-3,y-7,x+53,y+10,64950);
	fill_bow_up(x+25,y+28,40,65535);
	bar(x-4,y,x+54,y+42,0);
	bar(x-3,y,x+53,y+42,65535);
	bar(x-5,y+53,x+2,y+59,52263);
	bar(x+48,y+53,x+55,y+59,52263);
	bar(x-5,y+42,x+55,y+55,44373);
	bar(x-5,y+42,x+2,y+55,57083);
	bar(x+11,y+42,x+18,y+55,57083);
	bar(x+32,y+42,x+39,y+55,57083);
	bar(x+48,y+42,x+55,y+55,57083);
	linelevel(x-3,y+42,x+53,y+42,3,42260);
	linever(x+2,y+45,x+2,y+55,1,0);
	linever(x+11,y+45,x+11,y+55,1,0);
	linever(x+18,y+45,x+18,y+55,1,0);
	linever(x+32,y+45,x+32,y+55,1,0);
	linever(x+39,y+45,x+39,y+55,1,0);
	linever(x+48,y+45,x+48,y+55,1,0);
	fill_bow_down(x-2,y+53,4,65535);
    	fill_bow_down(x+14,y+53,4,65535);
	fill_bow_down(x+36,y+53,4,65535);
	fill_bow_down(x+53,y+53,4,65535);
	linelevel(x-5,y-48,x+55,y-48,1,0);
	linever(x,y-48,x,y-32,1,0);
	linever(x+50,y-48,x+50,y-32,1,0);
}

void window_close(int x,int y)      //关着的窗户
{
	x = x*40;
	y = y*40+4;
	bar(x,y+10,x+80,y+35,27469);
	bar(x+3,y+13,x+77,y+32,17430);
	bar(x+35,y+12,x+45,y+32,29714);
	linever(x+40,y+10,x+40,y+35,1,0);
}

void cupboard(int x,int y)      //衣柜
{
	x = x*40;
	y = y*40+4;
	theta_bar(x,y+5,20,10,-30,56612);
	theta_bar(x+12,y,20,10,30,56612);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,56612);
	linelevel(x,y+5,x+40,y+40,1,0);
	linever(x+20,y+5,x+20,y+40,1,0);
	circle(x+16,y+20,2,0);
	circle(x+24,y+20,2,0);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
}

void aircon(int x,int y,int open)//80*40,open==1为开启，空调
{

	int color[2] = {2016,55463};        //第一个元素是绿，第二个元素是红
	x = x*40;
	y = y*40-2;
	bar(x,y+10,x+80,y+40,65535);
	linelevel(x,y+30,x+80,y+30,1,0);
	linever(x+4,y+30,x+4,y+40,1,0);
	linever(x+76,y+30,x+76,y+40,1,0);
	linelevel(x+10,y+34,x+70,y+34,1,0);
	linelevel(x+10,y+37,x+70,y+37,1,0);

	if(open)        //空调开
	{
		FillCircle(x+5,y+15,3,color[0]);        //绿灯亮
	}
	else            //空调关
	{
		FillCircle(x+5,y+15,3,color[1]);        //红灯亮
	}

}

void WashMach(int x,int y)//40*40，洗衣机
{
	int color[3] = {17430/*钢蓝*/,29714/*石板灰*/,50712/*灰色，用于制作阴影效果*/};
	x = x*40+5;        //多8个偏移量
	y = y*40+4;
	theta_bar(x,y+5,20,10,-30,color[2]);
	theta_bar(x+12,y,20,10,30,color[2]);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,65535);
	linelevel(x,y+5,x+40,y+5,1,0);
	FillCircle(x+20,y+23,10,color[1]);
	FillCircle(x+20,y+23,7,color[0]);
	circle(x+20,y+23,8,0);

}

void bookshelf(int x,int y)//40*80，书架
{
	int color[5] = {44373,64033,64594,34816,45312};//深灰色，橙红色，深橙色，深红色，耐火砖
	x = x*40;
	y = y*40+4;
	bar(x,y,x+40,y+2,65535);
	bar(x,y+40,x+40,y+42,65535);
	bar(x,y+2,x+2,y+40,color[0]);
	bar(x+38,y+2,x+40,y+40,color[0]);
	bar(x,y+42,x+2,y+80,color[0]);
	bar(x+38,y+42,x+40,y+80,color[0]);

	//书
	bar(x+2,y+30,x+7,y+40,color[1]);
	bar(x+7,y+30,x+12,y+40,color[2]);
	bar(x+12,y+20,x+20,y+40,color[3]);
	bar(x+20,y+20,x+28,y+40,65535);
	bar(x+28,y+20,x+36,y+40,color[4]);
}

void desk(int x,int y)//80*40，小方桌
{
	int color[2] = {41605,65469};//黄锗土色，海贝色
	x = x*40+5;
	y = y*40+4;
	bar(x,y,x+80,y+25,color[0]);
	bar(x,y+25,x+80,y+32,color[1]);
	bar(x,y+32,x+10,y+40,color[1]);
	bar(x+70,y+32,x+80,y+40,color[1]);
}

void seat(int x,int y)//40*40，小板凳
{
	int color = 65370;//古董白
	x = x*40;
	y = y*40+4;
	bar(x+11,y+10,x+30,y+30,0);
	bar(x+12,y+11,x+29,y+29,color);
	ever_Fillellipse(x+15,y+10,x+25,y+10,5,0);
	ever_Fillellipse(x+15,y+10,x+25,y+10,4,color);
}

void trash1(int x,int y)//40*40，纸张
{
	x = x*40;
	y = y*40+4;
	FillCircle(x+20,y+30,5,65535);
	triangle1(x+12,y+23,7,65535);
	triangle1(x+25,y+12,10,65535);
	lean_line(x+25,y+30,7,-45,0);
	bow(x+23,y+21,12,0);

}

void trash2(int x,int y)//40*40,菜叶
{
    x = x*40;
    y = y*40+4;
    linever(x+20,y+15,x+20,y+25,2,transcolor(127,255,0));
    linever(x+14,y+15,x+14,y+25,2,transcolor(127,255,0));
    linever(x+18,y+15,x+18,y+25,2,transcolor(127,255,0));
    lean_line(x+20,y+25,10,45,transcolor(127,255,0));
    lean_line(x+14,y+25,10,45,transcolor(127,255,0));
	lean_line(x+18,y+25,10,45,transcolor(127,255,0));
}

void trash3(int x,int y)//40*40,果核
{
	x = x*40;
	y = y*40+4;
	bar(x+18,y+10,x+22,y+25,transcolor(255,215,0));
	ever_Fillellipse(x+12,y+10,x+28,y+10,3,63488);
	linever(x+20,y,x+20,y+10,1,0);
}

void pc(int x,int y)    //电脑
{
	x = x*40+5;       //这个坐标是小方块的坐标，给5个偏移量
	y = y*40;
	bar(x,y,x+40,y+20,0);
	bar(x+2,y+2,x+38,y+18,65535);
	bar(x+16,y+20,x+24,y+25,0);
	bar(x+12,y+25,x+28,y+28,0);
}

void TV(int x,int y)    //15*125
{
    x = x*40;       //这个坐标是小方块的坐标
	y = y*40+4+40;
	bar(x,y,x+6,y+150,0);  //黑色电视
}

void rect_table(int x,int y)//80*80，木条纹方桌
{
	int i;
	int color[3]={63222,54705,35362};
	x = x*40+5;     //多5个偏移量
	y = y*40+4;
	bar_round(x+40,y+35,80,70,3,1,0);
	bar_round(x+40,y+35,78,68,3,1,color[1]);
	bar(x+5,y+1,x+7,y+69,color[0]);
	bar(x+5+1*15,y+1,x+9+1*15,y+69,color[0]);
	bar(x+5+2*15,y+1,x+13+2*15,y+69,color[0]);
	bar(x+5+48,y+1,x+9+3*15,y+69,color[0]);
	bar(x+5+64,y+1,x+7+4*15,y+69,color[0]);
	theta_bar(x,y+71,50,6,45,color[2]);
	theta_bar(x+40,y+74,38,5,-45,color[2]);
	bar(x+10,y+75,x+14,y+80,color[2]);
	bar(x+68,y+75,x+74,y+80,color[2]);

}

void sofa_main(int x, int y)    //沙发主要部分
{
    x = x * 40;
    y = y * 40 +4;
    bar(x+20, y, x + 80, y + 160, 56784);    //硬木色
    bar(x+20, y+40, x + 50, y + 120, 65370);     //古董白
}

void sofa_up(int x, int y)      //沙发，屏幕上面的那组
{
    x = x * 40;
    y = y * 40 +8;
    bar(x, y, x + 80, y + 60, 56784);    //硬木色
    bar(x + 20, y + 20, x + 60, y + 60, 65370);     //古董白
}

void sofa_down(int x, int y)    //沙发，屏幕下面的那组
{
    x = x * 40;
    y = y * 40 +12;
    bar(x, y, x + 80, y + 60, 56784);    //硬木色
    bar(x + 20, y, x + 60, y + 40, 65370);     //古董白
}

void toilet(int x, int y)       //马桶
{
    int i;
    x = x * 40 + 5;     //5个偏移量
    y = y * 40;
    linelevel(x, y + 10, x + 10, y + 10, 1, 0);

    bar(x, y + 10, x + 10, y + 40, 65535);  //水箱
    Horizline(x, y + 10, 10, 0);
    Horizline(x, y + 20, 10, 0);        //水箱上的分割线

    bar(x + 10, y + 30, x + 20, y + 40, 65535); //底座
    eqver_tri(x + 20, y + 30, 10, 65535);
    lean_line(x + 20, y + 40, 10 * sqrt(2), -45, 0);     //三角形和外部的分界线
    Horizline(x, y + 40, 20, 0);

    FillCircle(x + 15, y + 10, 5, 65535);          //马桶盖
    bow_left_up(x + 15, y + 10, 5, 0);               //马桶盖边框
    bow_right_up(x + 15, y + 10, 5, 0);
    bar(x + 10, y + 10, x +20, y + 20, 65535);
    linever(x + 20, y + 10, x + 20, y + 20, 1, 0);      //也是马桶盖与外界的边界

    bar(x + 10, y + 20, x + 25, y + 30, 65535);     //马桶...
    lean_line(x + 10, y + 30, 10 * sqrt(2), -45, 0); //盖与主体之间的斜线
    Horizline(x + 20, y + 20, 8, 0);            //四条横线
    linelevel(x + 17.5, y + 22.5, x + 28, y + 22.5, 1, 0);
    linelevel(x + 12.5, y + 27.5, x + 28, y + 27.5, 1, 0);
    Horizline(x + 10, y + 30, 15, 0);
    FillCircle(x + 25, y + 25, 5, 65535);
    bow_right_up(x + 25, y + 25, 2.5, 0);
    bow_right_down(x + 25, y + 25, 2.5, 0);
    bow_right_up(x + 25, y + 25, 5, 0);
    bow_right_down(x + 25, y + 25, 5, 0);

    linever(x + 10, y + 10, x + 10, y + 40, 1, 0);  //水箱与马桶盖的分界线，如果在前面画会被覆盖
}

void water_dispenser(int x, int y)  //饮水机
{
    x = x * 40;
    y = y * 40;

    //底座
    y = y + 40; //第二个方格
    theta_bar(x,y+5,20,10,-30,29714);   //石板灰
	theta_bar(x+12,y,20,10,30,29714);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,65535);
	linelevel(x,y+5,x+40,y+5,1,0);

	//接水框
	bar(x + 10, y + 10, x + 30, y + 30, 34431); //亮天蓝
	bar(x + 17.5, y + 10, x + 22.5, y + 15, 7327);      //tap，道奇蓝

    //水桶
    y = y -40;  //第一个方格，变回来
    ever_Fillellipse(x + 15, y + 10, x + 25, y + 10, 5, 26620); //水蓝
    ever_Fillellipse(x + 15, y + 33, x + 25, y + 33, 5, 26620); //水蓝
    bar(x + 12, y + 10, x + 28, y + 33, 26620);     //水蓝
    bar(x + 18.5, y + 30, x + 21.5, y + 40, 26620);

}

void zaotai(int x, int y)       //灶台
{
    x = x * 40;
    y = y * 40;
    theta_bar(x, y + 10, 60, 10, -45, 46651);   //亮钢蓝，台面
    theta_bar(x + 10, y+2, 60, 10, 45, 46651);
    bar(x, y + 10, x + 80, y + 40, 46651);
    Horizline(x, y + 10, 80, 0);
    Horizline(x, y + 40, 80, 0);
    Horizline(x + 10, y, 60, 0);
    lean_line(x, y + 10, 10 * sqrt(2), -45, 0);
    lean_line(x + 70, y, 10 * sqrt(2), 45, 0);
    linever(x, y +10, x, y + 40, 1, 0);
    linever(x + 80, y + 10, x + 80, y + 40, 1, 0);

    //灶台的加热圈
    FillCircle(x + 30, y + 6, 2.5, 29779);    //亮岩灰
    FillCircle(x + 50, y + 6, 2.5, 29779);

    //边沿线
    bow_left_up(x + 30, y + 6, 3.5, 0);
    bow_left_down(x + 30, y + 6, 3.5, 0);
    bow_right_up(x + 30, y + 6, 3.5, 0);
    bow_right_down(x + 30, y + 6, 3.5, 0);

    bow_left_up(x + 50, y + 6, 3.5, 0);
    bow_left_down(x + 50, y + 6, 3.5, 0);
    bow_right_up(x + 50, y + 6, 3.5, 0);
    bow_right_down(x + 50, y + 6, 3.5, 0);
}

///左上角，画一个水杯，占1/16个方格，入口改为像素点，而非大坐标，因为机器人持物的图像要用
void water_bottle(int x, int y)
{
    bar(x+1, y, x+9, y+13, 0);
    bar(x+2, y+1, x+8, y+12, 59391);
}

void clothes(int x, int y)  //衣服
{
    bar(x+5, y, x+25, y+3, ARMSM);
    bar(x+5, y+4, x+25, y+6, PANTSM);
}

void plate(int x,int y)     //盘子
{
	theta_bar(x,y+5,20,10,-30,65535);
	theta_bar(x+12,y,20,10,30,65535);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
    linelevel(x,y+5,x+30,y+5,1,0);
}

void medical_kit(int x, int y)  //医疗包
{
	bar(x+10, y+15, x+30, y+35, 65535);
	FillCircle(x+20, y+25, 7, 63488);
	bar(x+18, y+20, x+22, y+30, 65535);     //十字的横
	bar(x+15, y+23, x+25, y+27, 65535);     //十字的竖
}

void TV_on(void)            //电视打开状态
{
    int i,j;

    for (i=0;i<34;i++)
    {
        for (j=0;j<150+2*i;j++)
        {
            Putpixel64k(287+i,445-i+j,57083);
        }
    }

}

void TV_off(void)           //电视关闭（和上面TV的不同之处是，要做额外绘画去恢复客厅模样）
{
    int j;

    for(j = 10; j < 16; j++)      //刚刚被电视投影灰色覆盖部分的地板恢复
    {
        wood_ver(7, j);
    }

    for(j = 11; j < 17; j++)     //卧室与客厅交界的墙壁恢复
    {
        w_right(6, j);
    }

    TV(7, 10.5);
}

void music_on(int x, int y) //音符
{
    bar(x*40+15,y*40,x*40+20,y*40+32,0);
    FillCircle(x*40+9,y*40+32,8,0);
    bow_right_up(x*40+20,y*40+15,15,0);
    bow_right_up(x*40+20,y*40+14,14,0);
    bow_right_up(x*40+20,y*40+13,13,0);
    bow_right_up(x*40+20,y*40+12,12,0);
    bow_right_up(x*40+20,y*40+11,11,0);
}

void music_off( int x, int y)   //去除音符
{
    wood_ver(x, y);
	wood_ver(x, y-1);
}









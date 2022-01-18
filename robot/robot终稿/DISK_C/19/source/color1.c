#include "title.h"
/****************************************************
颜色转换及渐变色相关函数
int transcolor(int r,int g,int b)
void linelevel_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
void linever_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
void circle_color(int x0,int y0,int r1,int g1,int b1,int r2,int g2,int b2,int r)
****************************************************/

/*将rgb颜色值转换为64k色*/
int transcolor(int r,int g,int b)
{
	int rgb;
	/*
	double r_mid,g_mid,b_mid;
	r_mid = (32*(double)(r)/255);
	g_mid = (64*(double)(g)/255);
	b_mid = (32*(double)(b)/255);
	rgb = ((int)(r_mid)<<11) || ((int)(g_mid)<<5) || ((int)(b_mid));

	*/
	/*0x117模式下，原图红绿蓝各8位分别近似为5位、6位、5位*/
			r >>= 3;
			g >>= 2;
			b >>= 3;
			rgb = ((((unsigned int)r) << 11)
			| (((unsigned int)g) << 5)
			| ((unsigned int)b));
			return rgb;
}

/*竖直线性渐变*/
void linever_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
{
	float fbegin = 0.0,fend = 0.0,rstep = 0.0,gstep = 0.0,bstep = 0.0;
	unsigned int rRed,rGreen,rBlue,rgb;
	int x,y,wide=y2-y1;
	for(y=y1;y<y2;y++)
	{
	    fbegin = (float)(r1);
	    fend = (float)(r2);
	    rstep = (fend-fbegin)/(wide);
        rRed = (int)(fbegin+rstep*y);

		//green
	    fbegin = (float)(g1);
	    fend = (float)(g2);
	    gstep = (fend-fbegin)/(wide);
		rGreen = (int)(fbegin+gstep*y);

		//blue
	    fbegin = (float)(b1);
	    fend = (float)(b2);
	    bstep = (fend-fbegin)/(wide);
		rBlue = (int)(fbegin+bstep*y);
		rgb = transcolor(rRed,rGreen,rBlue);
		for(x=x1;x<=x2;x++)
		{
			Putpixel64k(x,y,rgb);
		}

	}
}

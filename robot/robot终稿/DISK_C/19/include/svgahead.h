#ifndef svgahead.h
#define svgahead.h
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include "typstrct.h"


/*设置svga显示模式 1024*768 256*/
extern void SetSVGA256();



/*模式 1024*768 64k*/
extern void SetSVGA64k();


/*获得当前svga显示模式的信息，返回显示模式号*/
extern unsigned int GetSVGA();


/*获取SVGA显示模式号bx。摘录常用的模式号如下：
				模式号		分辨率		颜色数
				0x101		640*480		256
				0x103		800*600		256
				0x104		1024*768	16
				0x105		1024*768	256
				0x110		640*480		32K
				0x111		640*480		64K
				0x112		640*480		16.8M
				0x113		800*600		32K
				0x114		800*600		64K
				0x115		800*600		16.8M
				0x116		1024*768	32K
				0x117		1024*768	64K
				0x118		1024*768	16.8M
 ******************************************************/

typedef struct
{
	unsigned char B;	/*蓝色分量，BLUE缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char R;	/*红色分量，RED缩写*/
} WESHEN;

 /******************************************************
 功能说明：显存换页
 参数说明: page ,页面号
 ********************************************************/
extern unsigned int SelectPage(unsigned char page);

 /********************************************************/

 /********************************************************
	功能说明 ：画点函数
	参数说明：x,y 所要画点位置 color 颜色
**********************************************************/
extern void   putpixel(int x,int y,int color);

/**********************************************************
  功能说明：得到某点的颜色值；
  参数说明：x,y为该点的坐标；
  返回值：color为该点的颜色值
***********************************************************/

extern int getpixel(int x,int y);



 /*******************************************************
 功能说明：  异或画点函数
 参数说明：   x,y为像素位置，color 为异或的颜色
 返回值：    无
/**********************************************************/
extern void Xorpixel (int x, int y, int color);

/*************************************************************
功能函数：用64k的模式画点
参数说明：画点的位置
返回值说明： 无返回
***************************************************************/
extern void Putpixel64k(int x, int y,  int color);


/***********************************************************
	功能说明：从硬盘读取8位BMP直接到显存
	参数说明：x，y坐标  name：文件路径
	返回值说明：
/***********************************************************/

extern int   Readbmp256(int x,int y,char * path);


 /*读取24位图片，参数x,y为图片位置，name为路径，返回值：0失败，1成功*/
extern int Putbmp64k(int x,int y,const char *path);
extern unsigned int Getpixel64k(int x, int y);
extern void  put_image(int x0,int y0,unsigned int  *save);
extern void get_image(int x0,int y0,unsigned int  *save);
extern void  printf_image0(int x0, int y0, int x1, int y1);
extern void save_image0(int x0, int y0, int x1, int y1);
extern void  printf_image(int x0, int y0, int x1, int y1);
extern void save_image(int x0, int y0, int x1, int y1);
extern void  printf_image_2(int x0, int y0, int x1, int y1, int begin_y);

#endif

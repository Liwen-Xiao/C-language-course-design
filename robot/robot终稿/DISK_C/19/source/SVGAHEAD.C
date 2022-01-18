#include "title.h"


/*模式 1024*768 64k*/
void SetSVGA64k()
{
	union REGS in;
	in.x.ax = 0x4f02;
	in.x.bx = 0x117;  /*对应的模式*/
	int86(0x10,&in,&in);
	if(in.x.ax!=0x004f)//若调用成功则返回0x004f
	{
		printf("Error in setting SVGA64k,0x%x\n",in.x.ax);
		exit(1);
	}
}

/*获得当前svga显示模式的信息，返回显示模式号*/
unsigned int GetSVGA()
{
	union REGS out;
	out.x.ax = 0x4f03;
	int86(0x10,&out,&out);
	if(out.x.ax!=0x004f)
	{
		printf("error!: ox%x\n",out.x.ax);
		exit(1);
	}
	return(out.x.bx);
}

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


 /********************************************************
	功能说明 ：画点函数
	参数说明：x,y 所要画点位置 color 颜色
**********************************************************/
   void   putpixel(int x,int y,int color)
 {
  unsigned char far*VideoBuffer=(unsigned char far*)0xa0000000L;
  unsigned long int pos;
  int Newpage=0;
  /*计算显存地址偏移量和对应的页面号，做换页操作 */
  pos=((unsigned long int)y<<10)+x;
  Newpage=pos>>16;
  SelectPage(Newpage);
  VideoBuffer[pos]=color;
  }
/**********************************************************
  功能说明：得到某点的颜色值；
  参数说明：x,y为该点的坐标；
  返回值：color为该点的颜色值
***********************************************************/

int  getpixel(int x,int y)
 {
  int color;
  unsigned char far*VideoBuffer=(unsigned char far*)0xa0000000L;
  unsigned long int pos;
  int Newpage=0;
  /*计算显存地址偏移量和对应的页面号，做换页操作 */
  pos=((unsigned long int)y<<10)+x;
  Newpage=pos>>15;
  SelectPage(Newpage);
  color=VideoBuffer[pos];
  return color;
  }


/*************************************************************
功能函数：用64k的模式画点
参数说明：画点的位置
返回值说明： 无返回
***************************************************************/
void Putpixel64k(int x, int y,  int color)
{
	if(x>=0&&x<=1024&&y>=0&&y<=768)
	{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;

	/*要切换的页面号*/
	unsigned char newpage=0;

//	unsigned char oldpage=0;
	/*对应显存地址偏移量*/
	unsigned long int page;


	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	newpage = page >> 15;	/*32k个点一换页，除以32k的替代算法*/


		SelectPage(newpage);



	/*向显存写入颜色，对应点画出*/
	video_buffer[page] = color;
    }
}


unsigned int Getpixel64k(int x, int y)
 {
	 /*显存指针常量，指向显存首地址，指针本身不允许修改*/
	 unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;

	 /*要切换的页面号*/
	 unsigned char new_page;

	 /*对应显存地址偏移量*/
	 unsigned long int page;

	 /*判断点是否在屏幕范围内，不在就退出*/
	 if (x < 0 || x >(1024 - 1) || y < 0 || y >(768 - 1))
	 {
		 return 0;
	 }

	 /*计算显存地址偏移量和对应的页面号，做换页操作*/
	 page = ((unsigned long int)y << 10) + x;
	 new_page = page >> 15;	/*32k个点一换页，除以32k的替代算法*/
	 SelectPage(new_page);

	 /*返回颜色*/
	 return video_buffer[page];
 }

/**************************************************
                9月26日编写
function:       get_image

description:     得到一片区域的图像信息

Input:          x0,y0,左上角起始坐标，X1,Y2右下角坐标，save 指向存储信息的数组

out:              无输出
**************************************************************/

void    get_image(int x0,int y0,unsigned int  *save)
{

	FILE *fp;
	int i,j;
	unsigned int t;
	int fail_amount=0;
	fp=fopen("save//image","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<70;i++)
		for(j=0;j<85;j++)
		{
			t=Getpixel64k(x0+i,y0+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}



/**************************************************
				9月26日编写
function:       put_image

description:     显示出存储空间的图像信息

Input:          x0,y0,左上角起始坐标，X1,Y2右下角坐标，save 指向存储信息的数组

out:              无输出
**************************************************************/

void    put_image(int x0,int y0,unsigned int  *save)
{

	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//image","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<70;i++)
		for(j=0;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x0+i,y0+j,t);
		}
	fclose(fp);


}


void  printf_image_2(int x0, int y0, int x1, int y1, int begin_y)
{
	FILE * fpo;                            /*定义文件指针*/

	int i = 0;                                   /*循环变量*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;
	int dy = begin_y - y0;

	unsigned   int save = 0;

	char  fas[20]="saveim";
	fpo = fopen(fas, "rb");                  /*建立保存背景的文件*/
	if (fpo == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}

	for (i = 0; i<dy; i++)
	{
		for (j = 0; j<wide; j++)
		{
			fread(&save,sizeof(int),1,fpo);
		}
	}

	for (i = 0; i<high - dy; i++)
	{
		for (j = 0; j<wide; j++)
		{


			fread(&save,sizeof(int),1,fpo);
			Putpixel64k(x0 + j, y0 + i, save);

		}
	}

	fclose(fpo);

}

/**************************************************
10月26日编写
function:       save_image

description:    显示出存储空间的图像信息

Input:          x0,y0,左上角起始坐标，X1,Y2右下角坐标,将图像信息存到文件里面

out:
**************************************************************/
void save_image(int x0, int y0, int x1, int y1)
{
	FILE * fp;                            /*定义文件指针*/

	int i = 0;                                   /*循环变量*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;


	int save = 0;



	char fg[20] = "saveim";
	fp = fopen(fg, "wb");                  /*建立保存背景的文件*/
	if (fp == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

			save = Getpixel64k(x0+j,y0+i);
			fwrite(&save,sizeof(int),1,fp);

		}
	}

	fclose(fp);

}

 /******************************************************
 功能说明：显存换页
 参数说明: page ,页面号
 ********************************************************/
unsigned int SelectPage(unsigned char page)
{
	union REGS r;
	static unsigned char old_page = 0;
	static unsigned char flag = 0;
	r.x.ax = 0x4f05;
	r.x.bx = 0;
	if (flag == 0)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
		flag++;
	}
	if (page != old_page)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
	}

	return 0;
}
 /********************************************************/

#include "title.h"
//以下两个是机器人聊天框的背景存储函数
//第一个是得到聊天框的背景
//第二个是输出聊天框的背景，及覆盖聊天框
//输入：框的左上角
//输出：无
//尺寸：240*80
void saveimage_chat(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	fp=fopen("save//welcome","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<245;i++)
		for(j=0;j<85;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************将240*80的弹窗遮挡区域显示*****/

void putsave_chat(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//welcome","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<245;i++)
		for(j=0;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是机器人欢迎框的背景存储函数
//第一个是得到聊天框的背景
//第二个是输出聊天框的背景，及覆盖聊天框
//输入：框的左上角
//输出：无
//尺寸：240*80
void saveimage_welcome(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	fp=fopen("save//chat","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<710;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************将710*40的弹窗遮挡区域显示*****/

void putsave_welcome(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//chat","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<710;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


//以下两个是选择框的背景存储函数
//第一个是得到选择框的背景
//第二个是输出选择框的背景，及覆盖选择框
//输入：框的左上角
//输出：无
//尺寸：240*40
void saveimage_choose(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	fp=fopen("save//choose","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<250;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************将240*40的弹窗遮挡区域显示*****/

void putsave_choose(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//choose","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<250;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


//以下两个是机器人动作状态框的背景存储函数
//第一个是得到动作状态框的背景
//第二个是输出动作状态框的背景，及覆盖动作状态框
//输入：框的左上角
//输出：无
//尺寸：80*30
void saveimage_doing(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//doing","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<85;i++)
	{
		for(j=0;j<33;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	}
	fclose(fp);
}

/******************将80*30的弹窗遮挡区域显示*****/

void putsave_doing(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//doing","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<85;i++)
	{
		for(j=0;j<33;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	}
	fclose(fp);
}

//以下两个是g_c框的背景存储函数
//第一个是得到g_c框的背景
//第二个是输出g_c框的背景，及覆盖g_c框
//输入：框的左上角
//输出：无
//尺寸：90*40
void saveimage_g_c(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//g_c","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<105;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************将90*40的弹窗遮挡区域显示*****/

void putsave_g_c(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//g_c","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<95;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是机器人t_c框的背景存储函数
//第一个是得到t_c框的背景
//第二个是输出t_c框的背景，及覆盖t_c框
//输入：框的左上角
//输出：无
//尺寸：120*40
void saveimage_t_c(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//t_c","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<125;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************将120*40的弹窗遮挡区域显示*****/

void putsave_t_c(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//t_c","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<125;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是机器人box框的背景存储函数
//第一个是得到box框的背景
//第二个是输出box框的背景，及覆盖box框
//输入：框的左上角
//输出：无
//尺寸：200*40
void saveimage_box(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//box","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<210;i++)
		for(j=0;j<45;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************将200*40的弹窗遮挡区域显示*****/

void putsave_box(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//box","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<210;i++)
		for(j=0;j<45;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是人背景存储函数
//第一个是得到人的背景
//第二个是输出人的背景，及覆盖人
//输入：框的左上角
//输出：无
//尺寸：70*90

void get_image_man(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//man","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_man(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//man","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是机器人的背景存储函数
//第一个是得到机器人的背景
//第二个是输出机器人的背景，及覆盖机器人
//输入：框的左上角
//输出：无
//尺寸：70*90
void get_image_robot(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//robot","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_robot(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	//while(1);
	fp=fopen("save//robot","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是垃圾1的背景存储函数
//第一个是得到垃圾1的背景
//第二个是输出垃圾1的背景，及覆盖垃圾1
//输入：框的左上角
//输出：无
//尺寸：40*40
void get_image_trash1(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash1","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_trash1(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash1","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是垃圾2的背景存储函数
//第一个是得到垃圾2的背景
//第二个是输出垃圾2背景，及覆盖垃圾2
//输入：框的左上角
//输出：无
//尺寸：40*40
void get_image_trash2(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash2","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_trash2(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash2","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//以下两个是垃圾3的背景存储函数
//第一个是得到垃圾3的背景
//第二个是输出垃圾3的背景，及覆盖垃圾3
//输入：框的左上角
//输出：无
//尺寸：40*40
void get_image_trash3(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash3","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_trash3(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash3","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


//以下两个洗澡背景存储函数
//第一个是得到洗澡的背景
//第二个是输出洗澡的背景，及覆盖地板
//输入：框的左上角
//输出：无
//尺寸：80*80
void get_image_bath(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//bath","w+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<83;i++)
		for(j=0;j<83;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_bath(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//bath","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<83;i++)
		for(j=0;j<83;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


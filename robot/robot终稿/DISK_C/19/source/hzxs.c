#include "title.h"

void gethz(char incode[],char  *bytes)
{
	unsigned char qh, wh;
	unsigned long offset;
	FILE * fhzk_p;                                                      /*定义文件指针*/
	fhzk_p = fopen("HZK\\hzk16", "rb");

	if (fhzk_p == NULL)
	{
		printf("the hzk can't open\n");

		delay(1000);
		exit(1);
	}


	qh=incode[0]-0xa0;
	wh=incode[1]-0xa0;
	offset=(94*(qh-1)+(wh-1))*32L;
	fseek(fhzk_p,offset,SEEK_SET);
	fread(bytes,1,32,fhzk_p);
	fclose(fhzk_p);
}



void dishz(int x0,int y0,int mx,int my,char *code,int color)//显示字符
{
	int x, y, i, j, k, xt, yt, bit;
	int count = 0;
	unsigned char mask=0x80;
	char *mat=(char *)malloc(32*sizeof(char));
	if (mat == NULL)
	{
		overflow_box(500,500);
		getch();
		printf("there is no place\n");
		exit(1);

	}



	gethz(code,mat);
	y=y0;
	x=x0;
	i=0;
	while(i<32)
	{
		for(yt=0;yt<my;yt++)
		{
			for(k=0;k<2;k++,count++)
			{
				for(j=0;j<8;j++)
				{
					bit=mat[count]&mask;
					for(xt=0;xt<mx;xt++)
					{
						if(bit)
						{
							Putpixel64k(x,y,color);
						}
						x++;
					}
					mask=mask>>1;
				}
				mask=0x80;
			}
			x=x0;
			count=count-2;
			y++;			
		}
		i+=2;
		count+=2;
	}
	free(mat);
}



void fdhz(int x,int y,int mx,int my,char *s,int color)
{
  while(*s!=NULL)
  {
   while( ( (x+20*mx) <1024)&&(*s!=NULL) )
   {
   dishz(x,y,mx,my,s,color);
   x+=20*mx;
   s+=2;
   }
   x=20;
   y+=20*my;
  }

}



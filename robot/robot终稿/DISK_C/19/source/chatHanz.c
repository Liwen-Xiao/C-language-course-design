#include "title.h"
/******************函数清单***************************
1.  int ShowChinese(int *qhwh,int num_chinese,int color,Area show_area,int size,char *hzk_dir)
2.  int ShowPerCharacter(int qhwh,Area show_area,Coordinate * current_position,int color,int size,char *hzk_dir)
3.  int GetBit(int num,char ch)
4.  void CheckArea(Area area,Coordinate *current_position,int size)
*****************************************************/
int ShowChinese(int *qhwh,int num_chinese,int color,Area show_area,int size,char *hzk_dir)//1
{

    int i=0;

    Coordinate current_position;//定义当前左上角坐标
    current_position.x=show_area.lt.x;//初始化当前左上角坐标
    current_position.y=show_area.lt.y;


   for(i=0;i<num_chinese;i++)//逐个汉字开始打点
   {
        ShowPerCharacter(qhwh[i],show_area,&current_position,color,size, hzk_dir);//打出单个字符


   }
   return 0;
}

int ShowPerCharacter(int qhwh,Area show_area,Coordinate * current_position,int color,int size,char *hzk_dir)//2
{
    int i=0,j=0,k=0;
    int x=current_position->x;
    int y=current_position->y;
    int real_rb_x= ((show_area.rb.x - show_area.lt.x)/size)*size + show_area.lt.x;

    FILE *hzk;//定义汉字库文件指针
    char *hzk_file;//定义汉字缓存数组
    int width_byte=0;//定义字节长度
    int qh=0,wh=0;//定义区号位号
    unsigned char *bitmap;//定义bmp指针，用来储存字形码
    long offset;//定义偏移量
    int size_read=0;//定义汉字读取有效长度
    if(x==real_rb_x) x=x-size;

    if((hzk_file=(char *)malloc(sizeof(char)*512))==NULL)//如果动态分配bmp指针内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        exit(1);
    }

    if(size%4!=0&&size<=8)//如果字体太小或者不是4的倍数，则直接返回
    {
        perror("false size");
        exit(1);
    }
    else
    {
        size_read=((size+4)/8)*size;//初始化汉字读取有效长度
    }

    sprintf(hzk_file,"%s\\hzk%d",hzk_dir,size);//把汉字库的数据写入汉字缓存数组中

    if((hzk=fopen(hzk_file,"rb"))==NULL)//如果汉字库文件打开为空，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to open");
        exit(1);
    }

    if((bitmap=(char *) malloc(sizeof(char)*size_read))==NULL)//如果动态分配bmp指针内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        exit(1);
    }

    qh=qhwh/100;//初始化区号
    wh=qhwh%100;//初始化位号
    offset=(long) (94*((int) qh-1)+((int) wh-1))*size_read;//初始化偏移量

    fseek(hzk,offset,SEEK_SET);//根据偏移量寻找汉字库的该汉字的字形码
    fread(bitmap,sizeof(char),size_read,hzk);//读取汉字库中的该汉字的字形码

    width_byte=(size+4)/8;//计算字节数宽度

    for(i=0;i<size;i+=1)
    {
        for(j=0;j<width_byte;j+=1)
        {
            for(k=0;k<8;k+=1)
            {
                if(GetBit(k+1,bitmap[i*width_byte+j])==1)//如果该像素点需要打印
                {

                    Putpixel64k(x+j*8+k, y+i, color);

                }
            }
        }
    }
    CheckArea( show_area,current_position, size);
    free(hzk_file);
    free(bitmap);
	hzk_file = NULL;
	bitmap = NULL;
    fclose(hzk);
    return 0;
}

int GetBit(int num,char ch)//3
{
    int i;
    int temp=1;
    for(i=0;i<8-num;i++)
    {
        temp*=2;
    }
    return (temp&ch)&&1;
}

void CheckArea(Area area,Coordinate *current_position,int size)//4
{
    if( (current_position->x+size*2) <=area.rb.x)//如果当前位置x轴不越出边界，则初始位置后移
    {
        current_position->x+=size;
    }

    else if( (current_position->y+size*2)<= area.rb.y )//如果当前位置y轴不越出边界，则初始位置换行
    {
        current_position->y+=size;
        current_position->x=area.lt.x;
    }
    else current_position->x=((area.rb.x - area.lt.x)/size)*size + area.lt.x;	//stay where you are
}


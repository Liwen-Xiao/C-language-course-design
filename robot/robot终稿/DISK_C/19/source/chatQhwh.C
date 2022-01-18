#include "title.h"
/******************函数清单***************************
1.  void SaveChQhwh(FILE *fp,CH * ch)
2.  int FindChQhwh(CH *ch,char *temp,int num_tab,int qhwh)
3. int CheckQhwhNum(int *qhwh)
4.	void qhwh2incode(int qwh,char *incode)
*****************************************************/
void SaveChQhwh(FILE *fp,CH * ch)//1
{
    int i=0;
    while(!feof(fp)&&i<463)
    {
        fscanf(fp,"%s", ch[i].str );//读取字符

        fscanf(fp,"%d",&(ch[i].qhwh));//读取区号位号

        i++;
    }
    fclose(fp);
}

void SaveEnQhwh(FILE *fp,EN *en)//2
{
    int i=0;
    while(!feof(fp)&&i<120)
    {
        fscanf(fp,"%s",&(en[i].str));//读取字符

        fscanf(fp,"%d",&(en[i].qhwh));//读取区号位号

        i++;
    }
    fclose(fp);
}

int FindChQhwh(CH *ch,char *temp,int num_tab,int qhwh)//3
{
    int  i;
    //对字符进行比对，找到则进行赋值
    for(i=0;i<463;i++)
    {
        if(strncmp(temp,ch[i].str,num_tab)==0)
            {
                qhwh=ch[i].qhwh;
                break;
            }
    }
    return qhwh;
}

int FindEnQhwh(EN *en,char temp)//4
{
    int i,qhwh;
    //对字符进行比对，找到则进行赋值
    for(i=0;i<120;i++)
    {
        if(strncmp( &temp,&(en[i].str),1)==0)
            {
                qhwh=en[i].qhwh;
                break;
            }
    }
    return qhwh;
}

/******************
将区号位号从文件中读取出来放到qhwh里，传回函数中打印
CheckQhwhNum确认要写入的信息量
******************/
int TxtToQhwh(int *qhwh,char *filename)//5
{
    int i=0,j=0;
    char temp;
    FILE *txt;
    if((txt=fopen(filename,"r"))==NULL)
    {
         perror("fail to open");
         return (1) ;
    }
    while((!feof(txt))&&(i<MAXTXT))
    {
        for(j=0;j<4;j++)
        {
            temp=fgetc(txt);		//从txt中获取下一个字符（一个无符号字符），并把位置标识符往前移动
            qhwh[i]=qhwh[i]*10;
            qhwh[i]=qhwh[i]+ atoi(&temp);
        }
        i++;
    }
    fclose(txt);
    return 0;
}

int AddQhwhToTxt(int *qhwh,char *filename)//6
{
    int i=0;
    FILE *txt;
    if((txt=fopen(filename,"a"))==NULL)
    {
         perror("fail to open");
         return (1) ;
    }
    for(i=0;i<CheckQhwhNum(qhwh);i++)
    {
        fprintf(txt,"%4d", qhwh[i] );
    }
    fprintf(txt,"\n");
    fclose(txt);
    return 0;
}


/******************
将信息以区位号的形式写入文件中
CheckQhwhNum确认要写入的信息量
******************/
int ReplaceQhwhToTxt(int *qhwh,char *filename)//7
{
    int i=0;
    FILE *txt;
    if((txt=fopen(filename,"w"))==NULL)
    {
         perror("fail to open");
         return (1) ;
    }
    for(i=0;i<CheckQhwhNum(qhwh);i++)
    {
        fprintf(txt,"%4d", qhwh[i] );
    }
    fprintf(txt, "\n" );	//输入完后换行
    fclose(txt);
    return 0;
}


/******************
将信息以整型（占位4个字符）写入文件中
通过CheckQhwhNum确定要写入的信息量
******************/
int ReplacePassToTxt(int *qhwh,char *filename)//8
{
    int i=0;
    FILE *txt;
    if((txt=fopen(filename,"w"))==NULL)
    {
         perror("fail to open");
         return (1) ;
    }
    for(i=0;i<CheckQhwhNum(qhwh);i++)
    {
        fprintf(txt,"%4d", qhwh[i] );
    }
    fclose(txt);
    return 0;
}

int AddNumToTxt(int num,char *filename)//9
{
    FILE *txt;
    if((txt=fopen(filename,"a"))==NULL)
    {
         perror("fail to open");
         return (1) ;
    }
    fprintf(txt,"%d", num );
    fclose(txt);
    return 0;
}

int CheckNumInTxt(char *filename)//10
{
    int i=0;
    char temp;
    FILE *txt;
    if((txt=fopen(filename,"r"))==NULL)
    {
         perror("fail to open");
         return (1) ;
    }
    while((!feof(txt)))
    {
        fgetc(txt);
        ++i;
    }
    fclose(txt);
    return i/2;
}

/**************
看看有几个区号位号（几个字）
**************/
int CheckQhwhNum(int *qhwh)//11
{
    int num_qhwh=0,i=MAXTXT;
    while(i >= 1)
    {
        if(qhwh[i-1]== 0)
        {
            ++num_qhwh;
            --i;

        }
        else break;
    }

    return (MAXTXT-num_qhwh);
}

void qhwh2incode(int qwh,char *incode)
{
	char qh,wh;
	qh = (char)(qwh/100);
	wh = (char)(qwh%100);
	incode[0] = qh+0xa0;
	incode[1] = wh+0xa0;
}

void ClearKey(void)//2
{
	union REGS key;

	key.h.ah = 0x0c;
	key.h.al = 0x00;
	int86(0x21, &key, &key);
}


/**************
区号位号归零操作
每次调用输入法都要使用
**************/
int QhwhToZero(int *qhwh)//6
{
    int i;
    for(i=0;i<MAXTXT;i++)
        qhwh[i]=0;
    return 0;
}
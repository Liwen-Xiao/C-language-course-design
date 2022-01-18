#include "title.h"
//功能：欢迎静止界面
//输入：无
//输出：无
void outwelcome(void)
{
    
	CASE robot_position;											//机器人的状态的变量的定义（用于输出机器人logo）
	int i;															//决定输出的名人名言的随机变量
	int key;														//用于存储键盘输入的信息（判断是否为“r”时有用）
    char *str;														//字符指针，用于指向要输出的句子
    char t[2];														//用来得到输入的键的中间字符串数组
    unsigned int *image_save=(unsigned int *)malloc(708*40*sizeof(unsigned int));	//	保存验证码弹窗背后的图案
    robot_position.xpixel=512;
    robot_position.ypixel=320;										//初始化logo状态
	linever_color(0,0,1024,768,211,211,211,128,128,128);			//渐变色
	fdhz(250,50,3,3,"家",27469);
	fdhz(318,50,3,3,"居",27469);
	fdhz(386,50,3,3,"机",27469);
	fdhz(454,50,3,3,"器",27469);
	fdhz(522,50,3,3,"人",27469);
	fdhz(590,50,3,3,"模",27469);
	fdhz(658,50,3,3,"拟",27469);
	fdhz(726,50,3,3,"器",27469);
    outtextxy(364,120,"iRobot",4,4,48,0);
	saveimage_welcome(192,600);										//保存输出名人名言的地方的背景到文件中
    logo_robot(robot_position);										//画logo
    srand((unsigned int)time(0));
    while(1)                         //随机名人名言输出
    {
        putsave_welcome(192,600);										//清空名人名言部分的输出
        i=rand()%5;
        key=0;
        if (i==0)
        {
            str="活着就是为了改变世界，难道还有其他原因吗？";
            fdhz(332,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==1)
        {
            str="要有勇气追随心声，听从直觉。";
            fdhz(372,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==2)
        {
            str="你若能绕过经验，便会有创新之举。";
            fdhz(352,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==3)
        {
            str="领袖和跟风者的区别就在于创新。";
            fdhz(372,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==4)
        {
            str="佛教中有一句话：初学者的心态；拥有初学者的心态是件了不起的事情。";
            fdhz(212,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        gets(t);         											//输入完之后还要点一次回车
        key=t[0];
        if (key=='r')												//如果输入“r”，那么就刷新名人名言
        {
            continue;
        }
        else
        {
            break;
        }
    }
    free(image_save);
    image_save=NULL;
}


//功能：goodbye界面
//输入：无
//输出：无
void good_bye(void)
{
	CASE robot_position;
    robot_position.xpixel=512;
    robot_position.ypixel=220;
	linever_color(0,0,1024,768,211,211,211,128,128,128);
	logo_robot(robot_position);
	fdhz(220,460,3,3,"与您度过了美好的一天",27469);
	fdhz(250,520,3,3,"希望下次与您的见面",27469);
	outtextxy(364,120,"iRobot",4,4,48,0);
	getch();
	exit(1);
}

//功能：机器人logo输出
//输入：机器人的状态变量
//输出：无
void logo_robot(CASE robot_position)
{
	theta_bar(robot_position.xpixel,robot_position.ypixel+50,(int)(24/sin((double)(45)/180*PI)),(int)(24/sin((double)(45)/180*PI)),45,27469);
	FillCircle(robot_position.xpixel+16+(int)(32/tan((double)(45)/180*PI))+2,robot_position.ypixel+80,14,27469);
    theta_bar(robot_position.xpixel-(int)(24/sin((double)(45)/180*PI)),robot_position.ypixel+50,(int)(24/sin((double)(135)/180*PI)),(int)(24/sin((double)(135)/180*PI)),225,27469);

	FillCircle(robot_position.xpixel-16+(int)(32/tan((double)(-45)/180*PI))-2,robot_position.ypixel+80,14,27469);
	//头
	ever_Fillellipse(robot_position.xpixel-15, robot_position.ypixel+24, robot_position.xpixel+15, robot_position.ypixel+24, 18, 27469);    //先画黑再覆盖，相当于有了轮廓

    FillCircle(robot_position.xpixel-15, robot_position.ypixel+24, 6, 54938);   //眼睛
    FillCircle(robot_position.xpixel+15, robot_position.ypixel+24, 6, 54938);
    bar(robot_position.xpixel-30, robot_position.ypixel+120, robot_position.xpixel+30, robot_position.ypixel+150, 27469);
    linever(robot_position.xpixel, robot_position.ypixel+120, robot_position.xpixel, robot_position.ypixel+150, 1, 50712);
    //身体
	bar(robot_position.xpixel-32, robot_position.ypixel + 38,robot_position.xpixel+32, robot_position.ypixel + 122, 27469);//边框
    circle(robot_position.xpixel, robot_position.ypixel + 80, 20, 50712);   //不填充
    circle(robot_position.xpixel, robot_position.ypixel + 80, 21, 50712);   //不填充
}

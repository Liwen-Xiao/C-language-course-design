#include "title.h"
//功能：登录注册功能主逻辑
//输入：无
//输出：int型
//      返回1为登陆成功，跳出循环，进入下一模块
//		返回0为登陆失败，继续循环
int enter(void)
{
	USERS user;												//用来存放当前用户的信息
	USERS *head = NULL;										//链表的头节点
	int temp;												//用于存放键盘输入
	//int error=0;											//
	int button,x,y;
	int judge=0;											
	user.account[0] = '\0';
	user.code[0] = '\0';

	if ((head = (USERS *)malloc(sizeof(USERS))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	create_list(head);
	log_in_page();                                 //静止登录界面
	mouseInit(&x, &y,&button);
    while(1)
	{
		//newxy(&x, &y, &button);
				    /*初始化，接受缓冲区数据*/
		if (kbhit() == 0)
		{
			newxy(&x, &y, &button);
		}
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}

		/*登录*/
		if(x>=650&&x<=700&&y<=495&&y>=445&&button)
		{
			judge = log_in_check(head,user.account,user.code);  //登录成功返回1
		}


		/*注册*/
		if(x>=440&&x<=560&&y>=555&&y<=590&&button)
		{
			
			judge = UserRegist(head,user.account,user.code,&x,&y,&button);
		}

		if(x>=300&&x<=700&&y>=295&&y<=345&&button)	//选择id输入
		{
			judge = 2;
		}

		if(x>=300&&x<=700&&y>=445&&y<=495&&button)	//选择密码输入
		{
			judge = 3;
		}

		if(judge==2)//输入id
		{
			judge = input_account(head,&user.account,&user.code,&x,&y);

		}
		if(judge==3)//输入password
		{
			judge = input_code(head,&user.account,&user.code,&x,&y);
		}
		if(judge==1)
		{
			free_list(&head);
            return 1;
		}
		//返回登录界面
		if(judge==5)
		{
			free_list(&head);
			head=NULL;
			return 0;    //只要不是1就可以了
		}

	}
}


//功能：登录的静止界面
//输入：无
//输出：无
void log_in_page(void)
{
    CASE robot_position;
    robot_position.xpixel=500;
    robot_position.ypixel=120;
    
    linever_color(0,0,1024,768,211,211,211,128,128,128);
    bar_round(500,320,400,50,5,1,65535);//300,295,700,345
    bar_round(500,470,400,50,5,1,65535);
    fdhz(250,310,1,1,"帐",0);
    fdhz(270,310,1,1,"号",0);
    fdhz(250,460,1,1,"密",0);
    fdhz(270,460,1,1,"码",0);
    FillCircle(675,470,22,65535);
    circle(675,470,22,33808);
    circle(675,470,23,33808);
    linelevel(660,470,690,470,2,33808);
    lean_line_thick(690,470,20,225,2,33808);
    lean_line_thick(690,470,20,135,2,33808);
    bar (440,555,560,590,50712);
    fdhz(484,570,1,1,"注册",0);
	   

    logo_robot(robot_position);

}


//功能：账号输入函数
//输入：用户信息链表的头节点，指向账号字符串的字符指针，指向密码字符串的字符指针，鼠标坐标指针
//输出：int型
//		返回1：登录或注册成功
//		返回3：进入密码输入函数
int input_account(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *p=account;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;
	char temp[2] = {'\0','\0'};

	//查看已经输入了多少个字符
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		//newxy(x,y,&buttons);
		key=0;
		if (kbhit() == 0)
		{
			newxy(x,y,&buttons);
		}
		if (kbhit() != 0)
		{
			key = bioskey(0);    //输入的是键值
		}


	     /*将按键对应的字符存入account中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			temp[0] = ch;
			outtextxy(300+i*18,305,temp,2,2,10,0);


		/*将字符存入数组中*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }



        if(key ==0xe08)         //按了回删键
	    {
		    if(p != account)
		    {
			    bar(290 + i * 18, 295, 340 + i * 18, 345,65535);
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		//删掉了防止鼠标遮挡的功能（2020/7/26）



		//密码输入
		if(*x>=300&&*x<=700&&*y>=445&&*y<=495&&buttons)
		{
			return 3;
		}

		//注册键
		if(*x>=440&&*x<=560&&*y>=555&&*y<=590&&buttons)
		{
			
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}




		//登录键
		if(*x>=650&&*x<=700&&*y<=495&&*y>=445&&buttons)
		{

			judge = log_in_check(head,account,code);
			return judge;
		}
	}
}

//功能：账号输入函数
//输入：用户信息链表的头节点，指向账号字符串的字符指针，指向密码字符串的字符指针，鼠标坐标指针
//输出：int型
//		返回1：登录或注册成功
//		返回2：进入id输入函数
int input_code(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *u = code;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;

	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(u != code)
		    {
			    bar(275 + i * 25, 450, 305 + i * 25, 490,65535);
			    u--;
			    i--;
		    }
			*u = '\0';
	    }

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		//登录键
		if(*x>=650&&*x<=700&&*y<=495&&*y>=445&&buttons)
		{
            
			judge = log_in_check(head,account,code);
			return judge;
		}

		//删去防止输入时遮挡功能



		//输入账号
		if(*x>=300&&*x<=700&&*y>=295&&*y<=345&&buttons)
		{

			return 2;
		}

		//注册框
		if(*x>=440&&*x<=560&&*y>=555&&*y<=590&&buttons)
		{
			
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}


	/*将按键对应的字符存入code数组中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {


		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(315+i*25,470,8,0);

		/*将字符存入数组中*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
}



//功能：验证账号密码是否正确
//输入：用户信息链表的头节点，指向账字符串的字符指针，指向密码字符串的字符指针
//输出：int型
//		返回1：验证成功
//		返回5：验证失败
int log_in_check(USERS *head,char *account,char *code)
{
	char *rightcode= NULL;
	rightcode = accounts_2_code(head, account);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //登录成功
	else
	{
		fdhz(410, 500,1, 1, "用户名或密码输入错误", 0);
        getch();
		return 5;
	}
}

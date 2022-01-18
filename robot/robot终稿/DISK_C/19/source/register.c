#include "title.h"
//功能：注册功能主逻辑函数
//输入：用户信息链表的头节点，指向账号字符串的字符指针，指向密码字符串的字符指针，鼠标坐标指针和按键信息指针
//输出：int型
//		返回1：注册成功
//		返回5：按了返回键
int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *buttons)
{
	int judge = 0; //判断应该调用那些函数的变量
	int flag[4] = {0};  //分别为为用户名、密码、二次密码是否正确的判断变量
	int temp;  //用于吸收键盘缓冲区的变量
	char secondcode[11];  //第二次输入密码串
	char mail[20]={0};
	char real_veri[5]={0};
	char veri[5]={0};

	/*必要的初始化过程*/
	secondcode[0] = '\0';
	*account = '\0';
	*code = '\0';
	mousehide(*x,*y);         //画鼠标
    regist_page();              //登录界面
	reset_mouse(x,y);         //存鼠标样子
	while (1)
	{

        newxy(x, y, buttons);//在新的位置画鼠标
        //账号输入
		judge = input_area(x,y,buttons);
		
		switch(judge)
		{

			case 0:
				break;
			//调用账号输入函数
			case 1:
				//judge = RegisteraccountsInput(account, x, y);
				judge = inpu(account, x, y, buttons,349, 260,0);
				if (account[0]==0)
				{
					bar(695,240,750,310,50712);      //清空×勾的位置处的图像
					red_cross(700,275);
					fdhz(450,242,1,1,"账号不能为空",0);
					flag[0] = 0;
				}
				else if (accounts_2_code(head, account) != NULL)
				{
					bar(695,240,750,310,50712);      //清空×勾的位置处的图像
					red_cross(700,275);
					fdhz(450,242,1,1,"该账号已被注册",0);
					flag[0] = 0;
				}
				else
				{
					bar(695,240,750,310,50712);      //清空×勾的位置处的图像
					bar(440,241,690,259,50712);      //清空“该账号已被注册”
					green_tick(700,275);
					flag[0] = 1;

				}
				break;
			/*case 2:调用密码输入函数*/
			case 2:
				//judge = RegistercodeInput(code, x, y);
				judge = inpu(code, x, y, buttons,349, 350,1);
				if (strlen(code) < 6)
				{
					/*画红色的叉并提示密码不得少于六位&flag2=0*/
					bar(695,330,750,400,50712);      //清空×勾的位置处的图像
					bar(440,331,690,349,50712);      //清空“密码不得少于六位”
					red_cross(700,365);
					fdhz(442,332,1, 1, "密码不得少于六位",  0);
					flag[1] = 0;
				}
				else
				{
					/*画一个绿色的勾&flag2=1*/
					bar(695,330,750,400,50712);      //清空×勾的位置处的图像
					bar(440,331,690,349,50712);      //清空“密码不得少于六位”
					green_tick(700,365);
					flag[1] = 1;
				}
				break;

			/*case 3:调用二次密码输入函数*/
			case 3:
				//judge = RegistersecondcodeInput(secondcode, x, y);
				judge = inpu(secondcode, x, y, buttons,349, 440,1);
				if (strcmp(code, secondcode) != 0)
				{
					/*画红色的叉并提示两次密码输入不同&&flag3=0*/
					bar(695,420,750,490,50712);      //清空×勾的位置处的图像
					bar(400,421,690,439,50712);      //清空“两次输入的密码不同”

					red_cross(700,455);
					fdhz(442,422, 1, 1, "两次输入的密码不同", 0);
					flag[2] = 0;
				}
				else
				{
					/*画一个绿色的勾&flag3=1*/
					bar(695,420,750,490,50712);      //清空×勾的位置处的图像
					bar(400,421,690,439,50712);      //清空“两次输入的密码不同”
					green_tick(700,455);

					flag[2] = 1;
				}
				break;

			/*case 4:邮箱输入*/
			case 4:
				//judge=mail_input(mail,x,y);
				judge = inpu(mail, x, y, buttons,349, 530,0);
				break;

			/*case 5:获取验证码*/
			case 5:
				flag[3]=get_verification(mail,real_veri,flag);
				judge=4;
				break;


			/*case 6:验证码输入*/
			case 6:
				//judge=verification_input(veri, x, y);
				judge = inpu(veri, x, y, buttons,349, 620,0);
				break;

			/*case 7:完成注册键*/
			case 7:
				if (regist_success(real_veri, veri) && flag[1] && flag[2] && flag[0])
				{
					add_new_user(head,account,code);   //计入文件
					bar(695,600,750,670,50712);      //清空×勾的位置处的图像
					bar(400,601,690,619,50712);      //清空“验证码不正确”
					return 1;
				}
				else
				{
					bar(695,600,750,670,50712);      //清空×勾的位置处的图像
					bar(400,601,690,619,50712);      //清空“验证码不正确”

					red_cross(700,635);
					fdhz(622,602, 1, 1, "验证码不正确", 0);
				}
				break;
			case 8:
				return 5;
		}

	}
}


//功能：decide which input function will be invoked
//输入：the pointer's information of mouse
//输出：int型
//		返回1：进入账号输入函数
//		返回2：进入密码输入函数
//		返回3：进入二次确认密码输入函数
//		返回4：进入邮箱输入函数
//		返回6：进入输入验证码函数
//		返回7：点击了完成，进入注册验证函数
//		返回8：按了“back"
int input_area(int *x,int *y, int *buttons)
{
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
		}
        	//返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}
		else 
			return 0;

}




//功能：注册的各个模块的输入
//输入：
//		char*inpu_c：将要输入的字符串的首地址
//		int *x, int *y, int *buttons：鼠标的坐标和按键的指针
//		int x_posi, int y_posi：输入起始位置（第一个字符的左上角坐标）
//		int a_p：判断输入的是否是密码，是密码就显示实心圆，不是就显示该有的字符
//				0：不是密码
//				1：是密码
//输出：int型
//		返回1：进入账号输入函数
//		返回2：进入密码输入函数
//		返回3：进入二次确认密码输入函数
//		返回4：进入邮箱输入函数
//		返回6：进入输入验证码函数
//		返回7：点击了完成，进入注册验证函数
//		返回8：按了“back"
int inpu(char*inpu_c, int *x, int *y, int *buttons,int x_posi, int y_posi,int a_p)  //a_p是0表示非密码
{
	int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = inpu_c;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
    char temp[2]={0};//用于outtextxy的输出
	int judge=0;
	
	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}
	
	while (1)
	{
		newxy(x, y, buttons);//在新的位置画鼠标

		judge = input_area(x,y,buttons);
		
		if (judge!=0)
			return judge;

        key=0;

		if (a_p==0)
		{
			/*吸收键盘缓冲区数据*/
			if (kbhit() != 0)
			{
				key = bioskey(0);
			}

			/*按esc则退出*/
			if(key == 0x11b)
			{
				exit(0);
			}
			/*按了回删键*/
			if(key == 0xe08)	//点击退格键时的操作
			{
				if(p != inpu_c)		//检测是否是首位（地址是否相同）
				{
					bar(x_posi+ i * 10+4, y_posi, x_posi+16+ i * 10+4, y_posi+30,65535);
					p--;			//指针		往前移
					i--;			//记字数	往前移
				}
				*p = '\0';			//	同样将最后一位换成'\0'
			}
			//	将按键对应的字符一个个存入ph_num数组中

			ch = searchKeyValue(key);
			temp[0] = ch;
			if (ch != '\0'&&i<20)
			{
				outtextxy(x_posi+i*10+10,y_posi+7,temp,1,1,8,0);

				//	将字符存入数组中
				*p = ch;
				p++;
				*p = '\0';		// 每次操作都要归'\0'
				i++;

			}
		}
		
		else if(a_p==1)
		{
			/*吸收键盘缓冲区数据*/
			if (kbhit() != 0)
			{
				key = bioskey(0);
			}

			/*按esc则退出*/
			if(key == 0x11b)
			{
				exit(0);
			}
			/*按了回删键*/
			if(key == 0xe08)	//点击退格键时的操作
			{
				if(p != inpu_c)		//检测是否是首位（地址是否相同）
				{
					bar(x_posi + i * 15 -15, y_posi, x_posi+15 + i * 15, y_posi+30,65535);
					p--;			//指针		往前移
					i--;			//记字数	往前移
				}
				*p = '\0';			//	同样将最后一位换成'\0'
			}
			//	将按键对应的字符一个个存入ph_num数组中

			ch = searchKeyValue(key);
			temp[0] = ch;
			if (ch != '\0'&&i<20)
			{
				FillCircle(x_posi + i * 15+8, y_posi+15, 5, 0);

				//	将字符存入数组中
				*p = ch;
				p++;
				*p = '\0';		// 每次操作都要归'\0'
				i++;

			}
		}
	}
	
}

//功能：静态注册界面
//输入：无
//输出：无
void regist_page(void)
{
    CASE robot_position;
    robot_position.xpixel=517;
    robot_position.ypixel=90;
	bar(0,0,1024,768,54938);
	bar(80,70,944,695,50712);
	fdhz(296,11,3,3,"欢",0);
	fdhz(392,11,3,3,"迎",0);
	fdhz(488,11,3,3,"新",0);
	fdhz(584,11,3,3,"朋",0);
	fdhz(690,11,3,3,"友",0);
	//bar_round(100,100,50,50,3,1,255);
	bar_round(517,275,346,30,5,1,65535);//用户名     344,260   690,290
    bar_round(517,365,346,30,5,1,65535);//密码       344,350   690,380
    bar_round(517,455,346,30,5,1,65535);//再次输入密码  344,440   690,470
    bar_round(517,545,346,30,5,1,65535);//输入邮箱  344,530   690,560
    bar_round(517,635,346,30,5,1,65535);//输入验证码  344,620   690,650
    bar(584,533,690,557,54938);         //获取验证码    584，533   690，557
	//bar_round(517,540,234,50,5,1,33808);
	logo_robot(robot_position);
	fdhz(280,267,1,1,"帐",0);
	fdhz(300,267,1,1,"号",0);
	fdhz(280,357,1,1,"密",0);
	fdhz(300,357,1,1,"码",0);
	fdhz(240,447,1,1,"确",0);
	fdhz(260,447,1,1,"认",0);
	fdhz(280,447,1,1,"密",0);
	fdhz(300,447,1,1,"码",0);
	fdhz(280,537,1,1,"邮",0);
	fdhz(300,537,1,1,"箱",0);
	fdhz(590,537,1,1,"获取验证码",27469);
	fdhz(260,647,1,1,"验",0);
	fdhz(280,647,1,1,"证",0);
	fdhz(300,647,1,1,"码",0);
	fdhz(468,715,2,2,"完",0);
	fdhz(532,715,2,2,"成",0);
	outtextxy(83,95,"back",1,1,10,65535);
}

//功能：获取验证码函数
//输入：指向邮箱字符串的字符指针，指向验证码字符串的字符指针，指针flag
//输出：int型
//		返回1：账号密码信息完整，邮箱正确，生成验证码
//		返回0：验证码生成错误
int get_verification(char *mail,char *real_veri, int flag[])
{
    char real_mail[17] = "123456aqq.com";
    int a,i;
    char b[5];
    int flag0=0;
    srand((unsigned)time(0));
    
	if (flag[0]==1 && flag[1]==1  &&  flag[2]==1)
	{
			if (whether_mail(mail)==0)
		{
			bar(390,505,690,530,50712);
			fdhz(454,510,1,1,"邮箱格式不正确",65535);
			bar(695,530,750,580,50712);      //清空×勾的位置处的图像
			red_cross(700,545);
		}
		if (whether_mail(mail)==1)
		{
			if (strcmp(mail,real_mail)==0)
			{
				bar(390,505,690,530,50712);
				bar(695,530,750,580,50712);      //清空×勾的位置处的图像
				green_tick(700,545);
				//get_image(290,0,740,96,image_save);
				bar (290,0,740,50,65535);
				bar_round_2(290,30,740,96,10,1,65535);
				fdhz(300,5,1,1,"尊敬的用户，您好：",0);
				fdhz(332,25,1,1,"欢迎使用本智能家居机器人系统，本次您",0);
				fdhz(332,45,1,1,"注册的验证码为：",0);
				linelevel(380,90,620,90,3,0);
				a=rand()%10000;
				itoa(a,b,5);

				b[4]='\0';

				for(i=0;i<5;i++)
				{
					real_veri[i] = b[i];
				}


				outtextxy(450,50,b,2,2,15,0);

				fdhz(300,75,1,1,"祝您使用愉快",0);
				delay(1500);
				//put_image(290,0,740,96,image_save);
				flag0=1;
			}
		}
	}
	
	else 
	{
		bar(390,505,690,530,50712);
		fdhz(454,510,1,1,"账号密码信息不完整",65535);
		bar(695,530,750,580,50712);      //清空×勾的位置处的图像
		red_cross(700,545);
	}
    return flag0;
}

//功能：判断注册是否成功
//输入：真的验证码的字符指针和自己写入的验证码的字符指针
//输出：int型
//		返回0：验证码不正确，失败
//		返回1：验证码正确，成功
int regist_success(char *real_veri, char *veri)
{
    int p=0;
    if (strcmp(real_veri,veri)==0)
    {
        p=1;
    }
    return p;
}

//功能：判断邮箱是否为默认邮箱格式
//输入：指向邮箱字符串的字符指针
//输出：int型
//		返回1：格式正确
//		返回0：格式错误
int whether_mail(char *str)
{
    int p=0;
    if (strstr(str,"aqq.com"))
    {
        p=1;
    }
    return p;
}


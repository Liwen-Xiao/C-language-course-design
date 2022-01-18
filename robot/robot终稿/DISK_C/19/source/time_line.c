#include "title.h"
//功能：主人回家函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
void come_home(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{
    paint_man(*man, MASTER);																	//画人，人的参数已经在主进程函数中写了
	aimmove(robot,robot->x,robot->y,4,4,G,n,ROBOT);												//让机器人到4，4去迎接主人


	saveimage_chat(robot->x*40+40,robot->y*40);													//聊天框后面的背景的存储
	saveimage_choose(robot->x*40+40,robot->y*40+40*2);											//选择框后面的背景的存储

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  	//聊天白框
	show_reply("欢迎回家，主人",robot);

	delay(500);

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
	show_reply("您晚上想吃川菜还是粤菜呢？",robot);

	bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //选项白框
	fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"川菜",0);

	bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //选项白框
	fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"粤菜",0);

	while (1)
    {
        newxy(mx,my,button);
        if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)  //选择川菜
        {
            choice[1]=1;
            break;
        }
        if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)  //选择粤菜
        {
            choice[1]=2;
            break;
        }
    }

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
	show_reply("好的，我会记住您的选择",robot);

	putsave_chat(robot->x*40+40,robot->y*40);  //恢复聊天框的背后的背景
	putsave_choose(robot->x*40+40,robot->y*40+40*2);  //选择框消失
	delay(300);

	entertain_and_work(robot,man,mx,my,button,choice,G, n);							//进入工作娱乐函数功能模块
    delay0(200);
    aimmove(robot,robot->x,robot->y,10,2,G,n,ROBOT);
	saveimage_doing(robot->x*40-40,robot->y*40-35);									//做事状态框背后的图像的存储

    bar(robot->x*40-40,robot->y*40-35,robot->x*40+40,robot->y*40-5,65535);           //做饭状态白框
    fdhz(robot->x*40-30,robot->y*40-30,1,1,"做饭中",0);
}

//功能：晚餐函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
void dinner(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{
    int t;											//随机变量，用来判断随机输出菜名
    char *s=NULL;									//用于指向菜名的字符数组的字符指针
    srand((unsigned int)time(0));
    t=rand()%4;										//给t赋随机值

    putsave_doing(robot->x*40-40,robot->y*40-35);  //去掉”做饭中“的状态

	robot->catch_th = WITH_PLATE;					//机器人的状态改为拿了盘子
    aimmove(robot,robot->x,robot->y,11,6,G,n,ROBOT);//机器人走到桌子旁
	robot->catch_th = WITHOUT_THING;				//机器人将盘子放到桌上
    plate(12*40,8*40+20);


    //***********这里是还原人工作或休息时家具的状态

    if(choice[0]==1) 			 //假如人是在休息
    {
        if(choice[2]==1) 		//假如人选择了看电视
        {
            TV_off();   		//关掉电视机
            delay(200);
        }
        else if(choice[2]==2)	//假如人选择了听音乐
        {
            music_off(8,10);
            music_off(9,10);	//去掉音乐的音符
            delay(200);
        }

		//**********以下为吃饭的桌子恢复原样，用于吃饭后桌子恢复原样使用
        wood_ver(14, 12);
        wood_ver(14, 13);
        wood_ver(15, 12);
        wood_ver(15, 13);
		wood_ver(14, 14);
		wood_ver(15, 14);
        sofa_main(14, 11);
		man->xpixel=man->x*40;  //人的位置恢复到坐下来之前的位置
        man->ypixel=man->y*40;
        man_forebody(*man,1);	//画人的正面
		//***********
    }
    else if(choice[0]==2)  //假如人去工作
    {
		//*******************  以下是工作的桌子恢复原样，用于工作后桌子恢复原样使用
        green_bedroom(0, 14);
        green_bedroom(0, 15);
        green_bedroom(0, 16);
        green_bedroom(1, 14);
        green_bedroom(1, 15);
        green_bedroom(1, 16);
        rect_table(0, 13);
        desk(0, 15);
        seat(0, 16);
        pc(0, 15);
		man->xpixel=man->x*40;
        man->ypixel=man->y*40;
        man_forebody(*man,1);
		//***********************************
    }

    aimmove(man,man->x,man->y,9,10,G,n,MAN);    //人到饭桌旁



    put_image_man(man->xpixel,man->ypixel);     //将人盖住
    man->xpixel=500;
    man->ypixel=315;							//设置人坐下时的坐标
    sit_1(*man);								//画人坐在桌前

    if (choice[1]==1)							//如果选择的是川菜，则随机输出一个川菜
    {
        if(t==0)
        {
            s="麻婆豆腐";
        }
        else if (t==1)
        {
            s="鱼香肉丝";
        }
        else if (t==2)
        {
            s="冒菜";
        }
        else if (t==3)
        {
            s="蚂蚁上树";
        }
    }
    else if (choice[1]==2)						//如果选择的是川菜，则随机输出一个川菜
    {
        if(t==0)
        {
            s="蜜汁叉烧";
        }
        else if (t==1)
        {
            s="脆皮烤肉";
        }
        else if (t==2)
        {
            s="红烧乳鸽";
        }
        else if (t==3)
        {
            s="上汤焗龙虾";
        }
    }
	saveimage_chat(robot->x*40+40,robot->y*40);  //聊天框后面的背景的存储

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
	fdhz(robot->x*40+40+10,robot->y*40+20,1,1,"今天是",0);
	fdhz(robot->x*40+40+10,robot->y*40+40,1,1,s,0);
	fdhz(robot->x*40+40+10,robot->y*40+60,1,1,"请慢用",0);

	getch();									//需要按一下键
    putsave_chat(robot->x*40+40,robot->y*40);	//将聊天框背后的背景放出来

    //*********************
    //桌子上有盘子（表示人在吃饭）
    //*************
    saveimage_doing(man->x*40-40,man->y*40-35);	//存放人的动作状态框后面的背景

    bar(man->x*40-40,man->y*40-35,man->x*40+40,man->y*40-5,65535);           //吃饭
    fdhz(man->x*40-20,man->y*40-30,1,1,"吃饭中",0);
    getch();

    putsave_doing(man->x*40-40,man->y*40-35);		//动作状态背景put出

    entertain_and_work(robot,man,mx,my,button,choice,G, n);  //进入工作娱乐函数功能模块

}

//功能：娱乐工作函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
void entertain_and_work(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{

	saveimage_chat(robot->x*40+40,robot->y*40);  //聊天框后面的背景的存储
	saveimage_choose(robot->x*40+40,robot->y*40+40*2);  //选择框后面的背景的存储

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  	//聊天白框
    show_reply("您现在是选择娱乐还是工作呢？",robot);
	bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //选项
	fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"娱乐",0);

	bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //选项
	fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"工作",0);

    while (1)
    {
        newxy(mx,my,button);
        if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)   		//选择娱乐
        {
            choice[0]=1;
            break;
        }
        if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)    //选择工作
        {
            choice[0]=2;
            break;
        }
    }

    putsave_choose(robot->x*40+40,robot->y*40+40*2);  //选择框消失
	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
	fdhz(robot->x*40+40+20,robot->y*40+20,1,1,"好的",0);

	delay(200);


	if(choice[0]==1)  //娱乐
    {
        bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
        show_reply("您要哪种娱乐呢",robot);

        bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //选项
        fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"看电视",0);

        bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //选项
        fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"听音乐",0);

        while (1)
        {
            newxy(mx,my,button);
            if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)  	//选择看电视
            {
                choice[2]=1;
                break;
            }
            if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)	//选择听音乐
            {
                choice[2]=2;
                break;
            }
        }

        putsave_choose(robot->x*40+40,robot->y*40+40*2);  //选择框消失
        bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
        fdhz(robot->x*40+40+20,robot->y*40+20,1,1,"好的",0);

        delay(200);

        putsave_chat(robot->x*40+40,robot->y*40);  //恢复聊天框的背后的背景

		//*********以下为人起身，吃饭的桌子恢复原状

        wood_ver(12, 7);
        wood_ver(12, 8);
        wood_ver(12, 9);
        desk(12, 8);
        seat(12, 9);
		seat(12, 7);
		man->xpixel=man->x*40;
        man->ypixel=man->y*40;
        man_forebody(*man,1);         //吃饭的桌子恢复原状

        //****************
        aimmove(man,man->x,man->y,14,15,G,n,MAN);
        //*************这一行是人坐在沙发上的图像

        put_image_man(man->x*40,man->y*40);
        man->xpixel=580;
        man->ypixel=500;
        sit_2(*man);
		//*********************

        if(choice[2]==1)    //假如选择了看电视
        {
            TV_on();		//打开电视机

        }
        else if (choice[2]==2) //假如人选择了听音乐
        {

            music_on(8,10);
            music_on(9,10);  		//画出两个音符
        }
    }
    else if (choice[0]==2)			//假如人去工作
    {
		delay(200);

        putsave_chat(robot->x*40+40,robot->y*40);  //恢复聊天框的背后的背景

		//************以下为人起身，吃饭的桌子恢复原状
		wood_ver(12, 7);
        wood_ver(12, 8);
        wood_ver(12, 9);
        desk(12, 8);
        seat(12, 9);
		seat(12, 7);
		man->xpixel=man->x*40;
        man->ypixel=man->y*40;
        man_forebody(*man,1);         //吃饭的桌子恢复原状
		//***********************
		aimmove(man,man->x,man->y,2,15,G,n,MAN);	//人前往工作桌前
        //**************以下是人坐在桌前工作的图像

        put_image_man(man->x*40,man->y*40);
        man->xpixel=20;
        man->ypixel=600;
        sit_1(*man);
		//**********************

        aimmove(robot,robot->x,robot->y,14,2,G,n,ROBOT);//机器人去接水

        saveimage_doing(robot->x*40-40,robot->y*40-35); //机器人动作状态框背景存储

        bar(robot->x*40-40,robot->y*40-35,robot->x*40+40,robot->y*40-5,65535);           //接水
        fdhz(robot->x*40-30,robot->y*40-30,1,1,"接水中",0);
        delay(500);

        putsave_doing(robot->x*40-40,robot->y*40-35); 	//动作状态框恢复
		robot->catch_th = WITH_BOTTLE;          //  这里机器人的手中有水杯

        aimmove(robot,robot->x,robot->y,3,14,G,n,ROBOT);  //这行的目的是送杯水过去
		robot->catch_th = WITHOUT_THING;

        water_bottle(50,605);//把水杯放在桌上
        aimmove(robot,robot->x,robot->y,13,2,G,n,ROBOT);  //回到默认位置处
        delay0(50);
    }
}

//功能：洗澡函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
void bath(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{
	if (choice[0]==1)	//假如选择淋浴
	{
		aimmove(robot,robot->x,robot->y,13,16,G,n,ROBOT);    //机器人回到默认位置
	}
	if (choice[0]==2)	//假如选择泡澡
	{
		aimmove(robot,robot->x,robot->y,3,15,G,n,ROBOT);    //机器人前往厕所放水
	}

	saveimage_chat(robot->x*40+40,robot->y*40);  //聊天框后面的背景的存储
	saveimage_choose(robot->x*40+40,robot->y*40+40*2);  //选择框后面的背景的存储


	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
    show_reply("您今天是选择淋浴还是泡澡？",robot);


	bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //选项
	fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"淋浴",0);

	bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //选项
	fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"泡澡",0);

    while (1)
    {
        newxy(mx,my,button);
        if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button) 	//选择淋浴
        {
            choice[3]=1;
            break;
        }
        if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)	//选择泡澡
        {
            choice[3]=2;
            break;
        }
    }

    putsave_choose(robot->x*40+40,robot->y*40+40*2);  //选择框消失
	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
	fdhz(robot->x*40+40+20,robot->y*40+20,1,1,"好的",0);

	delay(200);

	if(choice[3]==2)
    {
        bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //聊天白框
        show_reply("马上为您准备热水",robot);

        delay(1000);
        putsave_chat(robot->x*40+40,robot->y*40);  //恢复聊天框的背后的背景

        aimmove(robot,robot->x,robot->y,2,3,G,n,ROBOT);//机器人到浴缸旁边

        saveimage_doing(robot->x*40-40,robot->y*40+82);
        bar(robot->x*40-40,robot->y*40+82,robot->x*40+40,robot->y*40+112,65535);           //准备热水
        fdhz(robot->x*40-30,robot->y*40+85,1,1,"放水中",0);
        delay(1000);
        putsave_doing(robot->x*40-40,robot->y*40+82);
    }
	else
    {
        putsave_chat(robot->x*40+40,robot->y*40);  //恢复聊天框的背后的背景
    }
        aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);  //回到默认位置处

    //*********以下为人起身，吃饭的桌子恢复原状 或 以下为人起身，工作的桌子恢复原状
	if(choice[0]==2)   //假如人选择了工作
	{
		green_bedroom(0, 14);
		green_bedroom(0, 15);
		green_bedroom(0, 16);
		green_bedroom(1, 14);
		green_bedroom(1, 15);
		green_bedroom(1, 16);
		rect_table(0, 13);
		desk(0, 15);
		seat(0, 16);
		pc(0, 15);
		man->x=2;
		man->y=15;
		man->xpixel=2*40;
		man->ypixel=15*40;
		man_forebody(*man,1);
	}
	else if(choice[0]==1) //假如人选择了娱乐
	{
		if(choice[2]==1)  //假如人选择了看电视
        {
            TV_off();
            delay(200);
        }
        else if(choice[2]==2)//假如人选择了听音乐
        {
            music_off(8,10);
            music_off(9,10);
            delay(200);
        }
        wood_ver(14, 12);
        wood_ver(14, 13);
        wood_ver(15, 12);
        wood_ver(15, 13);
		wood_ver(14, 14);
		wood_ver(15, 14);
        sofa_main(14, 11);
		man->x=14;
		man->y=15;
		man->xpixel=14*40;
		man->ypixel=15*40;
		man_forebody(*man,1);
	}
	//*******************
    aimmove(man,man->x,man->y,1,3,G,n,MAN);  //人去洗澡

    put_image_man(man->x*40,man->y*40);
	get_image_bath(40, 40);    				//洗澡的地板的背景存储
    bar(40,40,120,120,65535);
    fdhz(45,45,1,1,"洗澡中",0);				//把人盖住

    aimmove(robot,robot->x,robot->y,5,11,G,n,ROBOT);	//机器人去拿衣服
    delay(500);
    delay(500);
	robot->catch_th = WITH_CLOTHES;						//此时将机器人的状态调整为拿了衣服
    aimmove(robot,robot->x,robot->y,3,4,G,n,ROBOT);     //机器人前往厕所放衣服
	robot->catch_th = WITHOUT_THING;					//此时将机器人的状态调整为没拿衣服


    //***********
    //将衣服画到这个方格内

	clothes(1*40,4*40);

    aimmove(robot,robot->x,robot->y,3,11,G,n,ROBOT);  //去开空调
    delay(500);
    //    空调红灯变绿灯
    aircon(3, 6, 1);
    delay(500);
    aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);  //回到默认位置处

    //*****重新画出浴缸和地板和人
    put_image_bath(40,40);
    glass(1, 4);
    man_forebody(*man,1);
	
	//******************************
    delay(500);
    aimmove(man,man->x,man->y,3,10,G,n,MAN);  		//人走到床旁边

	man_sleep(*man);								//画人睡觉的图
}

//功能：早餐函数
//输入：机器人结构体指针，人结构体指针，鼠标指针，传入选择数组的指针，图
//输出：无
void breakfast(CASE *robot, CASE *man, VType G[], int n)
{
    aimmove(robot,robot->x,robot->y,10,2,G,n,ROBOT);	//机器人到灶台旁边
    saveimage_doing(robot->x*40-40,robot->y*40+82);
    bar(robot->x*40-40,robot->y*40+82,robot->x*40+40,robot->y*40+112,65535);           //准备早餐
    fdhz(robot->x*40-30,robot->y*40+85,1,1,"做饭中",0);
	getch();
    putsave_doing(robot->x*40-40,robot->y*40+82);

	robot->catch_th = WITH_PLATE;
    aimmove(robot,robot->x,robot->y,11,6,G,n,ROBOT);    // 此时手里拿着盘子
	robot->catch_th = WITHOUT_THING;
    aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);     //此时手里没有盘子

    //把盘子放在桌上
	plate(12*40,8*40+20);

    //重新画一遍床（人起床了），并且在旁边把人画上
	man_getup(*man);

    //去洗漱
     aimmove(man,man->x,man->y,1,4,G,n,MAN);  //人到厕所
	put_image_man(man->x*40,man->y*40);      //把人画没
	man_leftbody(*man);						//人侧着站
	saveimage_doing(man->x*40+40,man->y*40+82);
	bar(man->x*40+40,man->y*40+82,man->x*40+120,man->y*40+112,65535);           //xi shu
    fdhz(man->x*40+50,man->y*40+85,1,1,"洗漱中",0);
	getch();
	putsave_doing(man->x*40+40,man->y*40+82);

    aimmove(man,man->x,man->y,10,8,G,n,MAN);  		//人到饭桌旁

    //画一次地板，把人画没，再画一个有人吃饭的桌子
    put_image_man(man->x*40,man->y*40);
    man->xpixel=500;
    man->ypixel=370-60;
    sit_1(*man);
	saveimage_doing(man->xpixel-40,man->ypixel+82);
    bar(man->xpixel-40,man->ypixel+82,man->xpixel+40,man->ypixel+112,65535);           //吃饭
    fdhz(man->xpixel-30,man->ypixel+85,1,1,"吃饭中",0);
    getch();
	putsave_doing(man->xpixel-40,man->ypixel+82);

    //把人画出来，再画一个空的桌子
    	wood_ver(12, 7);
        wood_ver(12, 8);
        wood_ver(12, 9);
        desk(12, 8);
        seat(12, 9);
	seat(12, 7);
	man->xpixel=man->x*40;
	man->ypixel=man->y*40;
    man_forebody(*man,1);         //吃饭的桌子恢复原状

    aimmove(robot,robot->x,robot->y,10,2,G,n,ROBOT);
    saveimage_doing(robot->x*40-40,robot->y*40+82);
	bar(robot->x*40-40,robot->y*40+82,robot->x*40+40,robot->y*40+112,65535);           //洗碗
    fdhz(robot->x*40-30,robot->y*40+85,1,1,"洗碗中",0);
	getch();
	putsave_doing(robot->x*40-40,robot->y*40+82);

	man_forebody(*man,1);
	aimmove(man,man->x,man->y,4,1,G,n,MAN);
	put_image_man(man->x*40,man->y*40);			//把人画没，代表出门

	aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);  //回到默认位置处
}

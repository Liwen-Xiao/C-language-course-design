#include "title.h"
/******************************************************************************************
  函数列表：   1.void guard(CASE human, CASE robot, int identity);             //安保功能
                2.void treatment(CASE *human, CASE *robot, Graph G, int n);     //医疗照顾功能
                3.void clean(case *robot);                                      //打扫卫生功能
******************************************************************************************/
/*函数描述：安保：来人check，检查是主人还是陌生人。若是主人，上前欢迎问候；若是陌生人，
                  则捕捉陌生人图像，通过手机告知主人，并且传送到手机屏幕上，让主人进行识别。
                  如果主人点击“报警”，则自动拨打110，并且机器人会喊：“发现入侵者”，以警告入侵者
                  房子里有机器人在防卫，吓跑入侵者；若主人认为闯入的是熟人，即点击“欢迎”，则机器人会来访者。
  入口参数：分别表示人（闯入者）和机器人的结构体human、robot；
            identity表示人身份（就是闯入者），因为里面调用的paint_man函数需要该参数
            *x，*y，*button是鼠标需要的参数                                                   */
void rbtguard(CASE human, CASE robot, int identity, int *x, int *y, int *button)    //identity表明来的是主人还是陌生人
{
    int judge=0, j;
    paint_man(human, identity);
    if(identity)          //是主人
    {
        delay0(300);    //腾一点时间出来，做识别时间
        saveimage_g_c(robot.xpixel-105, robot.ypixel-40);     //腾出气泡空间

		bar(robot.xpixel-105, robot.ypixel-40, robot.xpixel-15, robot.ypixel,65535);
        fdhz(robot.xpixel-105, robot.ypixel-40,1,1,"主人，",0);
        fdhz(robot.xpixel-105, robot.ypixel-20,1,1,"欢迎回家",0);
        delay0(1500);  //汉字显示持续一段时间
        //void fdhz(int x,int y,int mx,int my,char *s,int color)
        putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //复原
    }
    else
    {
        delay0(300);    //腾一点时间出来，做识别时间
        FillCircle(robot.xpixel-7.5, robot.ypixel+12, 3, 63776);   //眼睛
        FillCircle(robot.xpixel+7.5, robot.ypixel+12, 3, 63776);//调用画眼睛的语句，眼睛变红

        //机器人会说出来，类似于警告入侵者房子里有机器人在监控
        saveimage_g_c(robot.xpixel-105, robot.ypixel-40);     //腾出气泡空间
        bar(robot.xpixel-105, robot.ypixel-20, robot.xpixel-5, robot.ypixel,65535);
        fdhz(robot.xpixel-105, robot.ypixel-20,1,1,"发现入侵者",0);
        //不着急put，最后再来

        //手机上提示主人有人入侵
        iph_frame(65534);
        fdhz(ORIGINX+28, ORIGINY+70,2,2,"发现入侵者",0);
        bar(ORIGINX+45, ORIGINY+155, FINALX-45, ORIGINY+250, 65535);         //人像背景

        //手机上画放大的人像
        human.xpixel = MIDDLEX;		//手机上的人
        human.ypixel = ORIGINY+165;
        man_forebody(human, INTRADER);

        //询问是否报警
        bar(ORIGINX+45, ORIGINY+295, MIDDLEX-10, ORIGINY+355, 63488);   //红色
        fdhz(ORIGINX+65, ORIGINY+315,1,1,"报警",0);
        bar(MIDDLEX+10, ORIGINY+295, FINALX-45, ORIGINY+355, 2016);   //绿色
        fdhz(MIDDLEX+30, ORIGINY+315,1,1,"欢迎",0);

        while(1)
        {
            newxy(x, y, button);

            if(ORIGINX+45<=*x && *x<=MIDDLEX-10 && ORIGINY+295<=*y && *y<=ORIGINY+355 && *button)         //点击“报警”，坐标待定
            {
                judge = 0;
                break;
            }
            else if(MIDDLEX+10<=*x && *x<=FINALX-45 && ORIGINY+295<=*y && *y<=ORIGINY+355 && *button)     //点击“忽略”
            {
                judge = 1;
                break;
            }
        }

		mousehide(*x,*y);

        if(!judge)      //报警
        {
            iph_frame(65534);

            fdhz(ORIGINX+45, ORIGINY+100,2,2,"正在呼叫",0);
            outtextxy(ORIGINX+55, ORIGINY+140,"110",2,2,50, 0);
            delay(2000);
            human.xpixel = human.x*40;
            human.ypixel = human.y*40;      //前面改变了pixel位置，但是x,y大坐标没变，现在变回去，把人覆盖掉
            put_image_man(human.xpixel, human.ypixel);
            putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //气泡
            iph_frame(65534);               //手机恢复

        }
        else
        {
            putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //气泡
            saveimage_g_c(robot.xpixel-105, robot.ypixel-40);     //腾出气泡空间
            bar(robot.xpixel-105, robot.ypixel-40, robot.xpixel-10, robot.ypixel,43001);    //苍色气泡
            fdhz(robot.xpixel-105, robot.ypixel-40,1,1,"你好，欢",0);
            fdhz(robot.xpixel-105, robot.ypixel-20,1,1,"迎你的到来",0);

            delay(2000);
            putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //气泡
			put_image_man(human.xpixel, human.ypixel);
			bar(3 * 40, 1 * 40, 7 * 40, 3 * 40, 65502); //防止人不消失，把门口那块画一遍

			for(j = 1; j < 4; j++)
            {
                w_right(2, j);       //浴室
            }

        }

        FillCircle(robot.xpixel-7.5, robot.ypixel+12, 3, 1023);   //眼睛变回去
        FillCircle(robot.xpixel+7.5, robot.ypixel+12, 3, 1023);

    }

	mousehide(*x,*y);
	iph_page_1();

}
///不需要*choice，main2里面直接传&choice[4]就好了
/*
函数描述：当检测到主人发烧时，端一杯水，询问是否拨打120。如果不拨打，则
          机器人把药箱放在床头供主人自取。
入口参数：人和机器人的结构体指针（因为要移动，改坐标，故必须传指针）
          图G以及图中元素个数n，用于寻路，*x，*y，*button是鼠标用的
          choice指针是main2中传入的choice数组，这里修改choice用来记录是否去了医院
*********************************************/
/**void fdhz(int x,int y,int mx,int my,char *s,int color)*/
void treatment(CASE *human, CASE *robot, Graph G, int n, int *x, int *y, int *button, int *choice)
{
    int i, judge=0;
	iph_page_1();

    aimmove(robot, robot->x, robot->y, 14, 2, G, n, ROBOT);//移动到水杯处
    robot->catch_th = WITH_BOTTLE;   //拿水杯，改变了这个量以后，画图就用fore_hold等持水杯的函数了
	water_dispenser(15, 1);          //重画饮水机，原来的上面覆盖有水杯，现在水杯被拿走了，画空的饮水机

    aimmove(robot, robot->x, robot->y, 2, 8, G, n, ROBOT);      //到床头

    water_bottle(3*40+5, 8*40);                //水杯放在床头的桌上
    robot->catch_th = WITHOUT_THING;        //水杯放下后，回到不持物状态
    saveimage_t_c(robot->xpixel, robot->ypixel-36);    //腾出气泡空间
    bar(robot->xpixel, robot->ypixel-36, robot->xpixel+120, robot->ypixel, 43001);           //画气泡，苍色
    fdhz(robot->xpixel, robot->ypixel-36,1,1,"主人，你",0);
    fdhz(robot->xpixel, robot->ypixel-18,1,1,"好像发烧了",0);
    delay0(500);
    bar(robot->xpixel, robot->ypixel-36, robot->xpixel+120, robot->ypixel, 43001);           //画气泡，苍色
    fdhz(robot->xpixel, robot->ypixel-36,1,1,"需要拨打",0);
    outtextxy(robot->xpixel+90, robot->ypixel-36,"120",1,1,10,0);
    fdhz(robot->xpixel, robot->ypixel-18,1,1,"吗",0);
    delay(500);
    putsave_t_c(robot->xpixel, robot->ypixel-36);    //复原

    //这里是手机上的东西
    iph_frame(65534);
    bar(ORIGINX+45, ORIGINY+155, FINALX-45, ORIGINY+205, 54938);
    bar(ORIGINX+45, ORIGINY+210, FINALX-45, ORIGINY+250, 54938);
    fdhz(ORIGINX+45, ORIGINY+155,1,1,"拨打",0);
    outtextxy(ORIGINX+98, ORIGINY+155,"120",1,1,10,0);
    fdhz(ORIGINX+45, ORIGINY+210,1,1,"休息一下就好",0);

    while(1)
    {
            newxy(x, y, button);

            if(*x>=ORIGINX+45 && *x<=FINALX-45 && *y>=ORIGINY+155 && *y<=ORIGINY+205 && *button)
            //if(ORIGINX+45<=*x && *x<=FINALX-45 && ORIGINY+155<=*y && *y<=ORIGINY+205 && *button)         //点击“拨打120”，坐标待定
            {
                judge = 0;
                break;
            }
            else if(*x>=ORIGINX+45 && *x<=FINALX-45 && *y>=ORIGINY+210 && *y<=ORIGINY+250 && *button)
            //else if(ORIGINX+45<=*x && *x<=FINALX-45 && ORIGINY+210<=*y && *y<=ORIGINY+250 && *button)     //点击“休息一下就好”
            {
                judge = 1;
                break;
            }
    }

	mousehide(*x,*y);

    if(!judge)               //鼠标交互，点击“拨打120”的区域
    {
        iph_frame(65534);
        fdhz(ORIGINX+50, ORIGINY+215,2,2,"正在呼叫",0);
        outtextxy(ORIGINX+50, ORIGINY+255,"120",2,2,50, 0);
        delay0(50);
        bed(0, 7);
        choice[4] = 1;      //打了120，人去医院，第二天不煮饭
    }
    else
    {
        //药箱放到床头方桌
        medical_kit(3*40+5, 7*40);
        saveimage_t_c(robot->xpixel, robot->ypixel-36);    //腾出气泡空间
        bar(robot->xpixel, robot->ypixel-36, robot->xpixel+120, robot->ypixel, 43001);           //画气泡，苍色
        fdhz(robot->xpixel, robot->ypixel-36,1,1,"那我把医疗",0);
        fdhz(robot->xpixel, robot->ypixel-18,1,1,"包放这啦",0);
        putsave_t_c(robot->xpixel, robot->ypixel-36);    //复原
        choice[4] = 0;      //没打120，第二天煮饭
    }

    aimmove(robot, robot->x, robot->y, 13, 3, G, n, ROBOT);     //回到原来的位置
    
	iph_page_1();

}

/********随机生成垃圾，再自动寻路拾取******/
void clean(CASE *robot, CASE *human, Graph G, int n)     //一大堆坐标点没解决
{
    Axis V1 = {12, 13}, V2 = {12, 13}, V3 = {12, 13}, Vtemp, Vex[3];
    int i, j, a, b, c;  //a，b，c是用来存随机数，选定垃圾样式的

    //三种垃圾的横纵坐标（大坐标），这样初始化的目的是：确保数组不越界，又保证会进入while
    //V1，V2,V3就是要产生垃圾的点，Vex根据各点与机器人的位置进行排序
    //下面这张图专门给trash用，和机器人寻路没关系
     const static int unaccessible[16][19]={
                                //[4][14],[5][4],[9][9]
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //第一列
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                                {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //第16列
                            };

    //这个图和findway里面有一点区别，因为要求机器人在trash左边捡垃圾，
    //所以现在把这个数组中，本身是0但上一行（也就是左边）为0的都设为1，不可达
    get_image_man(human->xpixel, human->ypixel);
    srand(time(NULL));       //随机数种子

    while(unaccessible[V1.x-1][V1.y] && unaccessible[V1.x][V1.y-1])   //前一个条件保证机器人能到达垃圾左边，后一个条件保证垃圾出现的地方没有别的东西
    {
        V1.x = rand()%15+1;
        V1.y = rand()%18+1;
    }

    while(unaccessible[V2.x-1][V2.y] && unaccessible[V2.x][V2.y-1])
    {
        V2.x = rand()%15+1;
        V2.y = rand()%18+1;
    }

    while(unaccessible[V3.x-1][V3.y] && unaccessible[V3.x][V3.y-1])
    {
        V3.x = rand()%15+1;
        V3.y = rand()%18+1;
    }

    //接下来按距离排序（选择排序法）
    Vex[0] = V1;
    Vex[1] = V2;
    Vex[2] = V3;

    for(i = 0; i < 2; i++)
    {
        for(j = i + 1; j < 3; j++)
        {   //排序准则是1范数距离，不是欧式距离
            if(abs(Vex[i].x - robot->x) + abs(Vex[i].y - robot->y) > abs(Vex[j].x - robot->x) + abs(Vex[j].y - robot->y)) //1范数距离，不是欧式距离
            {
                Vtemp = Vex[i];
                Vex[i] = Vex[j];
                Vex[j] = Vtemp;
            }
        }
    }

    //把三种垃圾的背景存起来
    get_image_trash1(Vex[0].x*40, Vex[0].y*40);
    get_image_trash2(Vex[1].x*40, Vex[1].y*40);
    get_image_trash3(Vex[2].x*40, Vex[2].y*40);

    //下面产生随机数，来决定三个产生垃圾的坐标点，各自产生的垃圾的种类
    a = rand()%3+1;

    do{
        b = rand()%3+1;
    }while(b == a);     //确保a、b不相等

    do{
        c = rand()%3+1;
    }while(c == a || c == b);   //确保c不与a、b相等

    //下面根据随机数的值来确定各位置垃圾的样式
    switch(a)
    {
        case 1:     //若a为1，Vex[0]处画第一种垃圾，即纸张
            trash1(Vex[0].x, Vex[0].y);
            break;
        case 2:     //若a为2，Vex[0]处画第二种垃圾
            trash2(Vex[0].x, Vex[0].y);
            break;
        case 3:     //若a为3，Vex[0]处画第三种垃圾，即纸张
            trash3(Vex[0].x, Vex[0].y);
            break;
    }

    switch(b)
    {
        case 1:     //若b为1，Vex[1]处画第一种垃圾，即纸张
            trash1(Vex[1].x, Vex[1].y);
            break;
        case 2:     //若b为2，Vex[1]处画第二种垃圾
            trash2(Vex[1].x, Vex[1].y);
            break;
        case 3:     //若b为3，Vex[1]处画第三种垃圾
            trash3(Vex[1].x, Vex[1].y);
            break;
    }

    switch(c)
    {
        case 1:     //若c为1，Vex[2]处画第一种垃圾，即纸张
            trash1(Vex[2].x, Vex[2].y);
            break;
        case 2:     //若c为2，Vex[2]处画第二种垃圾
            trash2(Vex[2].x, Vex[2].y);
            break;
        case 3:     //若c为3，Vex[2]处画第三种垃圾
            trash3(Vex[2].x, Vex[2].y);
            break;
    }

    //跑到trash左边一格，把trash处背景释放
    aimmove(robot, robot->x, robot->y, Vex[0].x-1, Vex[0].y, G, n, ROBOT);      //到垃圾a处，Vex[0]
    put_image_trash1(Vex[0].x*40, Vex[0].y*40);                                 //释放背景

	aimmove(robot, robot->x, robot->y, Vex[1].x-1, Vex[1].y, G, n, ROBOT);      //到垃圾b处，Vex[1]
    put_image_trash2(Vex[1].x*40, Vex[1].y*40);                                 //释放背景

	aimmove(robot, robot->x, robot->y, Vex[2].x-1, Vex[2].y, G, n, ROBOT);      //到垃圾c处，Vex[2]
    put_image_trash3(Vex[2].x*40, Vex[2].y*40);                                 //释放背景

	aimmove(robot, robot->x, robot->y, 8, 2, G, n, ROBOT);    //扔到垃圾箱

    aimmove(robot, robot->x, robot->y, 13, 4, G, n, ROBOT);    //回到原位
}



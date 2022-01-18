#include "title.h"
/*******************************************************
函数列表：   1.void paint_robot(CASE case_state)      //第一次画机器人时调用，将画机器人处的背景储存，并画出机器人正面
              2.void forebodyhead(CASE case_state)              //机器人正面
              3.void backbodyhead(CASE case_state)              //机器人背面
              4.void robot_left(CASE case_state)                //机器人左面
              5.void robot_right(CASE case_state)               //机器人右面
              6.void robot_hand_right(int x,int y,int theta)    //机器人的手，指向右侧，封装后在上面所述的几个函数中调用
              7.void robot_hand_left(int x,int y,int theta)     //机器人的手，指向左侧，封装后在上面所述的几个函数中调用
              8.void right_hold(CASE case_state)                //机器人手持物品向右走
              9.void left_hold(CASE case_state)                 //机器人手持物品向左走
              10.void front_hold(CASE case_state)               //机器人手持物品向下走（即正面）
              11.void back_hold(CASE case_state)                //机器人手持物品向上走（即背面）
********************************************************/

//函数功能：第一次画人时，将机器人的背景储存，并画出机器人的正面
void paint_robot(CASE case_state)
{
	 //获取机器人背景并绘制机器人
	get_image_robot(case_state.xpixel, case_state.ypixel);
    forebodyhead(case_state);
}

//画机器人的正面，传入表示机器人的结构体提供画机器人像的位置
void forebodyhead(CASE case_state)//范围：case_state.xpixel+-30;
{
	robot_hand_right(case_state.xpixel+4,case_state.ypixel+56,45);
	robot_hand_left(case_state.xpixel-28,case_state.ypixel+65,-45);
	//头
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 9, 0);    //先画黑再覆盖，相当于有了轮廓
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 8, 65535);

    FillCircle(case_state.xpixel-7.5, case_state.ypixel+12, 3, 1023);   //眼睛
    FillCircle(case_state.xpixel+7.5, case_state.ypixel+12, 3, 1023);
    //不要嘴巴也行
   // bow(case_state.xpixel-7.5, case_state.ypixel+12, 7.5/sin(3.14159/12), 0);
    //脚
    bar(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 65535);
    linever(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel-15, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+70, 30, 0);
    linever(case_state.xpixel, case_state.ypixel+60, case_state.xpixel, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);
    //身体
	bar(case_state.xpixel-16, case_state.ypixel + 19,case_state.xpixel+16, case_state.ypixel + 61, 0);//边框
	bar(case_state.xpixel-15, case_state.ypixel + 20,case_state.xpixel+15, case_state.ypixel + 60, 65535);//入口是中心。。。
    circle(case_state.xpixel, case_state.ypixel + 40, 10, 0);   //不填充
    Horizline(case_state.xpixel-15, case_state.ypixel+60, 30, 0);
    //暂时不画红十字

}

//画机器人的背面，传入表示机器人的结构体提供画机器人像的位置
void backbodyhead(CASE case_state)//范围：x+30,-30,y-80~y;
{
	robot_hand_right(case_state.xpixel+4,case_state.ypixel+56,45);
	robot_hand_left(case_state.xpixel-28,case_state.ypixel+65,-45);
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 9, 0);    //先画黑再覆盖，相当于有了轮廓
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 8, 65535);
    putpixel(case_state.xpixel-7.5, case_state.ypixel+12, 0);   //眼睛
    putpixel(case_state.xpixel+7.5, case_state.ypixel+12, 0);

    //脚
    bar(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 65535);
    linever(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel-15, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+70, 30, 0);
    linever(case_state.xpixel, case_state.ypixel+60, case_state.xpixel, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

     //身体
	bar(case_state.xpixel-16, case_state.ypixel + 19,case_state.xpixel+16, case_state.ypixel + 61, 0);//边框
	bar(case_state.xpixel-15, case_state.ypixel + 20,case_state.xpixel+15, case_state.ypixel + 60, 65535);//入口是中心。。。
    Horizline(case_state.xpixel-15, case_state.ypixel+60, 30, 0);
}

//画机器人的左面，传入表示机器人的结构体提供画机器人像的位置
void robot_left(CASE case_state)//x-10~x+10,y-80~y
{
    //头
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel-4, case_state.ypixel+15, 3, 1023); //眼睛

    ///手向左，头也向左，故不论左手还是右手，调用的都是robot_hand_left函数
    //右手
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+67,-45+case_state.hand_right);

    //身体
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //脚
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    //左手
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+71,-45-case_state.hand_right);

}

//画机器人的右面，传入表示机器人的结构体提供画机器人像的位置
void robot_right(CASE case_state)//x-10~x+10,y-80~y，手和头都向右
{
    //头
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel+4, case_state.ypixel+15, 3, 1023); //眼睛

    ///手向右，头也向右，故不论左手还是右手，调用的都是robot_hand_right函数
    //左手
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+58,45-case_state.hand_left);

    //身体
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //脚
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    //右手
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+62,45+case_state.hand_left);

}

//函数功能：画出机器人的手，指向右侧，封装后在上面所述的几个函数中调用
//入口参数：小像素点，表示画这只手的位置；theta角控制手摆动的角度，传入以后给theta_bar函数调用
void robot_hand_right(int x,int y,int theta)
{
    ///屏幕上看，这只手在大白右边，实际上是大白的左手
    ///如果想要在(0,0)弄上这只手的顶点，用的是(xpixel+10, ypixel+40)
    //color为0的稍微大一个像素点的theta_bar，就是留一个边沿（先画大一点，之后被覆盖），color为65535就是大白的颜色
    theta_bar(x-1,y-29,(int)(12/sin((double)(theta)/180*PI)),(int)(12/sin((double)(theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(theta)/180*PI)),(int)(10/sin((double)(theta)/180*PI)),theta,65535);
	FillCircle(x+(int)(16/tan((double)(theta)/180*PI))+5,y-(int)(24*sin((double)(theta)/180*PI))-2,7,0);
    FillCircle(x+(int)(16/tan((double)(theta)/180*PI))+5,y-(int)(24*sin((double)(theta)/180*PI))-2,6,65535);
}

//函数功能：画出机器人的手，指向左侧，封装后在上面所述的几个函数中调用
//入口参数同robot_hand_right
void robot_hand_left(int x,int y,int theta)
{
    ///注意事项也同上面的robot_hand_right
    ///在(xpixel,ypixel)=(40,40)画这只手，大约是(xpixel-20, ypixel+50),即(20,90)
    theta_bar(x-1,y-29,(int)(12/sin((double)(-1*theta)/180*PI)),(int)(12/sin((double)(-1*theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(-1*theta)/180*PI)),(int)(10/sin((double)(-1*theta)/180*PI)),theta,65535);
	FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-13,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,7,0);
    FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-13,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,6,65535);
}

///以下每个持物寻走的函数中，放物品的位置都是需要具体微调的，所以无法用一个统一的画物品的函数去封装
//画出机器人手持物品向右走的图像，传入表示机器人的结构体提供画机器人像的位置
void right_hold(CASE case_state)    //向右转，看到右手侧与物体
{
	///以下每个部件的代码和robot_right完全一致，但是为了得到手->物品->身体的层次感，
	///在画右手前插入了物品，因此不能直接调用函数解决问题只能出现重复代码代码

	//头
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel+4, case_state.ypixel+15, 3, 1023); //眼睛

    //左手
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+58,45+case_state.hand_left);

    //身体
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //脚
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    if(case_state.catch_th == WITH_BOTTLE)          //拿水杯
    {
        water_bottle(case_state.xpixel+16, case_state.ypixel+31);
    }
    else if(case_state.catch_th == WITH_CLOTHES)    //拿衣服
    {
        clothes(case_state.xpixel+5, case_state.ypixel+31);
    }
    else if(case_state.catch_th == WITH_PLATE)      //端碟子
    {
        plate(case_state.xpixel-10, case_state.ypixel+31);
    }

    //右手
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+62,45+case_state.hand_left);

}

//画出机器人手持物品向左走的图像，传入表示机器人的结构体提供画机器人像的位置
void left_hold(CASE case_state)//向左拿东西的图像
{
    //右手
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+67,-45-case_state.hand_right);

    if(case_state.catch_th == WITH_BOTTLE)              //拿水杯
    {
        water_bottle(case_state.xpixel-25, case_state.ypixel+28);
    }
    else if(case_state.catch_th == WITH_CLOTHES)        //拿衣服
    {
        clothes(case_state.xpixel-20, case_state.ypixel+28);
    }
    else if(case_state.catch_th == WITH_PLATE)          //端碟子
    {
        plate(case_state.xpixel-20, case_state.ypixel+32);
    }

    //头
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel-4, case_state.ypixel+15, 3, 1023); //眼睛

    //身体
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //脚
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    //左手
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+71,-45-case_state.hand_right);

}

//画出机器人手持物品向下走的图像（正面），传入表示机器人的结构体提供画机器人像的位置
void front_hold(CASE case_state)
{
    //水杯直接贴上去，覆盖在机器人的正面就好了。注意是先画机器人，再画物品，注意层次感。
    forebodyhead(case_state);
    if(case_state.catch_th == WITH_BOTTLE)
    {
        water_bottle(case_state.xpixel-30, case_state.ypixel+23);
    }
    else if(case_state.catch_th == WITH_CLOTHES)
    {
        clothes(case_state.xpixel-20, case_state.ypixel+27);
    }
    else if(case_state.catch_th == WITH_PLATE)
    {
        plate(case_state.xpixel-20, case_state.ypixel+29);
    }
}

//画出机器人手持物品向上走的图像（背面），传入表示机器人的结构体提供画机器人像的位置
void back_hold(CASE case_state)
{
    //注意是先画物品，再画机器人，注意层次感。
    if(case_state.catch_th == WITH_BOTTLE)
    {
        water_bottle(case_state.xpixel+20, case_state.ypixel+23);
    }
    else if(case_state.catch_th == WITH_CLOTHES)
    {
        clothes(case_state.xpixel+10, case_state.ypixel+27);
    }
    else if(case_state.catch_th == WITH_PLATE)
    {
        plate(case_state.xpixel+10, case_state.ypixel+27);
    }
    backbodyhead(case_state);
}


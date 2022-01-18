#include "title.h"
/****************************************************************
函数列表：   1.void paint_man(CASE case_state, int identity)           //第一次画人的时候调用，会画出人的正面
              2.void man_forebody(CASE case_state, int identity)        //人的正面，包括主人与陌生人
              3.void man_backbody(CASE case_state)                      //人的背面
              4.void man_rightbody(CASE case_state)                     //人的右面
              5.void man_leftbody(CASE case_state)                      //人的左面
              6.void man_sleep(CASE case_state)                         //睡觉时的人像
              7.void man_getup(CASE case_state)                         //起床
              8.void sit_1(CASE case_state)                             //背面坐姿，工作和吃饭时调用
              9.void sit_2(CASE case_state)                             //侧面坐姿，娱乐时调用
*****************************************************************/

//函数功能：第一次画人时，将人的背景储存，并画出人的正面
//入口参数：表示人的结构体，以及一个表身份的形参identity，
//          identity为MASTER(即1)时为主人，为INTRADER(即0)时为入侵者
void paint_man(CASE case_state, int identity)
{
    //获取画人的空间。第一次画人的时候用此函数，主要是为了get_image
    get_image_man(case_state.xpixel, case_state.ypixel);
    man_forebody(case_state, identity);
}

//函数功能：画出人的正面
//入口参数同上面的paint_man
void man_forebody(CASE case_state, int identity)  //x-20,x+20,y+80,y
{
    int color[2][5] = {{HAIRI, SKINI, EYESI, ARMSI, PANTSI},{HAIRM, SKINM, EYESM, ARMSM, PANTSM}};
    ///color[0]是画主人用的颜色，color[1]是陌生人的。
    ///注意到identity是0和1，正好可以表示数组的第一维和第二维，这样处理可以减去一大批重复代码

    //头
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+8, color[identity][0]);    //头发
    bar(case_state.xpixel-9, case_state.ypixel+9, case_state.xpixel+9, case_state.ypixel+19, color[identity][1]);    //皮肤
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 1, color[identity][2]);      //左眼，眼珠
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 1, color[identity][2]);      //右眼，眼珠
    Horizline(case_state.xpixel-3, case_state.ypixel+16, 6, 0);    //嘴

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+25,color[identity][1]);

    //上身
    bar(case_state.xpixel-18, case_state.ypixel+25, case_state.xpixel+18, case_state.ypixel+50, color[identity][3]);     //包含手的部分
    linever(case_state.xpixel-10, case_state.ypixel+35, case_state.xpixel-10, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+10, case_state.ypixel+35, case_state.xpixel+10, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-9, case_state.ypixel+50, case_state.xpixel+9, case_state.ypixel+55, color[identity][3]);     //衣服
    bar(case_state.xpixel-18, case_state.ypixel+50, case_state.xpixel-11, case_state.ypixel+55, color[identity][1]);     //手
    bar(case_state.xpixel+11, case_state.ypixel+50, case_state.xpixel+18, case_state.ypixel+55, color[identity][1]);

    //腿
    bar(case_state.xpixel-9, case_state.ypixel+55, case_state.xpixel+9, case_state.ypixel+73, color[identity][4]);       //裤子
    linever(case_state.xpixel, case_state.ypixel+55, case_state.xpixel, case_state.ypixel+80, 1, 0);

    //脚（鞋子）
    bar(case_state.xpixel-9, case_state.ypixel+74, case_state.xpixel+9, case_state.ypixel+80, 0);
}

//画人的背面，传入表示人的结构体提供画人像的位置
void man_backbody(CASE case_state)
{
     //头
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+19, 41605);    //赭黄，头发

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+25,63222);    //米黄色，肤色

    //上身
    bar(case_state.xpixel-18, case_state.ypixel+25, case_state.xpixel+18, case_state.ypixel+50, 65504);     //包含手的部分
    linever(case_state.xpixel-10, case_state.ypixel+35, case_state.xpixel-10, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+10, case_state.ypixel+35, case_state.xpixel+10, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-9, case_state.ypixel+50, case_state.xpixel+9, case_state.ypixel+55, 65504);     //穿着亚麻色的衣服
    bar(case_state.xpixel-18, case_state.ypixel+50, case_state.xpixel-11, case_state.ypixel+55, 63222);
    bar(case_state.xpixel+11, case_state.ypixel+50, case_state.xpixel+18, case_state.ypixel+55, 63222);

    //腿
    bar(case_state.xpixel-9, case_state.ypixel+55, case_state.xpixel+9, case_state.ypixel+73, 29186);       //乌贼墨色的裤子
    linever(case_state.xpixel, case_state.ypixel+55, case_state.xpixel, case_state.ypixel+80, 1, 0);

    //脚（鞋子）
    bar(case_state.xpixel-9, case_state.ypixel+74, case_state.xpixel+9, case_state.ypixel+80, 0);
}

//画人的右面，传入表示人的结构体提供画人像的位置
void man_rightbody(CASE case_state)      //x-10, x+10, y+80,y
{
    //头
    bar(case_state.xpixel-10, case_state.ypixel, case_state.xpixel-1, case_state.ypixel+20, 41605);
    bar(case_state.xpixel-1, case_state.ypixel, case_state.xpixel+10, case_state.ypixel+8, 41605);
    bar(case_state.xpixel-1, case_state.ypixel+9, case_state.xpixel+10, case_state.ypixel+20, 63222);
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 1, 65535);
    Horizline(case_state.xpixel+6, case_state.ypixel+18, 3, 0);

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+21, case_state.xpixel+4, case_state.ypixel+25, 63222);

    //上身
    bar(case_state.xpixel-10, case_state.ypixel+26, case_state.xpixel+10, case_state.ypixel+55, 65504);
    linever(case_state.xpixel-5, case_state.ypixel+28, case_state.xpixel-5, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+5, case_state.ypixel+28, case_state.xpixel+5, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-4, case_state.ypixel+50, case_state.xpixel+5, case_state.ypixel+55, 63222);   //手
    Horizline(case_state.xpixel-5, case_state.ypixel+55, 10, 0);

    //腿
    bar(case_state.xpixel-8, case_state.ypixel+55, case_state.xpixel+8, case_state.ypixel+73, 29186);       //乌贼墨色的裤子
    //脚（鞋子）

    bar(case_state.xpixel-8, case_state.ypixel+74, case_state.xpixel+8, case_state.ypixel+80, 0);
}

//画人的左面，传入表示人的结构体提供画人像的位置
void man_leftbody(CASE case_state)
{
    //头
    bar(case_state.xpixel+1, case_state.ypixel, case_state.xpixel+10, case_state.ypixel+20, 41605);
    bar(case_state.xpixel-10, case_state.ypixel, case_state.xpixel+1, case_state.ypixel+8, 41605);
    bar(case_state.xpixel-10, case_state.ypixel+9, case_state.xpixel+1, case_state.ypixel+20, 63222);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 1, 65535);
    Horizline(case_state.xpixel-6, case_state.ypixel+18, -3, 0);

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+21, case_state.xpixel+4, case_state.ypixel+25, 63222);

    //上身
    bar(case_state.xpixel-10, case_state.ypixel+26, case_state.xpixel+10, case_state.ypixel+55, 65504);
    linever(case_state.xpixel-5, case_state.ypixel+28, case_state.xpixel-5, case_state.y+55, 1, 0);
    linever(case_state.xpixel+5, case_state.ypixel+28, case_state.xpixel+5, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-4, case_state.ypixel+50, case_state.xpixel+5, case_state.ypixel+55, 63222);   //手
    Horizline(case_state.xpixel-5, case_state.ypixel+55, 10, 0);

    //腿
    bar(case_state.xpixel-8, case_state.ypixel+55, case_state.xpixel+8, case_state.ypixel+73, 29186);       //乌贼墨色的裤子

    //脚（鞋子）
    bar(case_state.xpixel-8, case_state.ypixel+74, case_state.xpixel+8, case_state.ypixel+80, 0);
}

//函数功能：time_line中，人去睡觉时，将站着的人像以类似put_image的方式移除，恢复背景，再在床上画出人睡觉的图像
//入口参数：表示人的结构体，提供画人像的位置
void man_sleep(CASE case_state) //上床睡觉
{
    //直接床上画人的头即可，不用get、put，但是要事先把站着的人的图像隐藏，也即，put
    put_image_man(case_state.xpixel, case_state.ypixel);
	case_state.xpixel = 0.75*40+5;		//头的位置，暂时改变，+5是因为给床多加了5个偏移量
	case_state.ypixel = 6.8*40;

    //头
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+8, HAIRM);    //头发
    bar(case_state.xpixel-9, case_state.ypixel+9, case_state.xpixel+9, case_state.ypixel+19, SKINM);    //皮肤

    Horizline(case_state.xpixel-6, case_state.ypixel+10, 4, 0);     //左眼（闭眼）
    Horizline(case_state.xpixel+2, case_state.ypixel+10, 4, 0);     //右眼（闭眼）
    Horizline(case_state.xpixel-3, case_state.ypixel+16, 6, 0);    //嘴

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+21,SKINM);
}

//函数功能：把床上睡觉的人去除，并在相应位置画出站立的人
//入口参数：表示人的结构体，提供画人像的位置
void man_getup(CASE case_state) //起床
{
    //重画一张床，就可以把头覆盖了。再把人画出来。
    bed(0, 7);
    paint_man(case_state, MASTER);
}

//人工作时和吃饭时的背面坐姿，传入表示人的结构体提供画人像的位置
void sit_1(CASE case_state)  //背面坐姿
{
    //头，实际上只需要画头发
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+19, 41605);    //赭黄，头发

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+25,63222);    //米黄色，肤色

    //上身
    bar(case_state.xpixel-18, case_state.ypixel+25, case_state.xpixel+18, case_state.ypixel+40, 65504);     //包含手的部分
    bar(case_state.xpixel-9, case_state.ypixel+40, case_state.xpixel+9, case_state.ypixel+50, 65504);
    bar(case_state.xpixel-9, case_state.ypixel+50, case_state.xpixel+9, case_state.ypixel+55, 65504);     //穿着亚麻色的衣服
    linever(case_state.xpixel-10, case_state.ypixel+35, case_state.xpixel-10, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+10, case_state.ypixel+35, case_state.xpixel+10, case_state.ypixel+55, 1, 0);

    //屁股
    bar(case_state.xpixel-9, case_state.ypixel+55, case_state.xpixel+9, case_state.ypixel+63, 29186);       //乌贼墨色的裤子
}

//人娱乐时的侧面坐姿，传入表示人的结构体提供画人像的位置
void sit_2(CASE case_state)  //侧面坐姿
{
     //头
    bar(case_state.xpixel+1, case_state.ypixel, case_state.xpixel+10, case_state.ypixel+20, 41605);
    bar(case_state.xpixel-10, case_state.ypixel, case_state.xpixel+1, case_state.ypixel+8, 41605);
    bar(case_state.xpixel-10, case_state.ypixel+9, case_state.xpixel+1, case_state.ypixel+20, 63222);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 1, 65535);
    Horizline(case_state.xpixel-6, case_state.ypixel+18, -3, 0);

    //脖子
    bar(case_state.xpixel-4, case_state.ypixel+21, case_state.xpixel+4, case_state.ypixel+25, 63222);

    //上身
    bar(case_state.xpixel-10, case_state.ypixel+26, case_state.xpixel+10, case_state.ypixel+55, 65504);
    linever(case_state.xpixel-5, case_state.ypixel+28, case_state.xpixel-5, case_state.y+55, 1, 0);
    linever(case_state.xpixel+5, case_state.ypixel+28, case_state.xpixel+5, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-4, case_state.ypixel+50, case_state.xpixel+5, case_state.ypixel+55, 63222);   //手
    Horizline(case_state.xpixel-5, case_state.ypixel+55, 10, 0);

    //腿
    bar(case_state.xpixel-18, case_state.ypixel+55, case_state.xpixel+8, case_state.ypixel+62, 29186);       //乌贼墨色的裤子
    bar(case_state.xpixel-18, case_state.ypixel+62, case_state.xpixel-6, case_state.ypixel+70, 29186);
    bar(case_state.xpixel-18, case_state.ypixel+70, case_state.xpixel-6, case_state.ypixel+76, 0);
}


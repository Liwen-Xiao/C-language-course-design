#include "title.h"
/****************************************************************************
函数列表：   1.paint_floor();      //画地板
              2.paint_wall();       //画墙壁
              3.paint_furniture();  //画家具
功能：     调用封装在bricks.c、wall.c和frnture.c中的函数，画出房子主界面
****************************************************************************/

void paint_house()
{
    paint_floor();      //画地板
    paint_wall();       //画墙壁
    paint_furniture();  //画家具
}

void paint_floor()      //地板
{
    int i, j;

    bar(3*40, 1*40, 7*40, 3*40, 65502);         //整体背景画成白色，如果不这样处理，背景是黑的

    for(i = 3; i < 7; i++)      //大门处
    {
        for(j = 3; j < 6; j++)
        {
            wood_ver(i, j);
        }
    }

    for(i = 7; i < 16; i++)      //客厅主体
    {
        for(j = 3; j < 19; j++)
        {
            wood_ver(i, j);
        }
    }

    ///以上把客厅部分画完了，下面是各个小房间

    for(i = 0; i < 3; i++)    //bathroom
    {
        for(j = 1; j < 6; j++)
        {
            glass(i, j);
        }
    }

    for(j = 1; j < 3; j++)    //kitchen
    {
        for(i = 7; i < 16; i++) //i的循环更长，放里面提高效率
        {
            green_kitchen(i, j);
        }
    }

    for(i = 0; i < 7; i++)    //bedroom
    {
        for(j = 7; j < 19; j++)
        {
            green_bedroom(i, j);
        }
    }

}

void paint_wall()       //墙壁
{
    int i, j;

    for(i = 0; i < 7; i++)      //顶上的和卧室的
    {
        w_blue(i, 0);
        w_blue(i, 6);
    }

    for(i = 7; i < 16; i++)     //顶上的（因为卧室只画到 i = 6为止，顶上的剩余部分单独遍历）
    {
        w_blue(i, 0);
    }

    for(j = 11; j < 19; j++)     //卧室与客厅交界
    {
        w_right(6, j);
    }

    for(j = 0; j < 19; j++)     //房子最右
    {
        w_right(15, j);
    }

    for(j = 1; j < 3; j++)  //厨房左
    {
        w_left(7, j);
    }

    for(j = 1; j < 4; j++)
    {
        w_right(2, j);       //浴室
    }

}

void paint_furniture()  //家具
{
    //bedroom
    bed(0, 7);
    rect_table(3, 7);
    aircon(3, 6, 0);
    bookshelf(6, 11);
    bookshelf(6, 12);
    bookshelf(6, 13);
    bookshelf(6, 14);
    cupboard(6, 11);
    rect_table(0, 13);
    desk(0, 15);
    seat(0, 12);
    seat(2, 14);
    seat(0, 16);
    pc(0, 15);

    //reception room
    rect_table(11, 12);
    desk(12, 8);
    seat(12, 7);    //饭桌旁边的小板凳
    seat(13, 7);
    seat(11, 8);
    seat(14, 8);
    seat(12, 9);
    seat(13, 9);
    TV(7, 10.5);
    sofa_main(14, 11);
    sofa_up(11, 10);
    sofa_down(11, 14.5);

    //bathroom
    window_close(1, 0);
    WashMach(0, 1);
    toilet(0, 3);

    //kitchen
    trashbin(7, 2);
    water_dispenser(15, 1);
    zaotai(9, 1);
    desk(12, 1);    //放水杯的桌子
    water_bottle(15.5*40, 2.4*40);
}

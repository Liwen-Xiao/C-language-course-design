#include "title.h"
/*****************************************************************
函数列表： 1.void dmove(CASE *case_state, int casetype)      //改变坐标点
            2.void move0(CASE *case_state, int casetype)      //坐标的改变与动作叠加
            3.int aimmove(CASE *case_state,int x0,int y0,int xt,int yt,const Graph G, const int n, int casetype)    //让机器人移动时需要直接调用的函数
*****************************************************************/
/*函数描述：dmove是每一次移动的最小单位函数，只改变坐标，然后直接画出这个时候的机器人或者人的图像，并不涉及到手的摆动；
  入口参数：表示机器人或人的状态的结构指针case_state，因为改变坐标需要址传递
            casetype用于表示是人还是机器人，MAN，即1，是人，ROBOT，即0，是机器人
*/
void dmove(CASE *case_state, int casetype)    //要改变状态，所以应该传指针，casetype为0是机器人，1是人
{
	int x0 = case_state->xpixel, y0 = case_state->ypixel;

	//判断方向并移动相应距离（以像素点计）
	if(!casetype)   //是机器人
	{
	    switch(case_state->direction)
        {
            case 1:         //向右走
            {
                if(case_state->catch_th == WITHOUT_THING)   //手上没拿东西
                {
                    robot_right(*case_state);       //画出向右走的图像
                }
                else    //手上有水杯或衣服或盘子
                {
                    right_hold(*case_state);
                }
                x0 = x0 + 10;
                break;
            }
            case 2:         //向左
            {
                if(case_state->catch_th == WITHOUT_THING)   //手上没拿东西
                {
                    robot_left(*case_state);       //画出向左走的图像
                }
                else    //手上有水杯或衣服或盘子
                {
                    left_hold(*case_state);
                }
                x0 = x0 - 10;
                break;
            }
            case 3:         //向上
            {
                if(case_state->catch_th == WITHOUT_THING)   //手上没拿东西
                {
                    backbodyhead(*case_state);
                }
                else    //手上有水杯或衣服或盘子
                {
                    back_hold(*case_state);
                }
                y0 = y0 - 10;
                break;
            }
            case 4:         //向下
            {
                if(case_state->catch_th == WITHOUT_THING)
                {
                    forebodyhead(*case_state);
                }
                else    //手上有水杯或衣服或盘子
                {
                    front_hold(*case_state);
                }
                y0 = y0 + 10;
                break;
            }
        }

        delay(80); //保持图像
        put_image_robot(case_state->xpixel, case_state->ypixel);

	}
    else        //是人
    {
        switch(case_state->direction)
        {
            case 1:         //向右走
            {
                man_rightbody(*case_state);
                x0 = x0 + 10;
                break;
            }
            case 2:         //向左
            {
                man_leftbody(*case_state);
                x0 = x0 - 10;
                break;
            }
            case 3:         //向上
            {
                man_backbody(*case_state);
                y0 = y0 - 10;
                break;
            }
            case 4:         //向下
            {
                man_forebody(*case_state, 1);   //一定是主人移动，陌生人只是出现并check，不需要他移动
                y0 = y0 + 10;
                break;
            }
        }

        delay(80); //保持图像
        put_image_man(case_state->xpixel, case_state->ypixel);

	}

	case_state->xpixel = x0;  //改变位置
	case_state->ypixel = y0;
	case_state->x = (case_state->xpixel + 2)/40;        //根据现在小坐标的情况调整大坐标
	case_state->y = (case_state->ypixel + 2)/40;        //给两个偏移量是因为2个像素点本身并无大碍，为了防止边界处发生潜在的故障

	if(!casetype)       //机器人
    {
        get_image_robot(case_state->xpixel, case_state->ypixel);
    }
    else                //人
    {
        get_image_man(case_state->xpixel, case_state->ypixel);
    }

}

/*函数描述：将dmove中坐标的改变（即位置的移动）与动作的改变融合，相当于运动的叠加
  入口参数：同dmove*/
void move0(CASE *case_state, int casetype)
{
	int i;
	if(!casetype)       //机器人
    {
        put_image_robot(case_state->xpixel, case_state->ypixel);
    }
    else
    {
        put_image_man(case_state->xpixel, case_state->ypixel);
    }

	//按一定的间隔改变机器人的位置
	for(i=0;i<4;i++)
	{
		//改变手的角度
		if(case_state->hand)
		{
			case_state->hand_left++;
			case_state->hand_right--;
		}
		else//初始化时为0，即动右手
		{
			case_state->hand_right++;
			case_state->hand_left--;
		}
		if((case_state->hand_right>=10)||(case_state->hand_left>=10)||(case_state->hand_right<=-10)||(case_state->hand_left<=-10))
		{
			case_state->hand=!case_state->hand;
		}
		//前面这些部分是在改变动作，相当于做一个走路的图画
		//后面调用dmove就是真的在移动了
///可以这样理解，走路的动画是：“在原地改变动作（即这段注释上面的部分）+不在意动作，给位置平移2个像素点”的叠加
		//调用最小移动单元
		dmove(case_state,casetype);
	}
	//更新位置
	case_state->x = case_state->xpixel/40;
	case_state->y = case_state->ypixel/40;

	if(!casetype)
    {
        forebodyhead(*case_state);
    }
    else
    {
        man_forebody(*case_state, 1);
    }

}

/*
函数综述： case_state的x、y坐标会到move0，然后再进到demove0，然后才被改变
            demove0中，根据方向，移动两个像素点，改变case_state
函数功能： 给定从起始点到终止点的最短路径，人和机器人共用此函数
入口参数： 表示机器人或人的状态的结构指针case_state，起始点、终止点的x、y坐标（大坐标）
            图G以及G中元素个数n，casetype用于表示是人还是机器人
*/
int aimmove(CASE *case_state,int x0,int y0,int xt,int yt,const Graph G, const int n, int casetype)//以(0,0)为开始，大像素点
{
	Axis V0, Vt;        //传给findway

	///path传给findway，然后用入栈S，再把S弹出放回path
	PathType *path = NULL, *t = NULL;      //t是入栈出栈时用的暂存变量
	LkStack S;
	int i;

	V0.x = x0, V0.y = y0;           //对V0、Vt初始化，因为findway需要的是Axis型的点
	Vt.x = xt, Vt.y = yt;

	InitStack(&S);                  //初始化栈

    path = (PathType *)malloc(n*sizeof(PathType));      //为path分配空间，path数组元素数目最多只有G的个数个

	if(!path)                       //分配失败
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}

	t = (PathType *)malloc(sizeof(PathType));   //为暂存节点分配空间

	if(!t)                          //分配失败
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}

	//如果起点等于终点
	if(x0==xt && y0==yt)
	{
		return 0;       //返回错误信息
	}

	if(!FindWay(G, path, n, V0, Vt))//进入FindWay函数，如果找到路径，则得到逆序的最短路径path，否则得到错误信息并提示寻路出错
	{
		//寻路出错
		FindWay_error(500,500);
		getch();
		exit(1);
	}
	else
	{
		//将path中的元素弹出，压入S
		for(i = LocateVex(G, n, Vt); i != -1; i = path[i].former)     //从终点开始向前回溯，i!=-1说明到达起始点后还要把起始点入栈
		{
		    Push(&S, path[i]);
		}

		//弹出S中元素，并单步移动
		while(S.top != S.bottom)    //栈非空
		{
            Pop(&S, t);             //出栈一个点，即得到现在该走向的下一个点
            case_state->direction = t->direction;     //记方向，知道下一个点由上一个点往什么方向走而到达，等下给move0的时候就知道方向，可以做动画，具体坐标不重要
            move0(case_state, casetype);              //每一步的移动通过move0实现
		}
	}

	//释放堆
	free(t);
    free(path);
    DestroyStack(&S);   //销毁栈

	//将指针置为空
	path = NULL;
	t = NULL;
}


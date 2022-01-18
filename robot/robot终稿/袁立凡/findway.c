#include "title.h"
/***************************************************************
函数列表：1.队列的基本操作
            void InitQueue(LinkQueue *Q)     //队的初始化
            void DestroyQueue(LinkQueue *Q)  //销毁队
            int IsEmpty(LinkQueue Q)         //判断队是否为空
            void EnQueue(LinkQueue *Q, QElemtype e)     //入队
            void DeQueue(LinkQueue *Q, QElemtype *e)    //出队
           2.图的基本操作
            int CreateGraph(Graph G)         //图的初始化根据给定地图，以链表的方式构建图
            int FindAdjVex(Graph const G, const int n, int k, QElemtype *adjvex)    //寻找某点在图中的邻接点
            int LocateVex(Graph const G, const int n, Axis V)                       //给定某点的数据值，确定该点在图中的索引
            int FindWay(Graph const G, PathType *path, const int n, Axis V0, Axis Vt)   //Dijkstra算法找到从V0到Vt的最短路径
           3.栈的基本操作
            void InitStack(LkStack *S)      //栈的初始化
            void DestroyStack(LkStack *S)   //销毁栈
            void Push(LkStack *S, SElemtype e)  //入栈操作
            void Pop(LkStack *S, SElemtype *e)  //出栈操作
***************************************************************/

//传入队指针完成队的初始化操作，即：先申请一个队节点，并让队头、队尾指向该节点
void InitQueue(LinkQueue *Q)
{
    Q->rear = (QueuePtr)malloc(sizeof(Qnode));     //指向头节点，不储存信息
    Q->front = Q->rear;

    if(!Q->front)    //分配失败
    {
        overflow_box(500, 500);
    }

    Q->front->next = NULL;
}

//传入队指针销毁队，即：将元素逐个出队后释放节点空间，直到队空
void DestroyQueue(LinkQueue *Q)     //从队头开始往队尾走，一个个释放
{
    while(Q->front)  //队还不空
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

//根据队头、队尾是否指向同一节点，判断队是否为空
int IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)    //队头、队尾重合，就是队空
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//将数据e储存，即入队，申请一个队节点，存放元素e信息后，插在队尾
void EnQueue(LinkQueue *Q, QElemtype e) //e插入队尾
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(Qnode));
    if(!p)
    {
        overflow_box(500, 500);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;    //连接到队尾
    Q->rear = Q->rear->next;          //队尾往后移动
}

//队头元素出队，传入指针e保存队头元素的信息，然后释放队头节点
void DeQueue(LinkQueue *Q, QElemtype *e)
{
    QueuePtr p;
    if(Q->front == Q->rear)
    {
        return ;        //队空，删除失败，退出函数
    }
    p = Q->front->next;
    *e = p->data;        //保存要出队的数据
	Q->front->next = p->next;    //队首后移
	if(Q->rear == p)     //删除之后，队空
    {
        Q->rear = Q->front;
    }
    free(p);    //删除以后就应该释放原结点
    p = NULL;
}

/*********队的基本操作结束，下面是图*************/
//入口是数组G，在main函数中声明，将给定地图中每个可通行的坐标点放进数组中。结构体数组里有一个指针，依次、按方向顺次指向其可通行的邻接点
int CreateGraph(Graph G)
{
    int i, j, k = 0;
    LNode *p = NULL, *last = NULL;      //p是每次加的临时节点，last指向每个G[k]接的链表的最后一个节点
    const char unaccessible[16][19]={
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //第一列
                                {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
                                {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                {1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //第16列
                            };

    /*建立邻接链表来储存图的信息*/
    for(i = 1; i < 15; i++) //边界肯定不通，不浪费时间去遍历了
    {
        for(j = 1; j < 18; j++)//边界肯定不通，不浪费时间去遍历了
        {
            if(!unaccessible[i][j])   //这个点可以通过，则加到图中。不能通过就舍弃
            {
                //给G[k]初始化，k自增
                G[k].x = i;
                G[k].y = j;
                G[k].next = NULL;
                last = G[k].next;	//初始化指向G[k]下一位，是NULL，但可以简化后面的操作
                //依次判断右边、左边、上面、下面可不可以通行
                if(i < 14 && !unaccessible[i+1][j])    //右边有方格且可以向右通行，自动去除了边界（i+1小于15，确保了不会访问到外界）
                {
                    p = (LNode *)malloc(sizeof(LNode));	//为p申请空间
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i+1;			//初始化p，p是G[k]点右边的点的坐标
                    p->y = j;
                    p->direction = 1;   //记录方向表示p点在G[k]右边
                    p->next = NULL;
                    if(!last)		//如果这是第一个邻接点则G[k].next直接连上去，否则靠last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //不管是不是第一个结点，last都得指向p，因为last指向最后一个
                }

                if(i > 1 && !unaccessible[i-1][j])    //左边有方格且可以向右通行，自动去除了边界（i-1>0。确保不会乱访问）
                {
                    p = (LNode *)malloc(sizeof(LNode));
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i-1;     //初始化p，p是G[k]点左边的点的坐标
                    p->y = j;
                    p->direction = 2;   //记录方向表示p点在G[k]左边
                    p->next = NULL;
                    if(!last)		//如果这是第一个邻接点则G[k].next直接连上去，否则靠last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //不管是不是第一个结点，last都得指向p，因为last指向最后一个
                }

                if(j > 1 && !unaccessible[i][j-1])    //上面，自动去除了边界（j-1>0，不会越界）
                {
                    p = (LNode *)malloc(sizeof(LNode));
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i;       //初始化p，p是G[k]点上面的点的坐标
                    p->y = j-1;
                    p->direction = 3;    //记录方向表示p点在G[k]上面
                    p->next = NULL;
                    if(!last)		//如果这是第一个邻接点则G[k].next直接连上去，否则靠last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //不管是不是第一个结点，last都得指向p，因为last指向最后一个
                }

                if(j < 17 && !unaccessible[i][j+1])    //下面，自动去除了边界（j+1<18，不会越界）
                {
                    p = (LNode *)malloc(sizeof(LNode));
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i;       //初始化p，p是G[k]点下面的点的坐标
                    p->y = j+1;
                    p->direction = 4;   //记录方向表示p点在G[k]下面
                    p->next = NULL;
                    if(!last)		//如果这是第一个邻接点则G[k].next直接连上去，否则靠last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //不管是不是第一个结点，last都得指向p，因为last指向最后一个
                }

                k++;            //图中个数+1
            }
        }
    }
    return k;   //返回G中元素的个数
}

//入口参数：索引k和adjvex[4]数组，数组各分量依次储存G[k]右、左、上、下四个方向的可通行邻接点在G中的坐标
//函数功能：找G[k]在G中的邻接点，储存在adjvex[4]中，放的是x，y坐标
int FindAdjVex(Graph const G, const int n, int k, QElemtype *adjvex)
{    //adjvex中第一个分量是向右的邻接点，第二个向左，以此类推。n是图中点的个数，k是邻接表中的下标
    int i, j;       //i用来表示adjvex的下标，j表示LocateVex的返回值
    LNode *p = NULL;
    Axis V;

    p = G[k].next;	//指向G的第一个邻接点
    if(!p)      //没有邻接点
    {
        return 0;       //图里有这个点，但它没邻接点
    }

    while(p)   //p非空，没到末尾
    {
        i = p->direction - 1;    //按方向存，direction是从1开始的，而i代表下标，从0开始
        V.x = p->x;				//V就是p代表的点，也即G[k]的邻接点
        V.y = p->y;
        p = p->next;			//往后移，找下一个邻接点
        j = LocateVex(G, n, V); //找V在G中的标号
        adjvex[i] = j;
    }
    return 1;           //找到了邻接点
}

//寻找V在G中的标号
int LocateVex(Graph const G, const int n, Axis V)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(G[i].x == V.x && G[i].y == V.y)
        {
            return i;						//G中找到V点后，把V在G中的下标返回
        }
    }

    return -1;  //没找到
}

//入口参数：路径path，起点V0,终点Vt，图G及G的元素个数n
//函数功能：根据Dijkstra算法得到逆序最短路径path
///得到path之后，先入栈再出栈，就得到了我们想要的从V0到Vt的路径
int FindWay(Graph const G, PathType *path, const int n, Axis V0, Axis Vt)
{
    int i, j, w, *dist, v0, vt;   //v0，vt是V0和Vt在G中的下标，w是中间点的下标
    LinkQueue Q;
    QElemtype k, adjvex[4]; //adjvex里面存的是下标，是要入队出队的，因此属于队的元素类型
    InitQueue(&Q);

    v0 = LocateVex(G, n, V0);
    vt = LocateVex(G, n, Vt);
    if(v0 == -1 || vt == -1)        //起始点、终止点错误，不玩了直接退出函数，啥也不干
    {
        return 0;       //error
    }
    dist = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        dist[i] = -1;
        path[i].former = -1;
    }
    dist[v0] = 0;

    EnQueue(&Q, v0);
    while(!IsEmpty(Q))
    {   //每个元素出队前，adjvex重新初始化，元素出队后遍历其邻接点时要用
        adjvex[0] = -1;
        adjvex[1] = -1;
        adjvex[2] = -1;
        adjvex[3] = -1;
        DeQueue(&Q, &k);    //k是队首元素，而队里放的是在图G中的编号
        if(FindAdjVex(G, n, k, adjvex)) //没邻接点的话返回0，直接跳掉，如果有的话，按方向储存其邻接点的标号置于adjvex数组
        {
            for(j = 0; j < 4; j++)      //依次向四个方向遍历
            {
                if((w = adjvex[j]) != -1)   //说明这个方向的这条路通，k有w这个邻接点
                {
                    if(dist[w] == -1)       //说明这条路不但是通的，还没被访问过
                    {
                        dist[w] = dist[k] + 1;  //V0到W的最短距离是 V0到K的最短距离+1
                        path[w].former = k;          //w的路径上有k这一点
                        path[w].direction = j + 1;  //记录这是由k代表的点向右走一步来的，还是向左来的，等等
                        EnQueue(&Q, w);             //在dist中标记过这个点后入队

                    }

                    if(w == vt)         //找到终点了，不浪费时间继续找了
                    {
                        path[v0].former=-1;
                        DestroyQueue(&Q);   //使用完毕，释放以节约内存
                        free(dist);
                        dist = NULL;
                        return 1;;
                    }
                }
            }
        }
    }
}

/****栈****/
//栈的作用仅在于将path逆序，不需要其他操作，因此只写四个函数

//初始化栈
void InitStack(LkStack *S)
{
    S->bottom = (SNode *)malloc(sizeof(SNode));     //申请头结点
    if(!S->bottom)
    {
        overflow_box(500, 500);
    }
    S->top = S->bottom;       //置空
}

//销毁栈
void DestroyStack(LkStack *S)
{
    SNode *p;
    while(S->top != S->bottom)  //栈还没空
    {
        p = S->top;
        S->top = p->next;
        free(p);
    }
    p = NULL;

}

//入栈
void Push(LkStack *S, SElemtype e)
{
    SNode *p;
    p = (SNode *)malloc(sizeof(SNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
}

//出栈
void Pop(LkStack *S, SElemtype *e)
{
    SNode *p;
    p = S->top;
    S->top = p->next;
    *e = p->data;
    free(p);
    p = NULL;
}









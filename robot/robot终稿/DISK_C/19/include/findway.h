#ifndef findway.h
#define findway.h
/*队与图的一些基本操作，用于寻路。
由于用得不多，因此只写 队的初始化、入队、出队、判断队空，
图的初始化和第一邻接点函数
补了栈的操作，因为要把path路径正向找出*/

#include "typstrct.h"
/******采用链队列，因为不知道要装多少个点*****/

void InitQueue(LinkQueue *Q);   //传入队指针完成队的初始化操作，即：先申请一个队节点，并让队头、队尾指向该节点

void DestroyQueue(LinkQueue *Q);    //传入队指针销毁队，即：将元素逐个出队后释放节点空间，直到队空

int IsEmpty(LinkQueue Q);       //根据队头、队尾是否指向同一节点，判断队是否为空

void EnQueue(LinkQueue *Q, QElemtype e); //将数据e储存，即入队，申请一个队节点，存放元素e信息后，插在队尾

void DeQueue(LinkQueue *Q, QElemtype *e);   //队头元素出队，传入指针e保存队头元素的信息，然后释放队头节点

///图
//入口是数组G，在main函数中声明，将给定地图中每个可通行的坐标点放进数组中。结构体数组里有一个指针，依次、按方向顺次指向其可通行的邻接点
int CreateGraph(Graph G);

//入口参数：索引k和adjvex[4]数组，数组各分量依次储存G[k]右、左、上、下四个方向的可通行邻接点在G中的坐标
//adjvex中第一个分量是向右的邻接点，第二个向左，以此类推
int FindAdjVex(Graph const  G, const int n, int k, QElemtype *adjvex);

int LocateVex(Graph const  G, const int n, Axis V);             //在图G中找到V点（实际上就是G中数据域同V的点）

int FindWay(Graph const  G, PathType *path, const int n, Axis V0, Axis Vt);   //根据Dijkstra算法得到逆序最短路径path

//栈
void InitStack(LkStack *S);  //初始化栈

void DestroyStack(LkStack *S);//销毁栈

void Push(LkStack *S, SElemtype e);//入栈

void Pop(LkStack *S, SElemtype *e);//出栈

#endif // findway










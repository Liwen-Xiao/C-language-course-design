#ifndef typstrct.h
#define typstrct.h

///机器人和人的结构体,储存所有相关信息
typedef struct{

	char hand;                      //左手前为1，右手为0
	char hand_left;
	char hand_right;                //手的运动参数,为θ
	char catch_th;                  //是否持物，1持物，对于人来说，这个参数没有意义
	int x;			                 //x,y和xpixel,ypixel都是机器人x中心、y顶上的位置坐标
	int y;                          //小方格，16*19
	int xpixel;
	int ypixel;                     //像素点，1024*768
	int direction;                  //方向，1为右，2为左，3为上，4为下
}CASE;

///队

typedef int QElemtype;  //队的元素类型

typedef struct Qnode    //QElemtype是队里面元素的类型，Qnode链表结点的类型，内含一个元素一个指针域
{
    QElemtype data;
    struct Qnode *next;
}Qnode, *QueuePtr;

typedef struct          //队指针
{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾
}LinkQueue;

///图

typedef struct LinkNode //表结点
{
    int x;
    int y;
    char direction;  //1为右，2为左，3为上，4为下
    struct LinkNode *next;
}LNode;

typedef struct Node     //G数组的元素类型，以及G的类型
{
    int x;  //x坐标（大坐标，40*40的block）
    int y;
    LNode *next;    //指向表结点
}VType, *Graph;     //Graph就是定义一个VType型的数组

typedef struct
{
    int x;
    int y;
}Axis;              //x，y坐标

///寻路主要部分
typedef struct
{
    int former;
    int direction;
}PathType;          //数组path的类型，第一维放前一个节点的索引，后一个表示方向

///栈

typedef PathType SElemtype;     //每个栈节点的data的数据类型，就是PathType，因为要入栈出栈的就是path

typedef struct StackNode        //栈节点
{
    SElemtype data;              //指向栈底，整个栈的起点，在栈构造之前与销毁之后，base值为NULL
    struct StackNode  *next;     //指向栈顶
}SNode;

typedef struct LinkStack        //链式栈
{
    SNode *bottom;      //指向栈底
    SNode *top;         //指向栈顶
}LkStack;


typedef struct ChTab
{
    int qhwh;
    char str[7];
}CH;

typedef struct EnTab
{
    int qhwh;
    char str;
}EN;

typedef struct Coordinate
{
    int x;
    int y;
} Coordinate;

typedef struct Area
{
    Coordinate lt;
    Coordinate rb;
} Area;

typedef struct USERS{
	char account[11];
	char code[11];
    struct USERS *next;
}USERS;

typedef struct tagBITMAPFILEHEADER{
	int bfType;
	long bfsize;//文件大小，单位为字节
	int bfReserved1;//保留，必须为0
	int bfReserved2;//保留，必须为0
	long bfOffBits;
}BITMAPFILEHEADER;

/*BMP信息头结构*/
typedef struct tagBITMAPINFOHEADER{
	long biSize; /*信息头大小*/
	long biWidth; /*图像宽度*/
	long biHeight; /*图像高度*/
	int biPlanes; /*必须为1*/
	int biBitCount; /*每像素位数，必须为1，4，8，24*/
	long	biCompression;	/*  压缩方法 */
	long	biSizeImage;	/* 实际图像大小，必须是 4 的倍数 */
	long	biXPelsPerMeter;	/*  水平方向每米像素数 */
	long	biYPelsPerMeter;	/*  垂直方向每米像素数*/
	long	biClrUsed;	/*  所用颜色数*/
	long	biClrImportant;	/* 重要的颜色数 */
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
	unsigned char B;	/*蓝色分量，RED缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char R;	/*红色分量，BLUE缩写*/
	unsigned char reserved;		/*保留字*/
} RGBQUAD;

typedef struct{
	int x;                          //left_up
	int y;                          //left_up
	int height;
	int wide;
	int click;
	int over;
}BUTTONS;

#endif // typstrct


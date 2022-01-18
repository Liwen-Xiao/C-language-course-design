#include "title.h"
//功能：主函数
void main()
{
	int judge=0;//返回1为验证失败
	int a, x,y, button;
	mouseInit(&x, &y,&button);  //鼠标初始化
	newxy(&x, &y, &button);     //画鼠标



	//SetSVGA64k();


    //CreateHouseFile();
	SetSVGA64k();
	a = GetSVGA();          //svga初始化

	srand((int)time(0));
	srand((int)time(0));


	outwelcome();         //欢迎界面

	getch();



	while(judge!=1)
    {
        judge=enter();     //进入登录注册界面，登录或者注册成功就可以退出这个循环
    }
    judge=0;
    while(judge!=1)
    {
        judge=finger_check();//进入指纹验证阶段
	}


    mainprocess(&x,&y,&button);    //主流程


}










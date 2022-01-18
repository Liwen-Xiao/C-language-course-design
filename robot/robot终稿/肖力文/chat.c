#include "title.h"


//	界面框架
void chat_interface()
{
	/***************
	输入框
	**************/
	bar_round_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+413,5,1,54938);
	bar_round_2(ORIGINX+13,ORIGINY+403,ORIGINX+243,ORIGINY+508,5,1,65535);
}


void chatmain(CASE *robot)
 {
	Area box_area = { {ORIGINX+15+2,ORIGINY+420} , {ORIGINX+240,ORIGINY+465} };		//输入框左上角坐标
	Coordinate current_show_position = {ORIGINX+17,ORIGINY+415};		//现在正在码的字的左上角坐标

	int i;
	int flag;
	int *qhwh=(int *)malloc(sizeof(int)*MAXTXT);		//区号位号


	if(qhwh==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	//界面
	iph_frame(28153);
	chat_interface();

	while(1)
	{
		//初始化区位号
		QhwhToZero(qhwh);
		//开始输入法
		flag = ShowChTab(box_area,current_show_position/*现在正在码的字的左上角坐标*/, 16,qhwh) ;
		//回车键之后刷新聊天窗口
		bar(ORIGINX+15, ORIGINY+405, ORIGINX+240, ORIGINY+460,65535);
		if(flag == 3)
		{
			show_main(qhwh,robot);
		}
		else
		{
			break;
		}
		getch();
	}
	free(qhwh);
	qhwh = NULL;
 }

#include "title.h"

//功能：指纹验证函数
//输入：无
//输出：int
//		返回1：验证成功（验证成功的按键是enter键）
int finger_check()
{
	int key;     //表示键值的变量
	bar(0,0,1024,768,65535);
	iph_frame();
	fdhz(816,119,1,1,"请",0);
	fdhz(852,119,1,1,"验",0);
	fdhz(892,119,1,1,"证",0);
	fdhz(928,119,1,1,"指",0);
	fdhz(964,119,1,1,"纹",0);

	FillCircle(896,394,25,26620);
	while(1)
    {
        key=0;

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		else if (key==0x1c0d)
        {
            bar(840,139,1024,159,65369);
			return 1;
        }
        else if (key!=0)
        {
            fdhz(856,139,1,1,"指纹不正确",0);
        }
    }
}

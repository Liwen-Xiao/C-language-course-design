#include "typstrct.h"
#ifndef furniture.h
#define furniture.h

extern void trashbin(int x,int y);      //垃圾桶，入口参数是垃圾桶的左上角

extern void bed(int x,int y);       //床

extern void window_close(int x,int y);      //关着的窗户

extern void cupboard(int x,int y);      //衣柜

void aircon(int x,int y,int open);	//80*40,open==1为开启，空调

void WashMach(int x,int y);	//40*40，洗衣机

void bookshelf(int x,int y);	//40*80，书架

void desk(int x,int y);	//80*40，小方桌

void seat(int x,int y);	//40*40,控制在12至28之间，小板凳

void trash1(int x,int y);	//40*40，纸张

void trash2(int x,int y);	//40*40,菜叶

void trash3(int x,int y);	//40*40,果核

void pc(int x,int y);		//电脑，要和上面那个桌子组合用

void TV(int x,int y);		//15*125

//木条纹方桌
void rect_table(int x,int y);	//80*80

extern void sofa_main(int x, int y);        //长条沙发

extern void sofa_up(int x, int y);          //沙发（短，上面的）

extern void sofa_down(int x, int y);         //沙发（短，下面的）

void toilet(int x, int y);			//马桶

extern void water_dispenser(int x, int y);	//饮水机，40*80

extern void zaotai(int x, int y);		//灶台

extern void water_bottle(int x, int y);		//水杯

extern void clothes(int x, int y);  //衣服

extern void plate(int x,int y);  //盘子

void medical_kit(int x, int y);	//医疗包

extern void TV_on(void);        //电视打开

extern void TV_off(void);       //电视关闭

extern void music_on(int x, int y);     //音符

extern void music_off( int x, int y);   //去除音符
#endif

#ifndef iph_page.h
#define iph_page.h
#include "typstrct.h"

//功能：手机外框等固定元素，任何界面都需要显示
extern void iph_frame();

//功能：手机界面附加元素
extern void iph_frame_plus();

//功能：手机主界面
extern void iph_page_1();

//功能：手动指令界面
extern void iph_page_2();

//功能：聊天界面
extern void iph_page_3();

//功能：默认设置修改界面
extern void iph_page_4(char *at,char *bt);

//功能：时间界面
extern void time_page();

#endif // iph_page

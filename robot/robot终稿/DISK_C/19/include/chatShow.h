#ifndef chatShow.h
#define chatShow.h
#include "typstrct.h"


//功能：打印用户命令
//输入：区号位号和输出框的纵坐标
//输出：无
extern void show_order(int *qhwh,int *y);





//功能：得到用户输入的字符串（将区号位号改成内码）
//输入：区号位号指针和内码指针
//输出：无
extern void get_str(int *qhwh, char *incode);





//功能：根据输入的字符串得到返回语句
//输入：用户输入的字符串的指针，回复的字符串的指针，机器人的状态指针
//输出：无
extern void reply_match(char * str,char *reply,CASE* robot);





//功能：机器人回复输出
//输入：输出语句的内码，机器人的状态
//输出：无
extern void show_reply(char *incode,CASE* robot);





//功能：聊天输出的主函数
//输入：用户输入的字符串的内码，机器人状态
//输出：无
extern void show_main(int *qhwh,CASE* robot);





//功能：判断用户输入的句子中是否有关键字
//输入：用户输入的字符串的字符指针
//输出：int
//		返回0：没有关键字
//		返回1：有关键字
extern int no_keyword(char *str);


#endif // chatShow

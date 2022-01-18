#ifndef log_in.h
#define log_in.h


#include "typstrct.h"

//功能：登录注册功能主逻辑
//输入：无
//输出：int型
//      返回1为登陆成功，跳出循环，进入下一模块
//		返回0为登陆失败，继续循环
extern int enter(void);



//功能：登录的静止界面
//输入：无
//输出：无
extern void log_in_page(void);



//功能：账号输入函数
//输入：用户信息链表的头节点，指向账号字符串的字符指针，指向密码字符串的字符指针，鼠标坐标指针
//输出：int型
//		返回1：登录或注册成功
//		返回3：进入密码输入函数
extern int input_account(USERS *head,char *account,char *code,int *x,int *y);



//功能：账号输入函数
//输入：用户信息链表的头节点，指向账号字符串的字符指针，指向密码字符串的字符指针，鼠标坐标指针
//输出：int型
//		返回1：登录或注册成功
//		返回2：进入id输入函数
extern int input_code(USERS *head,char *account,char *code,int *x,int *y);



//功能：验证账号密码是否正确
//输入：用户信息链表的头节点，指向账字符串的字符指针，指向密码字符串的字符指针
//输出：int型
//		返回1：验证成功
//		返回5：验证失败
extern int log_in_check(USERS *head,char *account,char *code);
#endif // log_in


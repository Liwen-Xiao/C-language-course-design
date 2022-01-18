#ifndef filefun.h
#define filefun.h

#include "typstrct.h"

//功能：创建用户链表
//输入：用户信息链表的头指针
//输出：无
extern void create_list(USERS *head);


//功能：将新用户的信息写入文件
//输入：用户信息链表的头指针，密码字符指针，账号字符指针
//输出：无
extern void add_new_user(USERS *head,char *s1,char *s2);


//功能：通过账户来输出对应的密码
//输入：用户信息链表的头指针，账号字符指针
//输出：无
extern char *accounts_2_code(USERS *head,char *string);


//功能：释放链表
//输入：用户信息链表的头指针
//输出：无
extern void free_list(USERS *head);
#endif

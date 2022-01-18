#ifndef txt_save.h
#define txt_save.h

#include "typstrct.h"

//以下两个是机器人聊天框的背景存储函数
//第一个是得到聊天框的背景
//第二个是输出聊天框的背景，及覆盖聊天框
//输入：框的左上角
//输出：无
//尺寸：240*80
extern void saveimage_chat(int x,int y);

extern void putsave_chat(int x,int y);


//以下两个是机器人欢迎框的背景存储函数
//第一个是得到聊天框的背景
//第二个是输出聊天框的背景，及覆盖聊天框
//输入：框的左上角
//输出：无
//尺寸：240*80
extern void saveimage_welcome(int x,int y);

extern void putsave_welcome(int x,int y);


//以下两个是选择框的背景存储函数
//第一个是得到选择框的背景
//第二个是输出选择框的背景，及覆盖选择框
//输入：框的左上角
//输出：无
//尺寸：240*40
extern void saveimage_choose(int x,int y);

extern void putsave_choose(int x,int y);


//以下两个是机器人动作状态框的背景存储函数
//第一个是得到动作状态框的背景
//第二个是输出动作状态框的背景，及覆盖动作状态框
//输入：框的左上角
//输出：无
//尺寸：80*30
extern void saveimage_doing(int x,int y);

extern void putsave_doing(int x,int y);


//以下两个是g_c框的背景存储函数
//第一个是得到g_c框的背景
//第二个是输出g_c框的背景，及覆盖g_c框
//输入：框的左上角
//输出：无
//尺寸：90*40
extern void saveimage_g_c(int x,int y);

extern void putsave_g_c(int x,int y);


//以下两个是机器人t_c框的背景存储函数
//第一个是得到t_c框的背景
//第二个是输出t_c框的背景，及覆盖t_c框
//输入：框的左上角
//输出：无
//尺寸：120*40
extern void saveimage_t_c(int x,int y);

extern void putsave_t_c(int x,int y);


//以下两个是机器人box框的背景存储函数
//第一个是得到box框的背景
//第二个是输出box框的背景，及覆盖box框
//输入：框的左上角
//输出：无
//尺寸：210*45
extern void saveimage_box(int x,int y);

extern void putsave_box(int x,int y);


//以下两个是人背景存储函数
//第一个是得到人的背景
//第二个是输出人的背景，及覆盖人
//输入：框的左上角
//输出：无
//尺寸：70*90
extern void get_image_man(int x, int y);

extern void put_image_man(int x, int y);


//以下两个是机器人的背景存储函数
//第一个是得到机器人的背景
//第二个是输出机器人的背景，及覆盖机器人
//输入：框的左上角
//输出：无
//尺寸：70*90
extern void get_image_robot(int x, int y);

extern void put_image_robot(int x, int y);


//以下两个是垃圾1的背景存储函数
//第一个是得到垃圾1的背景
//第二个是输出垃圾1的背景，及覆盖垃圾1
//输入：框的左上角
//输出：无
//尺寸：40*40
void get_image_trash1(int x, int y);

void put_image_trash1(int x, int y);


//以下两个是垃圾2的背景存储函数
//第一个是得到垃圾2的背景
//第二个是输出垃圾2背景，及覆盖垃圾2
//输入：框的左上角
//输出：无
//尺寸：40*40
void get_image_trash2(int x, int y);

void put_image_trash2(int x, int y);


//以下两个是垃圾3的背景存储函数
//第一个是得到垃圾3的背景
//第二个是输出垃圾3的背景，及覆盖垃圾3
//输入：框的左上角
//输出：无
//尺寸：40*40
void get_image_trash3(int x, int y);

void put_image_trash3(int x, int y);



//以下两个洗澡背景存储函数
//第一个是得到洗澡的背景
//第二个是输出洗澡的背景，及覆盖地板
//输入：框的左上角
//输出：无
//尺寸：80*80
void get_image_bath(int x, int y);

void put_image_bath(int x, int y);
#endif

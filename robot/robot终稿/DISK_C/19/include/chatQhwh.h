#ifndef  chatQhwh.h
#define  chatQhwh.h
#include "typstrct.h"

/**************************************************
function:        extern void SaveChQhwh(FILE *fp,CH * ch);

description:     将汉字区号位号保存在文件中

Input:           FILE *fp,CH * ch

output:
**************************************************************/
extern void SaveChQhwh(FILE *fp,CH * ch);

/**************************************************
function:        extern int FindChQhwh(CH *ch,char *temp,int num_qhwh,int qhwh);

description:     传进读取文件的拼音库，从中找到对应汉字的区位号

Input:           CH *ch,char *temp,int num_qhwh,int qhwh

output:
**************************************************************/
extern int FindChQhwh(CH *ch,char *temp,int num_qhwh,int qhwh);


/**************************************************
function:        extern int CheckQhwhNum(int *qhwh);

description:     看区位号数量（确认有几个字）

Input:           int *qhwh

output:          int 个数
**************************************************************/
extern int CheckQhwhNum(int *qhwh);

/**************************************************
function:        extern void qhwh2incode(int qwh,char *incode);

description:     将区号位号转化为内码，方便之后对比

Input:           int qwh,char *incode

output:
**************************************************************/
extern void qhwh2incode(int qwh,char *incode);



extern void SaveEnQhwh(FILE *fp,EN *en);
extern int FindEnQhwh(EN *en,char temp);
extern int TxtToQhwh(int *qhwh,char *filename);
extern int AddQhwhToTxt(int *qhwh,char *filename);
extern int AddNumToTxt(int num,char *filename);
extern int CheckNumInTxt(char *filename);
extern int ReplaceQhwhToTxt(int *qhwh,char *filename);
extern int ReplacePassToTxt(int *qhwh,char *filename);

extern void ClearKey(void);




extern int QhwhToZero(int *qhwh);


#endif

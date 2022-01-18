#ifndef rbtfunc.h
#define rbtfunc.h

#include "typstrct.h"

void rbtguard(CASE human, CASE robot, int identity, int *x, int *y, int *button);//安保功能

void treatment(CASE *human, CASE *robot, Graph G, int n, int *x, int *y, int *button, int *choice);//医疗照顾功能

void clean(CASE *robot, CASE *human, Graph G, int n);//打扫卫生功能

#endif // rbtfunc


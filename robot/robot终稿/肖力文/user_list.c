#include "title.h"
/*
users.txt文件说明：
1.账号的起始符是"\n", 密码的起始符是" ".
2.一行为一个用户的信息，空格前是账号，空格后是密码

链表说明：
1.链表的头是一个指针，指向链表结构体
2.链表的最后一个元素的next指向为null,但是其account和code不是空的
*/


//功能：创建用户链表
//输入：用户信息链表的头指针
//输出：无
void create_list(USERS *head)                   
{
	USERS *current = NULL;//指向当前结点的指针变量
    FILE *fp=NULL;        //用于打开users.txt的文件指针
    char ch;    //用于接收并传送文件内部字符的中间变量
    char *p=NULL;   //指向需要接收字符的地址的指针变量

  //初始化
  current = head;
  p = head->account;
  //防止直接点击登陆进入的情况发生
  if ((fp = fopen("user\\users.txt", "r+")) == NULL)
  {
	  null_box(500,500);
	  getch();
	  exit(1);
  }
  while(!feof(fp))//判断指针是否已到达文件尾部
  {
	ch=fgetc(fp);    //从users.txt文件中提取一个字符
	if(ch=='\n')    //表示账户串的开始，密码串的结束    
	 {
		/*向系统申请空间*/
	   if((current->next=(USERS *)malloc(sizeof(USERS)))==NULL)
		{
           overflow_box(500,500);
		   getch();
		   exit(1);
		}

	   current=current->next;

	   *p='\0';           //上一个用户的密码最后面加一个0表示密码读入完成，完善密码的字符串
	   p=current->account;
	 }
	else if(ch==' ')      //表示账户串的结束，密码串的开始
	{
	  *p='\0';            //用户的账号最后面加一个0表示账号读入完成，完善账号的字符串
	  p=current->code;
	}
	else        //将对应的账户串或密码串装入链表中
	{
	  *p=ch;
	  p++;
	}
  }
  p--;
  *p=0;         //去掉EOF，并给链表最后一个元素的密码的字符串结尾

  current->next=NULL;
  fclose(fp);
}


//功能：将新用户的信息写入文件
//输入：用户信息链表的头指针，密码字符指针，账号字符指针
//输出：无
void add_new_user(USERS *head,char *s1,char *s2)    /*******创建新用户的链表和将新用户的信息写入文件中    s1是账号，s2是密码********/
{
	USERS *current = head;
	FILE *fp;
	char *p;

	//以下程序块是为新用户在链表中创建节点
	while(current->next != NULL)
	{
		current = current->next;
	}
	if((current->next = (USERS *)malloc(sizeof(USERS))) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	current = current->next;
	strcpy(current->account,s1);
	strcpy(current->code,s2);
	current->next = NULL;

	//以下程序块是将将新用户的信息写入users.txt文件中
	if((fp = fopen("user\\users.txt","r+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	//将文件内部指针移到文件末端
    fseek(fp,0L,2);

	p="\n";
	putc(*p,fp);
    p=s1;
    while(*p!='\0')
    {
	    putc(*p,fp);//输入字符到指定文件
	    p++;
    }
    putc(' ',fp);//账户串结束，密码串开始

    p=s2;
    while(*p!='\0')
    {
	    putc(*p,fp);
	    p++;
    }
 fclose(fp);
}

//功能：通过账户来输出对应的密码
//输入：用户信息链表的头指针，账号字符指针
//输出：字符指针
//在已经生成的用户信息链表中查询目标账号的对应密码，并输出该密码字符串的首地址；如果没有该账号，则输出NULL
char *accounts_2_code(USERS *head,char *string)      
{
 USERS *current=head;
 int p=0;				//判断是否有对应的账号

 while(current->next&&strcmp(current->account,string)!=0)    //在除了最后一个节点的其他节点中寻找是否有对应的账号
 {
   current=current->next;
 }
 if (current->next!=NULL)  		//找到了对应的账号，p置为1
 {
	 p=1;
 }
 else if (current->next==NULL)	//如果现在指针指向了最后一个节点
 {
	 if (strcmp(current->account,string)==0)  //如果该账号是目标账号
	 {
		 p=1;
	 }
 }
 
 if (p==0)				//如果没有找到对应账号，那么就输出0
 {
	 return NULL;
 }
 else 					//如果找到了对应的账号，那么就输出对应账号对应的密码
 {
	 return current->code;
 }
}


//功能：释放链表
//输入：用户信息链表的头指针
//输出：无//释放链表
void free_list(USERS *head)         
{
	USERS *previous = head;			//将previous指针指向头节点
	USERS *current = head->next;	//将current指针指向第一个节点

	while (current->next != NULL)   //如果current指针没有指空
	{
		free(previous);				//释放previous指针指向的节点
		previous = current;			//将previous指针指向current指针
		current = current->next;	//将current指向下一个节点
	}
	free(previous);					//此时current指向空，那么就释放previous的空间
	previous=NULL;
	current=NULL;
	head = NULL;
}

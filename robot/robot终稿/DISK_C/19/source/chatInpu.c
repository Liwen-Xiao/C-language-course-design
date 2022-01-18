#include "title.h"
/******************函数清单***************************
1.  void CursorWhite(Coordinate current_show_position,int show_size)
2.  void CursorBlack(Coordinate current_show_position,int show_size)
3.  void DeleteShow(Area show_area,Coordinate * current_show_position,int show_size )
4.  void ShowWhite(Coordinate * current_show_position,int show_size)
5.  void DeleteTab(Coordinate * current_en_position,CH* ch,EN* en,char *temp ,int * num_tab,int *ch_qhwh, unsigned int *box_save)
6.  void ShowTxt(int *qhwh, Area show_area,Coordinate* current_show_position,int show_size)
7.  int ShowChTab(Area show_area,Coordinate current_show_position, int show_size,int *qhwh)
*****************************************************/


//展示白色光标
void CursorWhite(Coordinate current_show_position,int show_size){
	bar(current_show_position.x,current_show_position.y,current_show_position.x+2,current_show_position.y+show_size,65535);
}

//展示黑色光标
void CursorBlack(Coordinate current_show_position,int show_size){
	bar(current_show_position.x,current_show_position.y,current_show_position.x+2,current_show_position.y+show_size,0);
}



/*************

似乎只是单纯的让定位改变，没有体现“删除”操作

*************/
void DeleteShow(Area show_area,Coordinate * current_show_position,int show_size )//1
{	
	
	//初始化real_rb_x，使其指向定位
    int real_rb_x=((show_area.rb.x - show_area.lt.x)/show_size)*show_size + show_area.lt.x;
    //int real_rb_y=((show_area.rb.y - show_area.lt.y)/show_size)*show_size + show_area.lt.y;
    if(current_show_position->x>show_area.lt.x || current_show_position->y > show_area.lt.y)//框内是否有字的检测
    {
		//有字有两种情况①光标不在最左侧即左侧有字符②光标在最左侧但不在第一行即上面有字符
        if(current_show_position->x > show_area.lt.x )					//若① 则执行下一句
            current_show_position->x =current_show_position->x-show_size;	//定位往前移一格删除一个
        else	//②的情况
        {
            current_show_position->x = real_rb_x- show_size;		//x移到倒数第二位
            current_show_position->y = current_show_position->y- show_size;		//y移到上一行
        }
    }
    ShowWhite( current_show_position, show_size);
}



/**********************

似乎是写了个白bar

**********************/
void ShowWhite(Coordinate * current_show_position,int show_size)//2
{
    int x,y,i,j,k;
    int width_byte=0;//定义字节长度
    x=current_show_position->x;
    y=current_show_position->y;

    width_byte=(show_size+4)/8;//计算字节数宽度

    for(i=0;i<show_size;i+=1)
    {
        for(j=0;j<width_byte;j+=1)
        {
            for(k=0;k<8;k+=1)
            {
               Putpixel64k(x+j*8+k, y+i, 0xFFFFFF);
            }
        }
    }
}

/***************

在输入法的框中删除字母
（区别于在输入框中删除字母

****************/

void DeleteTab(Coordinate * current_en_position,CH* ch,EN* en,char *temp ,int * num_tab,int *ch_qhwh)//3
{
    int en_qhwh,i;

    Area show_ch_area={ {ORIGINX+30,ORIGINY+365} , {ORIGINX+222,ORIGINY+380} };
    Area show_en_area={ {ORIGINX+30,ORIGINY+388} , {ORIGINX+222,ORIGINY+400} };
    Coordinate current_ch_position ={ORIGINX+30,ORIGINY+365};

    --(*num_tab);		//	不是很懂。。哪里要减一？
	/***************
	懂了懂了，这里说明一下这个num_tab吧
	这个就是拼音中的每个字母数
	之后有一个FindChQhQh这个函数就是将前几位拼音与汉字库中做对比，
	而这个num_tab就是某个汉字的总字母数
	每次按backspace触发这个DeleteTab函数意味着删去输入拼音中的刚刚那个字母
	***************/
    *ch_qhwh = FindChQhwh(ch,temp, *num_tab, *ch_qhwh);		//在num_tab少了一个之后重新在汉字库中寻找匹配值
    current_en_position->x=ORIGINX+30;		//设置英文输入起始位置

	//重新put输入法框
    //Putbmp64k(589,633,"bmp\\ChTab.bmp");	
	//put_image(ORIGINX+25,ORIGINY+365,ORIGINX+225,ORIGINY+400, box_save);
	putsave_box(ORIGINX+25,ORIGINY+365);
	
	//重新输出文字信息（都是保存好的地址的之前的内容
    for(i=0;i<*num_tab;i++)
    {
        en_qhwh = FindEnQhwh(en,temp[i]);
        ShowPerCharacter(en_qhwh,show_en_area, current_en_position ,0x000000,16,"hzk");
    }

    for(i=0;i<5;i++)
    {
        ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
        ShowPerCharacter((*ch_qhwh)+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
    }
}



/***************

将刚刚输入法打出的字整合成一句话展示
ShowPerCharacter用来决定文字是否需要换行
else后的操作用来改变定位

****************/

void ShowTxt(int *qhwh, Area show_area,Coordinate* current_show_position,int show_size)//6
{
    int i=0,num_qhwh;	//num_qhwh相当于current的字数统计
    int real_rb_x=((show_area.rb.x - show_area.lt.x)/show_size)*show_size + show_area.lt.x;
    int real_rb_y=((show_area.rb.y - show_area.lt.y)/show_size)*show_size + show_area.lt.y;
    num_qhwh=CheckQhwhNum(qhwh);	//看有几个字

    for(i=0;i<num_qhwh;i++)
    {
        if(qhwh[i]!=0)	//打印整句话
        ShowPerCharacter(qhwh[i],show_area, current_show_position,0 , show_size,"hzk");
        else
        {
            ShowWhite( current_show_position, show_size);
            if((current_show_position->x+show_size)<=real_rb_x|| (current_show_position->y+show_size)<=real_rb_y)//判断需不需要换行从最左边开始打印
            {
                if(current_show_position->x < real_rb_x - show_size)	//不需要换行，直接接在本行后面打印
                    current_show_position->x =current_show_position->x+show_size;
                else
                {		//需要换行的将定位按要求换行
                    current_show_position->x = show_area.lt.x;
                    current_show_position->y =current_show_position->y+show_size;

                }
            }

        }
    }
}

int ShowChTab(Area show_area,Coordinate current_show_position/*现在正在码的字的左上角坐标*/, int show_size/*有48，36，28*/,int *qhwh)//7
{
    union
    {
        int key;
        char c[2];
    }u;
	Coordinate first_show_position = current_show_position;
    CH * ch=NULL;//定义汉字符号结构体
    EN * en=NULL;//定义英文符号结构体
    char temp[500],temp1;          //定义临时变量缓存
    int i,ch_qhwh,en_qhwh,num_tab=0,num_qhwh=0;
    FILE *hanzi;            //定义汉字符号文件指针
    FILE *fuhao;            //定义英文符号文件指针

    Area show_ch_area={ {ORIGINX+30,ORIGINY+365} , {ORIGINX+222,ORIGINY+380} };
    Area show_en_area={ {ORIGINX+30,ORIGINY+388} , {ORIGINX+222,ORIGINY+400} };
    //Area input_tab_area={ {589,633},{1024,768} };
    Coordinate current_ch_position ={ORIGINX+30,ORIGINY+365};
    Coordinate current_en_position ={ORIGINX+30,ORIGINY+388};


    int real_rb_x= ((show_area.rb.x - show_area.lt.x)/show_size)*show_size + show_area.lt.x;	
	//初始化real_rb_x（最右点坐标），之后用最右值均用此

    if( ( ch=(CH *)malloc(sizeof(CH)*463) )==NULL )//如果动态分配内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        return(1);
    }
    if( ( en=(EN *)malloc(sizeof(EN)*120) )==NULL )//如果动态分配内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        return(1);
    }

    if((hanzi = fopen("txt\\hanzi.txt","r")) == NULL)//hanzi和fuhao是文件句柄 
    {
		null_box(500,500);
		getch();
        perror("fail to open");
        return (1) ;
    }
    if((fuhao = fopen("txt\\fuhao.txt","r")) == NULL)
    {
		null_box(500,500);
		getch();
        perror("fail to open");
        return (1) ;
    }

    //StoreBk(input_tab_area.lt,435,135);		//保存input_tab_area的所有图像，1左上角坐标2宽度3高度  这句就相当于getimage
    //Putbmp64k(input_tab_area.lt.x,input_tab_area.lt.y,"bmp\\ChTab.bmp");	//放输入框贴图

    SaveChQhwh(hanzi,ch);	//	初始化汉字输入库，将hanzi.txt里的汉字信息全部一个个转移到ch这个结构体中去
    SaveEnQhwh(fuhao,en);	//	初始化英文输入库，将fuhao.txt里的英文信息也全部一个个转移到en这个结构体中去

    num_qhwh=CheckQhwhNum(qhwh);//计算当前字符个数，总共有几个qhwh代表的字符，作用就是之后在整段聊天打印的时候需要
	//这里就是一开始光标找一下存在感
    CursorBlack(current_show_position,show_size);//光标涂黑（相当于出现光标）
    delay(400);
    //CursorWhite(current_show_position,show_size);//光标涂白（隐藏光标）

    ClearKey();//清除键盘缓存，不重要

    while(1)//进入按键循环
    {

        u.key=bioskey(0);//获取按键信息，key是int型（扫描码？

        if(u.c[1]==0x1) //键入esc退出
        {
			//归位
            free(ch);
            free(en);
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            CursorWhite(current_show_position,show_size);//光标涂白
            //PutBk(input_tab_area.lt,435,135);		//把之前StoreBk的图片重新putimage上来
            return 0;
        }

		/**********
		当num_tab==0时，
		均对输入框操作
		以下
		**********/		
        else if(u.c[1]==0x1c&& num_tab==0)//键入回车发送消息
        {
            //归位
            free(ch);
            free(en);
			ch = NULL;
			en = NULL;
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            CursorWhite(current_show_position,show_size);//光标涂白
            //PutBk(input_tab_area.lt,435,135);		//把之前StoreBk的图片重新putimage上来
            return 3;


        }

		
        else if(u.c[1]==0x48 && num_tab==0)//键入 光标向上（UP上键）
        {
            if(current_show_position.y>show_area.lt.y )		//	判断之后是否会出界
            {
                num_qhwh=num_qhwh-(real_rb_x- show_area.lt.x)/show_size;	//num_qhwh减去整整一行的字符数
                CursorWhite(current_show_position,show_size);
                current_show_position.y-=show_size;
                CursorBlack(current_show_position,show_size);
            }

        }

		
        else if(u.c[1]==0x50 && num_tab==0)//键入 光标向下（DOWN下键）
        {
            if((current_show_position.y+2*show_size)<=show_area.rb.y)	//这里*2是因为current_show_position定位的时左上角，故得判断顶端往下两行（即向下一行）的操作之后不会出界
            {
				num_qhwh=num_qhwh+(real_rb_x- show_area.lt.x)/show_size;	//num_qhwh加上整整一行的字符数
                CursorWhite(current_show_position,show_size);
                current_show_position.y+=show_size;
                CursorBlack(current_show_position,show_size);
            }

        }

		
        else if(u.c[1]==0x4b&& num_tab==0)//键入 光标向左（LEFT）
        {
            if( current_show_position.x > show_area.lt.x || current_show_position.y>show_area.lt.y)//判断下一步不会出界
            {
                CursorWhite(current_show_position,show_size);
                if(current_show_position.x > show_area.lt.x )//确认光标不会左移出输入框
                    current_show_position.x = current_show_position.x-show_size;//定位左移一个单位
                else
                {
					//若左移出输入框则定位到上一行字符串尾
                    current_show_position.x =real_rb_x;
                    current_show_position.y =current_show_position.y-show_size;

                }
                --num_qhwh;//不论哪种情况，num_qhwh都是要减1（由键入LEFT键决定）
                CursorBlack(current_show_position,show_size);//显示到现在定位的后面
            }

        }
		//在y处需要*2也是current)_show_position定位在左上角惹的祸，用来判断下一行在不在界内
        else if(u.c[1]==0x4d&& num_tab==0)//键入 光标向右（RIGHT）
        {
            if((current_show_position.x+show_size)<=real_rb_x|| (current_show_position.y+2*show_size)<=show_area.rb.y)//确认现在定位在正确框内
            {
                CursorWhite(current_show_position,show_size);
                if(current_show_position.x <= real_rb_x - show_size)//确认还在离最后面的字的定位有至少一个字以上的空间
                    current_show_position.x =current_show_position.x+show_size;//定位右移一个单位
                else
                {
					//若左移出输入框则定位到下一行字符串首（似乎只对两行以上的输入方式有效
                    current_show_position.x = show_area.lt.x;
                    current_show_position.y =current_show_position.y+show_size;

                }
                ++num_qhwh;
                CursorBlack(current_show_position,show_size);
            }

        }

        else if(u.c[1]==0xe && num_tab==0)//键入删除键（backspace），删除定位前一个字符
        {
            if(current_show_position.x>first_show_position.x || current_show_position.y>first_show_position.y)//如果不在第一个字的位置才可以进行
			{
				CursorWhite(current_show_position,show_size);
				DeleteShow( show_area,& current_show_position, show_size );//图像上的操作，逻辑上的操作见下一句
				qhwh[num_qhwh-1]=0;//当前字符区号位号置0
				--num_qhwh;//字符个数减去1
            }
			CursorBlack(current_show_position,show_size);
        }

        else if(u.c[1]==0x39&& num_tab==0)//键入空格
        {
            if((current_show_position.x+show_size)<=real_rb_x || (current_show_position.y+2*show_size)<=show_area.rb.y)
            {
                CursorWhite(current_show_position,show_size);
                if(current_show_position.x <= real_rb_x - show_size)//确认还在离最后面的字的定位有至少一个字以上的空间
                    current_show_position.x =current_show_position.x+show_size;//图像上的空格，等下字符个数凭空加一
                else
                {
					//满了就初始化重新输入
                    current_show_position.x = show_area.lt.x;
                    current_show_position.y =current_show_position.y+show_size;

                }
                ++num_qhwh;//字符个数+1
                CursorBlack(current_show_position,show_size);
            }
        }


        else if(u.c[0]>='a'&& u.c[0]<='z')//键入字母，注意 这里是拼音的字母
        {
            num_tab++;
            temp[num_tab-1]=(char) (u.c[0]);	//temp的容量是500，肯定够了
            ch_qhwh = FindChQhwh(ch,temp, num_tab,ch_qhwh);		
			//去这个函数中与之前保存好的ch里面的所有汉字作比较，找到目标汉字，
			//但此时有很多匹配值，所以在后面会全部put出来
            en_qhwh = FindEnQhwh(en,temp[num_tab-1]);	//到英文库中找到输入的字母，直接显示出来
            if(num_tab<=6)	//限制了拼音最多输入6位
            ShowPerCharacter(en_qhwh,show_en_area, &current_en_position ,0x000000,16,"hzk");	//这里先把拼音的字母输出来
            //Putbmp64k(589,633,"bmp\\part.bmp");		//这里是输入法显示框（之前是输入框操作
			bar(ORIGINX+25,ORIGINY+365,ORIGINX+225,ORIGINY+380,65535);
			
			
            current_ch_position.x = ORIGINX+30;	//从这个位置输出可能匹配的汉字
            current_ch_position.y = ORIGINY+365;
            for(i=0;i<5;i++)	//一页显示五个可能值
            {
				//显示序号12345
                ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
                //显示汉字，拼音相同的两个汉字区位码相差1
				ShowPerCharacter(ch_qhwh+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
            }

        }


        else if(u.c[1]==0xe && num_tab!=0)//tab框 键入删除键，删除输入法tab框
        {
            DeleteTab(& current_en_position, ch, en, temp ,& num_tab,& ch_qhwh);
        }


        else if(u.c[0]>='1'&&u.c[0]<='5'&& num_tab!=0)//键入1-5  选择字符
        {
            CursorWhite(current_show_position,show_size);
            ++num_qhwh;		//为什么这里还需要让字符数加一。。。
            qhwh[num_qhwh-1]=ch_qhwh + u.c[0]-'1';	
			/***********************
			u.c[0]-'1'是取出整型的输入数字（而不是ascii码），
			加上ch_qhwh之后就是指的是输入法框中的第几个汉字了
			***********************/

            ShowPerCharacter(qhwh[num_qhwh-1],show_area, &current_show_position,0x000000 , show_size,"hzk");	//这次是打印到输入框中了
            //Putbmp64k(589,633,"bmp\\ChTab.bmp");	//重新刷图
            //put_image(ORIGINX+25,ORIGINY+365,ORIGINX+225,ORIGINY+400, box_save);
			putsave_box(ORIGINX+25,ORIGINY+365);
			num_tab=0;	//拼音字母数归零
            current_ch_position.x = ORIGINX+30;	//汉字出现位置归位
            current_ch_position.y = ORIGINY+365;	
            current_en_position.x=ORIGINX+30;		//拼音出现位置归位
            current_en_position.y=ORIGINY+388;
            CursorBlack(current_show_position,show_size);	//黑色光标重新出现

        }

        else if((u.c[1]==0x48/*UP*/||u.c[1]==0x4b/*LEFT*/)&& num_tab!=0)//键入 向上或向左 翻页
        {
            ch_qhwh=ch_qhwh-5;		//汉字库中往前走五个（刚好翻页
            //Putbmp64k(589,633,"bmp\\part.bmp");	//又开始重新put所有信息
            bar(ORIGINX+25,ORIGINY+365,ORIGINX+225,ORIGINY+380,65535);
			
			current_ch_position.x = ORIGINX+30;
            current_ch_position.y = ORIGINY+365;
            for(i=0;i<5;i++)
            {
                ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
                ShowPerCharacter(ch_qhwh+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
            }

        }

        else if((u.c[1]==0x50/*DOWN*/||u.c[1]==0x4d/*RIGHT*/) && num_tab!=0)//键入 向下翻页
        {
            ch_qhwh=ch_qhwh+5;		//汉字库中往后走五个（刚好翻页
            //Putbmp64k(589,633,"bmp\\part.bmp");	//又开始重新put所有信息
            bar(ORIGINX+25,ORIGINY+365,ORIGINX+225,ORIGINY+380,65535);
			
			current_ch_position.x = ORIGINX+30;
            current_ch_position.y = ORIGINY+365;
            for(i=0;i<5;i++)
            {
                ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
                ShowPerCharacter(ch_qhwh+i,show_ch_area,&current_ch_position,0x000000,16,"hzk");
            }
        }

        else		//直接输出英文（不知道对应什么情况
        {
            temp1=(char) (u.c[0]);
            en_qhwh = FindEnQhwh(en,temp1);
            CursorWhite(current_show_position,show_size);
            ++num_qhwh;
            qhwh[num_qhwh-1]=en_qhwh;
            ShowPerCharacter(qhwh[num_qhwh-1],show_area, &current_show_position ,0x000000,show_size,"hzk");
            CursorBlack(current_show_position,show_size);

        }
    }
}

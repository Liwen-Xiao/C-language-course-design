int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *buttons);

int input_area(int *x,int *y, int *buttons);

int inpu(char*inpu_c, int *x, int *y, int *buttons,int x_posi, int y_posi,int a_p);

void regist_page(void);

int get_verification(char *mail,char *real_veri, int flag[]);

int regist_success(char *real_veri, char *veri);

int whether_mail(char *str);
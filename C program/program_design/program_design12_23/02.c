#include <stdio.h>

typedef struct {
    int year, month, day;
} DateData;

typedef struct {
    char ID[13], nickname[31];
    int loginTimes, articles, money;
    DateData lastLogin;
    char gender, flags;
} BloggerData;

int main()
{
    FILE *fp = fopen("bloggerData_BIG5.data", "rb");
    if (fp == NULL){
        printf("開檔失敗\n");
        return 0;
    }
    BloggerData blogger[100];
    fseek(fp, 0, SEEK_END);
    int fsize = ftell(fp);
    rewind(fp);
    int total = fsize/sizeof(BloggerData);
    fread(blogger, sizeof(BloggerData), total, fp);
    fclose(fp);
    printf("總共讀進 %d 位部落客資料。\n", total);
    for(int i = 0 ; i<total ; i++)
    {
        printf("\nBlogger#%d:\n", i);
        printf("ID = %s\n", blogger[i].ID);
        printf("nickname = %s\n", blogger[i].nickname);
        printf("loginTimes = %d\n", blogger[i].loginTimes);
        printf("articles = %d\n", blogger[i].articles);
        printf("money = %d\n", blogger[i].money);
        printf("lastLogin = %d/%d/%d\n", blogger[i].lastLogin.year, blogger[i].lastLogin.month, blogger[i].lastLogin.day);
        printf("gender = %c\n", blogger[i].gender);
        printf("flags = %d\n", blogger[i].flags);
    }
}

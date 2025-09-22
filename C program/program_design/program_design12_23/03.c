#include <stdio.h>
#include <string.h>

typedef struct {
    int year, month, day;
} DateData;

typedef struct {
    char ID[13], nickname[31];
    int loginTimes, articles, money;
    DateData lastLogin;
    char gender, flags;
} BloggerData;

Verification(char flag)
{
    if(1 & flag)
    {
        if(1<<2 & flag)
            return "已過(水桶中)";
        return "已經通過認證";
    }
    else
        return "尚未通過認證";
}

Gender(char c)
{
    if(c == 'U')
        return "未知";
    if(c == 'B')
        return "帥哥";
    if(c == 'G')
        return "美女";
    if(c == 'A')
        return "動物";
    if(c == 'P')
        return "植物";
    if(c == 'R')
        return "礦物";
}

Money(int a)
{
    if(a<0)
        return "負債累累";
    if(a >= 0 && a <= 999)
        return "家境清寒";
    if(a >= 1000 && a <= 9999)
        return "家境普通";
    if(a >= 10000 && a <= 19999)
        return "家境小康";
    if(a >= 20000 && a <= 29999)
        return "家境富有";
    if(a >= 30000)
        return "家財萬貫";
}

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
    int bloggertotal = fsize/sizeof(BloggerData);
    fread(blogger, sizeof(BloggerData), bloggertotal, fp);
    fclose(fp);


    printf("總共讀進 %d 位部落客資料。\n", bloggertotal);

    for(int i = 0 ; i<bloggertotal ; i++)
    {
        int firstWeight, thirdWeight, fourthWeight;
        int idweight = strlen(blogger[i].ID);
        int flagweight = strlen(Verification(blogger[i].flags));
        if(idweight >= flagweight)
            firstWeight = idweight;
        else
            firstWeight = flagweight;
        //int loginTiWei = strlen(blogger[i].loginTimes) + 2, artiWei = strlen(blogger[i].articles) + 2, genWei=8, ;
        printf("\nBlogger#%d:\n", i);
        printf("[帳號] %-12s [暱稱] %-19s [上站] %6d次 [文章] %6d篇\n", blogger[i].ID, blogger[i].nickname, blogger[i].loginTimes, blogger[i].articles);
        printf("[認證] %12s [上次] %4d 年 %2d 月 %2d 日 [性別] 我是%s [財產] %s\n", Verification(blogger[i].flags), blogger[i].lastLogin.year, blogger[i].lastLogin.month, blogger[i].lastLogin.day, Gender(blogger[i].gender), Money(blogger[i].money));
    }
}

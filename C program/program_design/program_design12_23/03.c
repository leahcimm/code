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
            return "�w�L(����)";
        return "�w�g�q�L�{��";
    }
    else
        return "�|���q�L�{��";
}

Gender(char c)
{
    if(c == 'U')
        return "����";
    if(c == 'B')
        return "�ӭ�";
    if(c == 'G')
        return "���k";
    if(c == 'A')
        return "�ʪ�";
    if(c == 'P')
        return "�Ӫ�";
    if(c == 'R')
        return "�q��";
}

Money(int a)
{
    if(a<0)
        return "�t�Ųֲ�";
    if(a >= 0 && a <= 999)
        return "�a�ҲM�H";
    if(a >= 1000 && a <= 9999)
        return "�a�Ҵ��q";
    if(a >= 10000 && a <= 19999)
        return "�a�Ҥp�d";
    if(a >= 20000 && a <= 29999)
        return "�a�ҴI��";
    if(a >= 30000)
        return "�a�]�U�e";
}

int main()
{
    FILE *fp = fopen("bloggerData_BIG5.data", "rb");
    if (fp == NULL){
        printf("�}�ɥ���\n");
        return 0;
    }
    BloggerData blogger[100];
    fseek(fp, 0, SEEK_END);
    int fsize = ftell(fp);
    rewind(fp);
    int bloggertotal = fsize/sizeof(BloggerData);
    fread(blogger, sizeof(BloggerData), bloggertotal, fp);
    fclose(fp);


    printf("�`�@Ū�i %d �쳡���ȸ�ơC\n", bloggertotal);

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
        printf("[�b��] %-12s [�ʺ�] %-19s [�W��] %6d�� [�峹] %6d�g\n", blogger[i].ID, blogger[i].nickname, blogger[i].loginTimes, blogger[i].articles);
        printf("[�{��] %12s [�W��] %4d �~ %2d �� %2d �� [�ʧO] �ڬO%s [�]��] %s\n", Verification(blogger[i].flags), blogger[i].lastLogin.year, blogger[i].lastLogin.month, blogger[i].lastLogin.day, Gender(blogger[i].gender), Money(blogger[i].money));
    }
}

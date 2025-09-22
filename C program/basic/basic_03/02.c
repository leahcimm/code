#include <stdio.h>
int main()
{
    int student,Y,M,D,i,stat[14]={0};
    printf("請問有幾位同學？"); scanf("%d",&student);
    printf("請輸入他們的生日 (格式為 年/月/日)。\n");
    for(i=0;i<student;i++)
    {
        scanf("%d/%d/%d",&Y,&M,&D);
        stat[M % 13]++;
    }
    for(i=1;i<13;i++)
        printf("%d月出生的有 %d 位\n",i,stat[i]);
}//92/12/26
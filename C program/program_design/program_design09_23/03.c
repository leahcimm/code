#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int n,m,i;
    system("chcp 65001");
    printf("請問這個月有多少天？");
    scanf("%d",&n);
    printf("請問這個月第一天是星期幾？(0=星期天, 1=星期一, ...) ");
    scanf("%d",&m);
    printf(" S  M  T  W  T  F  S\n");
    for (i=1 ; i<=m; i++)
        printf("   ");
    for(i=1; i<=n; i++)
    {
        printf("%2d ",i);
        if ((m+i)%7 == 0 )
        {
            printf("\n");
        }
    }
}
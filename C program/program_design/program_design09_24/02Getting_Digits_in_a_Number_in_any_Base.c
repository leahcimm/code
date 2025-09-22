#include <stdio.h>

int main()
{
    int num, base, maxbase, i, output;
    printf("請輸入一個非負整數："); scanf("%d", &num);
    printf("請輸入進位制："); scanf("%d", &base);
    maxbase=1;
    i=1;
    while(i<=num)
    {
        maxbase = i;
        i = i * base;
    }

    while(maxbase!=0) //
    {       
        printf("%d", num / maxbase); 
        num = num % maxbase;       
        
        maxbase = maxbase / base;
               
    }
    //printf("%d", num);



    //printf("10進位表示法:",);
}
#include <stdio.h>

int main()
{
    int input, i=1;
    //printf("請猜一個被 3 除餘 2、被 5 除餘 3、被 7 除餘 2 的數："); scanf("%d",&input);
    while(i>0)
    {
        i++;
        printf("請猜一個被 3 除餘 2、被 5 除餘 3、被 7 除餘 2 的數："); scanf("%d",&input);
        if(input%3==2 && input%5==3 && input%7==2)
        {            
            break;
        }
        else
        {           
            printf("錯!");
            continue;
        }
        printf("%d",i);
    }
    if((i-1)==1)
    {
        printf("哇！一次就猜中！超強！");
    }
    else if((i>=2) || (i<=5))
    {
        printf("猜了 %d 次才猜對，有待加強。", (i-1));
    }
    else
    {
        printf("猜了 %d 次才猜對，沒人比你強。", (i-1));
    }
    return 0;
}
//15 28 53 23
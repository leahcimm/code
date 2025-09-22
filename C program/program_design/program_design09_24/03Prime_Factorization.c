#include <stdio.h>

int main()
{
    int number, factor, count;
    printf("Please input a positive number: "); scanf("%d", &number);
    printf("%d = ",number);
    for(factor=2 ; number>1 ;factor++)
    {
        count=0;   //count是factor除了多少次
        
        while(number%factor==0)
        {
            count++;//while的條件已經除過一次了 所以count要加一
            number = number / factor;                        
        }
        
        if(count!=0)
        {
            printf("%d^%d",factor,count);
            if(number!=1)
            {
                printf("*");
            }
        }
        
        
    
    
    }
    return 0;
}
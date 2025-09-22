#include <stdio.h>

int main()
{
    int n, m, i;
    printf("How many sets of test data: ");
    scanf("%d",&n);
    printf("\n");
    for(i=0 ; i<n ; i++) //for裡面是分號(;)
    {
        printf("Input a number: ");
        scanf("%d",&m);//scanf要記得加&
        printf("\n");
        if (m % 5==0 && m % 7 ==0 )
        {    
            printf("%d is a multiple of 5.\n", m);
            printf("%d is a multiple of 7.\n", m);
            printf("\n");
        }
        else if(m % 5 == 0)
        {
            printf("%d is a multiple of 5.\n", m);
            printf("\n");
            
        }
        else if(m % 7 == 0)
        {
            printf("%d is a multiple of 7.\n", m);
            printf("\n");
        }

        else //不用加小括弧
        {
            
            printf("\n");
        }

    }
    printf("Over!\n");

        
}
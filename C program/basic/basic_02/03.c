#include <stdio.h>
int main()
{
    int data, i, val, dig, x, y, s, c, d;
    printf("How many sets of test data: "); scanf("%d", &data);
    for(i=0;i<data;i++)
    {
        printf("Input the value of a (1 ~ 9): "); scanf("%d",&val);
        while((val<1) || (val>9))
        {
            printf("Input the value of a (1 ~ 9): "); scanf("%d",&val);
        }
        
        printf("Input the number of digits (1 ~ 9): "); scanf("%d",&dig);
        while((dig<1) || (dig>9))
        {
            printf("Input the number of digits (1 ~ 9): "); scanf("%d",&dig);
        }
        
        s=0;
        printf("s =");
        d=val;
        for (y=0;y<dig;y++)
        {
            printf(" %d ", val);
            s=val+s;
            val=val*10+1*d;
            //printf("%d",val);
            if(y==(dig-1))
            {
                break;
            }
            printf("+");
        }
        printf("= ");
        printf("%d\n", s);
        printf("\n");
        }
    }
//2 3 5
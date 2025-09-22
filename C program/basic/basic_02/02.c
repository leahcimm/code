#include <stdio.h>
int main() //3 12345 7878495 100
{
    int data, num, rev, i, x, y=1;
    printf("How many sets of test data: "); scanf("%d", &data);
    //printf("\n");
    for( i=0 ; i<data ; i++ )
    {
        printf("\n");
        printf("Input a number: "); scanf("%d", &num);
        
        printf("Reverse: ");
        while(num>0)
        {
            x = num % 10;
            num=num/10;
            printf("%d", x);

        }
        printf("\n");
        

    }
}
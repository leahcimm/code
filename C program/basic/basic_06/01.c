#include <stdio.h>
int main()
{
    unsigned numU;
    int i, j, sets, interval;
    printf("How many sets of test data: ");
    scanf("%d",&sets);
    for(i = 0 ; i < sets ; i++)
    {
        printf("\nPlease input a large integer: ");
        scanf("%u", &numU);
        printf("Please input an interval: ");
        scanf("%d", &interval);
        printf("Your input is [%u]\n",numU);
        printf("Its next 10 numbers by adding %d are:\n",interval);
        for(j = 0 ; j < 10 ; j++)
        {
            numU = numU + interval;
            printf("%u\n", numU);
        }
        numU = 0;
        printf("Over!!\n");
    }
}
/*
3
3214567890
8
4024549127
13
2984341603
-6
*/
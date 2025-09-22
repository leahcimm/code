#include <stdio.h>

int main()
{
    int sets, i, j, x=1, input;
    printf("How many sets of test data: ");
    scanf("%d", &sets); if(getchar() == '\r') getchar();
    for(i=0 ; i<sets ; i++)
    {
        printf("\nInput: "); scanf("%d", &input); if(getchar() == '\r') getchar();
        printf("The 1 bits are at: ");
        x=1;
        for(j=0 ; j<32 ; j++)
        {
            if(input & x)
                printf("%d ", j);
            x <<= 1;
        }
        printf("\n");
    }
}
#include <stdio.h>

int main()
{
    int sets, i, j, x=1, Number, Position;
    printf("How many sets of test data: ");
    scanf("%d", &sets); if(getchar() == '\r') getchar();
    for(i=0 ; i<sets ; i++)
    {
        printf("\nNumber: "); scanf("%d", &Number); if(getchar() == '\r') getchar();
        printf("Position: "); scanf("%d", &Position); if(getchar() == '\r') getchar();
        //printf("It is a %d bit.",( ((1<<Position)&Number) == (1<<Position) ));
        x=1;
        x <<= Position;
        if(Number & x)
            printf("It is a 1 bit.");
        else
            printf("It is a 0 bit.");
        printf("\n");
    }
}
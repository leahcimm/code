#include <stdio.h>
#include <string.h>

int main()
{
    int sets, i;
    char inputStr[1000], symbol[300], *p;
    printf("How many sets of test data: "); scanf("%d", &sets); if (getchar() == '\r') getchar();
    for(i = 0 ; i < sets ; i++)
    {
        printf("Input a string: ");
        fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n");
        printf("Divided by what symbols: ");
        fgets(symbol, sizeof(symbol), stdin); strtok(symbol, "\r\n");
        p = strtok(inputStr, symbol);
        while(p != NULL)
        {
            printf("[%s] length = %d\n", p, strlen(p));
            p = strtok(NULL, symbol);
        }
        printf("\n");
    }
}
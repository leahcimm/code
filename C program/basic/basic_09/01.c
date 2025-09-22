#include <stdio.h>
#include <string.h>
int main()
{
    int repeatTimes, ti;
    
    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes); if (getchar() == '\r') getchar();
    
    char sent[300];
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\n");
        printf("Input a line:\n");
        fgets(sent, sizeof(sent), stdin); strtok(sent, "\r\n");
		printf("Modified line:\n");
        char *p = sent;
        while(*p != '\0')
        {
            if(!((*p >= '0' && *p <= '9') || *p == '.' || *p == '%'))
            {
                *p = '_';
            }
            printf("%c", *p);
            p++;
        }
        printf("\n");
    }
    return 0;
}
/*
The Dow Jones Industrial Average ended 32.62 higher, or 0.28%, to 11555.63;
and the Nasdaq finished 11.83 lower, or 0.47%, to 2515.51.
*/
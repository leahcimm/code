#include <stdio.h>
#include <string.h>
int main()
{
    int repeatTimes, ti, skp;
    
    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes);
    
    char sent[300];
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\n");
        printf("Input a string: \n");
        if(getchar() == '\r') getchar(); fgets(sent, sizeof(sent), stdin); strtok(sent, "\r\n");
		printf("Skipping = "); scanf("%d", &skp);
        char *p = sent;
        int size = strlen(sent); //strlen(str)
        while( p < sent + size )
        {
            printf("[%s]", p);
            p = p + skp;
            printf("\n");
        }
    }
    return 0;
}
/*
3
The Dow Jones Industrial Average ended 32.62 higher, or 0.28%, to 11555.63;
4
and the Nasdaq finished 11.83 lower, or 0.47%, to 2515.51
7
National Taiwan Ocean University was originally established in 1953
5
*/
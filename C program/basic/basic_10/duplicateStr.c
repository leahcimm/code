#include <stdio.h>
#include <string.h>

void duplicateStr(char dest[], char *src, int n)
{
    dest[0] = '\0'; //WHY??
    for(int i = 0 ; i < n ; i++)
        strcat(dest, src);
}

int main() {
    char newStr[1000], inputStr[1000];
    int ti, repeatTimes, rpTimes;
    printf("How many sets of test data: "); scanf("%d", &repeatTimes); if (getchar() == '\r') getchar();// get repeatTimes from keyboard
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nInput a string: ");
        fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n");  // or fgets(???)
        printf("Duplicate how many times: ");
        scanf("%d", &rpTimes); if (getchar() == '\r') getchar();
        duplicateStr(newStr, inputStr, rpTimes);
        printf("The new string is [%s]\n", newStr);
    }
    return 0;
}
/*
Koka
5
yesterday
-2
\(^_^)/
10
S.H.E.
8
see\
15
*/
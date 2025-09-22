#include <stdio.h>
#include <string.h>

void reverseStr(char str[])
{
    int n = strlen(str);
    for(int i=0 ; i<n/2 ; i++)
    {
        int j = str[i];
        str[i] = str[n-i-1];
        str[n-1-i] = j;
    }
};

int main()
{
    char inputStr[300];
    int ti, repeatTimes;
    printf("How many sets of test data: "); scanf("%d", &repeatTimes);
    if(getchar() == '\r') getchar();
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nInput a string: ");
        fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n");
        reverseStr(inputStr);
        printf("The reversed string is [%s]\n", inputStr);
    }
    return 0;
}
/*
3
Something special
I am 100% sure about this (haha)!
To be or not to be.
*/
#include <stdio.h>
#include <string.h>

char * myStrRchr(char * sentence, char c)
{
    char *sp = sentence;
    while(*sp != '\0')
        sp++;
    while(sp != sentence-1)
    {
        if(*sp == c) return sp;
        sp--;
    }
    return NULL;
}

int main()
{
    int sets, i;
    char inputStr[1000], symbol, *p=inputStr;
    printf("How many sets of test data: "); scanf("%d", &sets); if(getchar() == '\r') getchar();
    for(i=0 ; i<sets ; i++)
    {
        p = inputStr;//要把*p歸位到最頭, 不然在跑第二次的時候p就會是NULL這樣就不會進到底下的while裡面了
        printf("\nInput a string: "); fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n"); //fgets專門拿來吃字串用的, 阿如果要單吃字元的話用scanf就可以了
        printf("Divided by what symbol: "); scanf("%c", &symbol); if(getchar() == '\r') getchar();
        printf("Results:\n");
        while(p != NULL)
        {
            printf("[%s]\n", inputStr);
            p = myStrRchr(inputStr, symbol);
            if( p != NULL ) *p = '\0'; //這邊要記得用if判斷, 不是NULL才要改成'\0', 如果是NULL還改成'\0'的話那第一個字元就會被吃掉
        }
    }
}
/*
2
4,654,123,678,944,028,763
,
National Taiwan Ocean University was originally established in 1953
 
*/
#include <stdio.h>
int main()
{
    char ch;
    while((ch = getchar()) != '\n')
    {
        if(ch >= 'A' && ch <= 'Z')
            printf("%c", (ch - 'A'+28)%26 + 'A');//+2+26
        else if(ch >= 'a' && ch <= 'z')
            printf("%c",(ch - 'a'+28)%26 + 'a');//+2+26
        else if(ch >= '0' && ch <= '9')
            printf("%c", (ch- '0'+9)%10 + '0');//-1+10
        else printf("%c", ch);
    }
}
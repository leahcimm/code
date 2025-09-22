#include <stdio.h>
int main()
{
    char ch;
    while((ch = getchar()) != '\n')
    {
        printf("[%c] %d ==> [%c] %d\n", ch, ch, ch + 1, ch + 1);
    }
}
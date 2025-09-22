#include <stdio.h>

void over(){ printf("over"); }
void over( int a ) { printf("%d",a); }

int main()
{
    over();
}
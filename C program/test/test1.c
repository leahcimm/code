#include <stdio.h>
#include <stdlib.h>
void hanoi(int n, char start, char goal, char other)
{
    if (n == 1)
    {
        printf("從 %c 柱移到 %c 柱\n", start, goal);
    }
    else 
    {
        hanoi(n-1, start, other, goal);
        hanoi( 1 , start, goal, other);
        hanoi(n-1, other, goal, start);
    }
}

int main()
{
    system("chcp 65001");
    hanoi(5, 'A', 'C', 'B');
    return 0;
}

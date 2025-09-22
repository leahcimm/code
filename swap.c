#include <stdio.h>
void swap(int *k, int *t)
{
    int n = *k;
    *k = *t;
    *t = n;
}
int main ()
{
    int k = 6, t = 33;
    swap(&k, &t);
    printf("")
    return 0;
}

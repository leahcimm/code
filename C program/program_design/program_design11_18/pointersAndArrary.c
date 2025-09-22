#include <stdio.h>
void strangeFunc(int arr[], int size);
void printArray(int arr[], int size, int c);
void swap(int *a, int *b);
int main() {
    int a[13] = {65, 0, -5, -22, 9, 231, 43, -7, 11, -65, 0, -18, 65};
    int b[12] = {65, 0, -5, -22, 9, 231, 43, -7, 11, 65, 0, -18};
    int c[12] = {65, 0, 5, 22, 9, 231, 43, 7, 11, 65, 0, 18};

    printArray(a, 13, 'a');
    printArray(b, 12, 'b');
    printArray(c, 12, 'c');
    printf("\n");

    strangeFunc(a, 13);
    strangeFunc(b, 12);
    strangeFunc(c,12);

    printArray(a, 13, 'a');
    printArray(b, 12, 'b');
    printArray(c, 12, 'c');

    return 0;
}
void printArray(int arr[], int size, int c)
{
    printf("原先%c[]為 {", c);
    for(int j=0 ; j<size-1 ; j++)
        printf("%d, ", arr[j]);
    printf("%d}\n", arr[size-1]);
}
void strangeFunc(int arr[], int size)
{
    int *p = arr, *q = arr + (size-1);
    while(p<q)
    {
        if(*p >= 0)
        {
            p++;
            continue;
        }
        if(*q >= 0)
        {
            q--;
            continue;
        }
        if(*p < 0 && *q < 0)
        {
            swap(p, q);
            p++;
            q--;
        }
    }
}
void swap(int *a, int *b)
{
    int n = *a;
    *a = *b;
    *b = n;
}
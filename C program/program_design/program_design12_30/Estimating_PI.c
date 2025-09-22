#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int times = 0, i, n=1000;
    double x, y, pi;
    srand((unsigned int)time(NULL));
    for(i = 1 ; i <= 1000000000 ; i++) {
        x = (double)rand() / RAND_MAX;//轉(double)
        y = (double)rand() / RAND_MAX;
        if((x * x + y * y) <= 1) {
            times++;
            if(i == n) {
                pi = ((double)times/i)*4.0;
                printf("After %d points, PI = %lf\n", i, pi);
                n = n * 10;
            }
        }
    }
}
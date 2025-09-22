#include <stdio.h>
int main ()
{
    int A[20][20] = {0}, B[20][20] = {0}, C[20][20] = {0};
    int sets, i, j, k, l, m, n, p;
    printf("A is a matrix with m x n elements and\n");
    printf("B is a matrix with n x p elements.\n");
    printf("\n");
    printf("How many sets of test data: "); scanf("%d",&sets);    
    for(i = 0 ; i < sets ; i++) //幾組測資就跑幾次
    {
        for(j = 0 ; j < 20 ; j++)
        {
            for(k = 0 ; k < 20 ; k++)
            {
                A[j][k] = 0;
            }           
        }
        for(j = 0 ; j < 20 ; j++)
        {
            for(k = 0 ; k < 20 ; k++)
            {
                B[j][k] = 0;
            }           
        }
        for(j = 0 ; j < 20 ; j++)
        {
            for(k = 0 ; k < 20 ; k++)
            {
                C[j][k] = 0;
            }           
        }
        printf("\n");
        printf("Input values of m, n, p: "); scanf("%d %d %d", &m, &n, &p); //填入matrix的大小
        printf("Input numbers in matrix A: ");
        for(j = 0 ; j < m ; j++)//填matrix_A
        {
            for(k = 0 ; k < n ; k++)
            {
                scanf("%d", &A[j][k]);
            }
        }          
        printf("Input numbers in matrix B: ");
        for(j = 0 ; j < n ; j++)//填matrix_B
        {
            for(k = 0 ; k < p ; k++)
            {
                scanf("%d", &B[j][k]);
            }            
        }
        //開始做運算matrix_A * matrix_B = matrix_C        
        for(j = 0 ; j < m ; j++)
        {
            for(k = 0 ; k < p ; k++)
            {
                for(l = 0 ; l < n ; l++)
                {
                    C[j][k] += A[j][l] * B[l][k];
                }
            }            
        }
        printf("Numbers in matrix C are:\n{{");
        //printf("{{"); 看上面那一行
        for(j = 0 ; j < m ; j++)
        {
            for(k = 0 ; k < p ; k++)
            {
                printf("%d", C[j][k]);
                if(k+1 != p)
                printf(", ");
                if(k+1 == p)
                {
                    printf("}");
                    if(k+1 == p && j+1 != m)
                    {
                        printf(",");                        
                    }                    
                    if(j+1 != m)
                    printf("\n{");                    
                }                
            }            
        }
        printf("}\n");
    }
}
/*
2
2 3 4
2 7 4 2 8 6
8 5 2 4 6 8 0 6 3 2 5 7
3 4 2
2 1 32 -6 8 6 12 76 87 -3 4 9
28 43 4 65 -7 23 0 11
*/
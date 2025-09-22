#include <stdio.h>
int main ()
{
    int A[20][20] = {0}, B[20][20] = {0}, C[20][20] = {0};
    int sets, i, m, n, x = 0, y = 0, j, k;
    printf("Both A and B are matrices with m x n elements.\n");
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
        printf("\n");
        printf("Input values of m and n: "); scanf("%d %d", &m, &n);
        printf("Input numbers in matrix A: ");//填matrix_A
        for(j = 0 ; j < m ; j++) //有幾row就要跑幾次
        {
            for(k = 0 ; k < n ; k++) //橫的方向填數字過去
            {
                scanf("%d", &A[j][k]);
            }      
        }
        printf("Input numbers in matrix B: ");//填matrix_B
        for(j = 0 ; j < m ; j++) //有幾row就要跑幾次
        {
            for(k = 0 ; k < n ; k++) //橫的方向填數字過去
            {
                scanf("%d", &B[j][k]);
            }       
        }     
        for(j = 0 ; j < m ; j++)// matrix填完後 開始做 matrix_A + matrix_B
        {            
            for(k = 0 ; k < n ; k++)
            {
                C[j][k] = A[j][k] + B[j][k];
            }
        }
        printf("Numbers in matrix C are:\n");
        printf("{{");
        for(j = 0 ; j < m ; j++)
        {
            for(k = 0 ; k < n ; k++)
            {
                printf("%d", C[j][k]);
                if(k+1 != n)
                printf(", ");
                if(k+1 == n)
                {
                    printf("}");
                    if(k+1 == n && j+1 != m)
                    {
                        printf(",");                        
                    }                    
                    if(j+1 != m)
                    printf("\n");                    
                    if(j+1 != m)
                    printf("{");
                }                
            }            
        }
        printf("}");
        printf("\n");
    }
}
/*
2
2 3
2 7 4 2 8 6
8 5 2 6 8 0
4 2
2 1 8 6 87 -3 32 -6
28 43 4 65 -7 23 0 11
*/

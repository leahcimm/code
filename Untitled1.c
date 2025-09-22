#include <stdio.h>
#define width 157
#define height 44
char *maze[2 * height + 1][2 * width + 1];
void initMaze();
void printMaze();
int main()
{
    initMaze();
    printMaze();
}
void initMaze()
{
    int i, j;
    for(i=0 ; i<2 * height + 1 ; i++)
    {
        for(j=0 ; j<2 * width + 1 ; j++)
        {
            if(i % 2 == 1 && j % 2 == 1) maze[i][j] = '?';
            else maze[i][j] = "⊠";

        }
    }
    maze[1][0] = ' ';maze[1][1] = ' ';//
    maze[2 * height-1][2 * width ] = ' ';
}
void printMaze()
{
    int i, j;
    for(i=0 ; i<2 * height + 1 ; i++)
    {
        for(j=0 ; j<2 * width + 1 ; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

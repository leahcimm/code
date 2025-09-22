#include <stdio.h>
#include <time.h>
#define width 188
#define height 48
char* maze[2 * height + 1][2 * width + 1];
void initMaze();
void createMaze(int n, int k);
void printMaze();
int main()
{
    srand((unsigned int)time(NULL));
    system("chcp 65001");
    initMaze();
    createMaze(1, 1);
    printMaze();
    return 0;
}
void initMaze()
{
    int i, j;
    for(i=0 ; i<2 * height + 1 ; i++)
    {
        for(j=0 ; j<2 * width + 1 ; j++)
        {
            if(i % 2 == 1 && j % 2 == 1) maze[i][j] = "?";
            else maze[i][j] = "0";

        }
    }
    maze[1][0] = " ";maze[1][1] = " ";//é_¿Ú
    maze[2 * height-1][2 * width ] = " ";
}
void createMaze(int n, int k)
{
    int i, count;
    int offsetX[4] = {-2, 2, 0, 0};
    int offsetY[4] = {0, 0, -2, 2};
    while(1)
    {

        count = 0;
        for(i=0 ; i<4 ; i++)
        {
            if(maze[n + offsetX[i]][k + offsetY[i]] == "?")
                count++;
        }
        if( count==0 ) return ;
        else
        {
            int R = rand() % 4;
            while(maze[n + offsetX[R]][k + offsetY[R]] != "?")
            {
                R=rand()%4;
            }
            maze[n + offsetX[R]][k + offsetY[R]] = " ";
            maze[n + offsetX[R]/2][k + offsetY[R]/2] = " ";
            createMaze(n + offsetX[R], k + offsetY[R]);//veryhard
        }
    }
}
void printMaze()
{
    int i, j;
    for(i=0 ; i<2 * height + 1 ; i++)
    {
        for(j=0 ; j<2 * width + 1 ; j++)
        {
            printf("%s", maze[i][j]);
        }
        printf("\n");
    }
}

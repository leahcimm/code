#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int board[4][8] = { 0 };

void gameInit();
void printBoard();

int main()
{
    int;
    srand((unsigned int)time(NULL));
     // (for Windows users) force the command window to show unicode characters

    gameInit();
    printBoard ();
    // your main function here

    return 0;
}


void printBoard()
{
    int i, j;
    char *chessBlack[9] = { "卒", "卒", "卒", "包", "馬", "車", "象", "士", "將"}, *chessRed[9] = { "兵", "兵", "兵", "炮", "傌", "俥", "相", "仕", "帥"};

    printf("x\\y  0  1  2  3  4  5  6  7\n");
    for(i=0 ; i<4 ; i++)
    {

        if( i==0 ) printf("   ┌──┬──┬──┬──┬──┬──┬──┬──┐\n");
        else printf("   ├──┼──┼──┼──┼──┼──┼──┼──┤\n");
        printf("%d  ", i);
        for(j=0 ; j<8 ; j++)
        {
            if( board[i][j]<0 ) printf("│●");
            else if ( board[i][j]>0 )
            {
                if ( board[i][j] <= 16 ) printf("│%s", chessBlack[board[i][j]/2]);
                else printf("│%s", chessRed[ (board[i][j]-16)/2 ]);
            }
            else printf("│  ");
        }
        printf("│\n");
    }
    printf("   └──┴──┴──┴──┴──┴──┴──┴──┘");
    // your first basic problem
}
void gameInit()
{
    board[0][2] = -8;
    board[0][3] = 12;
    board[1][7] = 28;
}

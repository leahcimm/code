#include <stdio.h>
#include <stdlib.h>

int puzzle[9][9]={0};

void inputQuiz() {
    int i, j, k, tmp;
    printf("please input:\n");
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            scanf("%1d", &puzzle[i][j]);
        }
    }
    
} // 將所有格子都設為 0, 再由鍵盤讀入題目
void printGameField() {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("┼───");
            if(j==8)
                printf("┼");
        }
        printf("\n");
        for (j = 0; j < 9; j++) {
            printf("│ %d ", puzzle[i][j]);
            if(j==8)
                printf("│");
        }
        printf("\n");
        for (j = 0; j < 9; j++) {
            if(i==8){
                printf("┼───");
                if(j==8){
                    printf("┼");
                    printf("\n");
                }
            }
        }
}
} // 借用自中國暗棋遊戲印出畫面
/*void removeCandidate(int i, int j, int value) { // 當 puzzle[i][j] 確定填入 value, 其他格就不能填
    同一列之 candidate[??][??][value] 改為 0 or false
    同一欄之 candidate[??][??][value] 改為 0 or false
    同一宮之 candidate[a][b][value] 改為 0 or false // a, b 的起終範圍可由 i, j 算出
    puzzle[i][j] 之 candidate[i][j][???] 全改為 0 or false
}
void startFindSolution() {
    先把 candidate[0][0][0] ~ candidate[8][8][9] 全設為 1 or true
    檢查每一格 puzzle[i][j]
        puzzle[i][j] 有值的時候呼叫 removeCandidate(...)
}
int solveBySingleSol() {
    檢查每一格 puzzle[i][j]
        當 puzzle[i][j] 沒有值而且只有一種填法
            puzzle[i][j] 填入值
            呼叫 removeCandidate(...)
            return 1;
    return 0;
}*/
int main() {
    system("chcp 65001|cls");
    /*puzzle[0][0] = 5; puzzle[0][1] = 3; puzzle[0][4] = 7;
    puzzle[1][0] = 6; puzzle[1][3] = 1; puzzle[1][4] = 9; puzzle[1][5] = 5;
    puzzle[2][1] = 9; puzzle[2][2] = 8; puzzle[2][7] = 6;
    puzzle[3][0] = 8; puzzle[3][4] = 6; puzzle[3][8] = 3;
    puzzle[4][0] = 4; puzzle[4][3] = 8; puzzle[4][5] = 3; puzzle[4][8] = 1;
    puzzle[5][0] = 7; puzzle[5][4] = 2; puzzle[5][8] = 6;
    puzzle[6][1] = 6; puzzle[6][6] = 2; puzzle[6][7] = 8;
    puzzle[7][3] = 4; puzzle[7][4] = 1; puzzle[7][5] = 9; puzzle[7][8] = 5;
    puzzle[8][4] = 8; puzzle[8][7] = 7; puzzle[8][8] = 9;*/
    inputQuiz();
    printGameField();
    /*startFindSolution();
    int yes = 1;
    while (yes > 0) {
        yes = 0;
        yes += solveBySingleSol();
        // yes += otherSolution(); // add other solutions in the future
    }
    printGameField();*/
    return 0;
}
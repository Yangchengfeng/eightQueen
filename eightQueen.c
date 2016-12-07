#include <stdio.h>

int count = 0;

int notDanger(int row, int line, int (*chess)[8]) {
    int i, k, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5  = 0;
    for(i=0; i<8; i++) { // 判断列
        if(*(*(chess+i)+line)!=0) {
            flag1 = 1;
            break;
        }
    }
    for(i=row,k=line; i>=0&&k>=0; i--,k--) { // 判断左上方
        if(*(*(chess+i)+k)!=0) {
            flag2 = 1;
            break;
        }
    }
    for(i=row,k=line; i<8&&k<8; i++,k++) { // 判断右下方
        if(*(*(chess+i)+k)!=0) {
            flag3 = 1;
            break;
        }
    }
    for(i=row,k=line; i>=0&&k<8; i--,k++) { // 判断右上方
        if(*(*(chess+i)+k)!=0) {
            flag4 = 1;
            break;
        }
    }
    for(i=row,k=line; i<8&&k>=0; i++,k--) { // 判断左下方
        if(*(*(chess+i)+k)!=0) {
            flag5 = 1;
            break;
        }
    }
    if(flag1||flag2||flag3||flag4||flag5) {
        return 0;
    }  else {
        return 1;
    }
}

void eightQueen(int row, int line, int (*chess)[8]) { // 行、列、棋盘的指针
    int chess1[8][8], i, j; // chess1为临时棋盘
    for(i = 0; i<8; i++) {
        for(j = 0; j<8; j++) {
            chess1[i][j] = chess[i][j];
        }
    }
    if(row == 8) { // 递归结束的条件，打印棋盘情况
        printf("第%d种情况:\n", count + 1);
        for(i = 0; i<8; i++) {
            for(j = 0; j<8; j++) {
                printf("%d", *(*(chess1+i)+j));
            }
            printf("\n");
        }
        printf("\n\n");
        count++;
    } else {
        for(j=0; j<line; j++) {
            if(notDanger(row, j, chess)) { // 判断是否合适
                for(i = 0; i<8; i++) {
                    *(*(chess1+row)+i) = 0;
                }
                *(*(chess1+row)+j) = 1;
                eightQueen(row+1, line, chess1);
            }
        }
    }
}

int main()
{
    int chess[8][8] = {0}; // 初始化为0，表示没放置棋子
    eightQueen(0, 8, chess);
    return 0;
}
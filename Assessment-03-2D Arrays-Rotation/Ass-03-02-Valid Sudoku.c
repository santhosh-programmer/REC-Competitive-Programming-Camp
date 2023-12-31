// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.

// Each column must contain the digits 1-9 without repetition.

// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:

// ·         A Sudoku board (partially filled) could be valid but is not necessarily solvable.

// ·         Only the filled cells need to be validated according to the mentioned rules.

// Example 1:

// Input: board =

// [["5","3",".",".","7",".",".",".","."]

// ,["6",".",".","1","9","5",".",".","."]

// ,[".","9","8",".",".",".",".","6","."]

// ,["8",".",".",".","6",".",".",".","3"]

// ,["4",".",".","8",".","3",".",".","1"]

// ,["7",".",".",".","2",".",".",".","6"]

// ,[".","6",".",".",".",".","2","8","."]

// ,[".",".",".","4","1","9",".",".","5"]

// ,[".",".",".",".","8",".",".","7","9"]]

// Output:

// true

// Example 2:

// Input: board =

// [["8","3",".",".","7",".",".",".","."]

// ,["6",".",".","1","9","5",".",".","."]

// ,[".","9","8",".",".",".",".","6","."]

// ,["8",".",".",".","6",".",".",".","3"]

// ,["4",".",".","8",".","3",".",".","1"]

// ,["7",".",".",".","2",".",".",".","6"]

// ,[".","6",".",".",".",".","2","8","."]

// ,[".",".",".","4","1","9",".",".","5"]

// ,[".",".",".",".","8",".",".","7","9"]]

// Output:

// false

// Explanation:

// Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

// Constraints:

// board.length == 9

// board[i].length == 9

// board[i][j] is a digit 1-9 or '.'.


// For example:

// Input	Result
// 53..7....
// 6..195...
// .98....6.
// 8...6...3
// 4..8.3..1
// 7...2...6
// .6....28.
// ...419..5
// ....8..79
// true
// 83..7....
// 6..195...
// .98....6.
// 8...6...3
// 4..8.3..1
// 7...2...6
// .6....28.
// ...419..5
// ....8..79
// false

#include<stdio.h>
int main() {
    int n=9;
    char a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%c",&a[i][j]);
        scanf("\n");
    }
    for(int i=0;i<n;i++) {
        int temp[10]={};
        for(int j=0;j<n;j++) {
            if(a[i][j]>=48 && a[i][j]<=57) {
                if( temp[(int)a[i][j]-48]!=0) {
                    printf("false");
                    return 0;
                }
                else temp[(int)a[i][j] -48 ]=1;
            }
        }
    }
    for(int i=0;i<n;i++) {
        int temp[10]={};
        for(int j=0;j<n;j++) {
            if(a[j][i]>=48 && a[j][i]<=57) {
                if( temp[(int)a[j][i]-48]!=0) {
                    printf("false");
                    return 0;
                }
                else temp[(int)a[j][i] -48 ]=1;
            }
        }
    }
    for(int x=0;x<9;x+=3) {
        int temp[10]={};
        for(int i=x;i<x+3;i++) {
            for(int j=x;j<x+3;j++) {
                if(a[i][j]>=48 && a[i][j]<=57) {
                    if(temp[ (int) a[i][j] -48 ]!=0) {
                        printf("false");
                        return 0;
                    }
                    else temp[ (int) a[i][j] -48 ]=1;
                }
            }
        }
    }
    printf("true");
}


// UPDATED CODE WITH ERRORS FIXED

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int n=9;
    for(int i=0;i<n;i++) {
        int temp[10]={};
        for(int j=0;j<n;j++) {
            if(board[i][j]!='.') {
                if( temp[(int)board[i][j]-48]!=0) return false;
                else temp[(int)board[i][j] -48 ]=1;
            }
        }
    }
    for(int i=0;i<n;i++) {
        int temp[10]={};
        for(int j=0;j<n;j++) {
            if(board[j][i]!='.') {
                if( temp[(int)board[j][i]-48]!=0) return false;
                else temp[(int)board[j][i] -48 ]=1;
            }
        }
    }
    for(int x=0;x<9;x+=3) {
        for(int y=0;y<9;y+=3) {
            int temp[10]={};
            for(int i=x;i<x+3;i++) {
                for(int j=y;j<y+3;j++) {
                    if(board[i][j]!='.') {
                        if(temp[ (int) board[i][j] -48 ]!=0) return false;
                        else temp[ (int) board[i][j] -48 ]=1;
                    }
                }
            }
        }
    }
    return true;
}

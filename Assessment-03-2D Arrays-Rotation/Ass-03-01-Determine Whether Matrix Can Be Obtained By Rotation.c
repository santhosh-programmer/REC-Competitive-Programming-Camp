// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

// Example 1:



// Input:

// mat = [[0,1],[1,0]], target = [[1,0],[0,1]]

// Output:

// true

// Explanation:

// We can rotate mat 90 degrees clockwise to make mat equal target.

// Example 2:



// Input:

// mat = [[0,1],[1,1]], target = [[1,0],[0,1]]

// Output:

// false

// Explanation:

// It is impossible to make mat equal to target by rotating mat.

// Example 3:



// Input:

// mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]

// Output:

// true

// Explanation:

// We can rotate mat 90 degrees clockwise two times to make mat equal target.

// Constraints:

// n == mat.length == target.length

// n == mat[i].length == target[i].length

// 1 <= n <= 10

// mat[i][j] and target[i][j] are either 0 or 1.



// For example:

// Input	Result
// 2
// 0 1
// 1 0
// 1 0
// 0 1
// true
// 2
// 0 1
// 1 1
// 1 0
// 0 1
// false


#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int mat[n][n],tar[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&mat[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&tar[i][j]);
    }
    for(int k=0;k<4;k++) {
        for(int i=0;i<n/2;i++) {
            for(int j=i;j<n-i-1;j++) {
                int temp=mat[i][j];
                mat[i][j]=mat[n-j-1][i];
                mat[n-j-1][i]=mat[n-i-1][n-j-1];
                mat[n-i-1][n-j-1]=mat[j][n-i-1];
                mat[j][n-i-1]=temp;
            }
        }
        int f=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]!=tar[i][j]) {
                    f=1;
                    break;
                }
            }
        }
        if(f==0) {
            printf("true");
            return 0;
        }
    }
    printf("false");
}

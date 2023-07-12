// Given an n x n matrix, return all elements of the matrix in spiral order.

// Example 1:



// Input:

// matrix = [[1,2,3],[4,5,6],[7,8,9]]

// Output:

// [1,2,3,6,9,8,7,4,5]

// Constraints:

// n == matrix.length

// n == matrix[i].length

// 1 <= n <= 10

// -100 <= matrix[i][j] <= 100
// For example:

// Input	Result
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// 1 2 3 6 9 8 7 4

#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n/2;i++) {
        for(int j=i;j<n-i-1;j++) printf("%d ",a[i][j]);
        for(int j=i;j<n-i-1;j++) printf("%d ",a[j][n-i-1]);
        for(int j=n-i-1;j>i;j--) printf("%d ",a[n-i-1][j]);
        for(int j=n-i-1;j>i;j--) printf("%d ",a[j][i]);
    }
    if((n%2)!=0) printf("%d",a[n/2][n/2]);
}

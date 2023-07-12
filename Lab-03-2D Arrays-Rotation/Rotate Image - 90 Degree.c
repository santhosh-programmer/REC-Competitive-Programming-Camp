// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// Example 1:



// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

// Output:

// [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:



// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

// Output:

// [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Constraints:

// n == matrix.length == matrix[i].length

// 1 <= n <= 20

// -1000 <= matrix[i][j] <= 1000



// For example:

// Input	Result
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// 7 4 1
// 8 5 2
// 9 6 3


#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    for(int i=0;i<n/2;i++) {
        for(int j=i;j<n-i-1;j++) {
             int temp=a[i][j];
             a[i][j]=a[n-j-1][i];
             a[n-j-1][i]=a[n-i-1][n-j-1];;
             a[n-i-1][n-j-1]=a[j][n-i-1];
             a[j][n-i-1]=temp;
        }
    } 
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

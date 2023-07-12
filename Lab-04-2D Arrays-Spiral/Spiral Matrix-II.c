// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:



// Input:

// n = 3

// Output:

// [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:

// Input:

// n = 1

// Output:

// [[1]]

// Constraints:

// 1 <= n <= 20


// For example:

// Input	Result
// 3
// 1 2 3
// 8 9 4
// 7 6 5
// 1
// 1
// Answer:(penalty regime: 0 %)

#include<stdio.h>
int main() {
    int n,counter=1;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n/2;i++) {
        for(int j=i;j<n-i-1;j++) {
            a[i][j]=counter;
            counter++;
        }
        for(int j=i;j<n-i-1;j++) {
            a[j][n-i-1]=counter;
            counter++;
        }
        for(int j=n-i-1;j>i;j--) {
            a[n-i-1][j]=counter;
            counter++;
        }
        for(int j=n-i-1;j>i;j--) {
            a[j][i]=counter;
            counter++;
        }
    }
    if((n%2)!=0) a[n/2][n/2]=n*n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}

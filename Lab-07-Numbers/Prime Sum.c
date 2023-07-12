// Given an even number (greater than 2), return two prime numbers whose sum will be equal to given number.

// NOTE: A solution will always exist.

// Example:

// Input:

// 4

// Output:

// 2 + 2 = 4

// If there are more than one solutions possible, return the lexicographically smaller solution.

// If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then

// [a, b] < [c, d]

// If a < c OR a==c AND b < d.


// For example:

// Input	Result
// 4
// 2 2


#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int check[n+1];
    for(int i=2;i<=n;i++) check[i]=1;
    for(int i=2;i*i<=n;i++) {
        if(check[i]) for(int j=i*2;j<=n;j+=i) check[j]=0;
    }
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            if( i+j==n && check[i] && check[j] ) {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
}

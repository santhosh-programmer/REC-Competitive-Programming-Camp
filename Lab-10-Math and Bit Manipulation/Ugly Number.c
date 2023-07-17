// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

// Example 1:

// Input:

// n = 6

// Output:

// true

// Explanation:

// 6 = 2 × 3

// Example 2:

// Input:

// n = 1

// Output:

// true

// Explanation:

// 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

// Example 3:

// Input:

// n = 14

// Output:

// false

// Explanation:

// 14 is not ugly since it includes the prime factor 7.

// Constraints:

// -231 <= n <= 231 - 1


// For example:

// Input	Result
// 6
// true
// 1
// true
// 14
// false

#include<stdio.h>
int fn(int n) {
    if(n==1) return 1;
    else if(n%2==0) return fn(n/2);
    else if(n%3==0) return fn(n/3);
    else if(n%5==0) return fn(n/5);
    return 0;
 }
int main() {
    int n;
    scanf("%d",&n);
    if(n<0) printf("false");
    else if(fn(n)) printf("true");
    else printf("false");
}

// Write a program to take value V and  we want to make change for V Rs, and we have infinite supply of each of the denominations in Indian currency, i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

// Input Format:

// Take an integer from stdin.

// Output Format:

// print the integer which is change of the  number.

// Example Input :

// 64

// Output:

// 4

// Explanaton:

// We need a 50 Rs note and a 10 Rs note and two 2 rupee coins.

// Example Input:

// 49

// Output:

// 5

// Explanation:

// We need a  two 20 Rs notes and a 5 Rs coins and two 2 rupee coins.

#include<stdio.h>
int main() {
    int a[]={1000,500,200,100,50,20,10,5,2,1},n,i=0,ans=0;
    scanf("%d",&n);
    while(n>0) {
        if(n<a[i]) i++;
        else {
            ans+=(n/a[i]);
            n=n%a[i];
        }
    }
    printf("%d",ans);
}

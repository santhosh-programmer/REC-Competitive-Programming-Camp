// Let’s print a chessboard!

// Write a program that takes input:

// The first line contains T, the number of test cases

// Each test case contains an integer N and also the starting character of the chessboard

// Output Format

// Print the chessboard as per the given examples

// Sample Input / Output

// Input:

// 2

// 2 W

// 3 B

// Output:

// WB

// BW

// BWB

// WBW

// BWB



// For example:

// Input	Result
// 2
// 2 W
// 3 B
// WB
// BW
// BWB
// WBW
// BWB

#include<stdio.h>
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int n;
        scanf("%d\n",&n);
        char c,c1,c2;
        scanf("%c",&c);
        if(c=='W') {
            c1='W';  c2='B';
        }
        else {
            c1='B'; c2='W';
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ((i+j)%2==0) ? printf("%c",c1) : printf("%c",c2);
            } 
            printf("\n");
        }
    }
}

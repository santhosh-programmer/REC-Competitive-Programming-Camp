// Given an integer n as input, print an inverted full pyramid of n rows.

// Input Format:

// Take input an integer from stdin.

// Output Format:

// Print the pattern

// Example Input:

// 10

// Output:

// * * * * * * * * * *

//  * * * * * * * * *

//   * * * * * * * *

//    * * * * * * *

//     * * * * * *

//      * * * * *

//       * * * *

//        * * *

//         * *

//          *


#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        printf("%*s",i,"");
        for(int j=0;j<n-i;j++) printf("* ");
        printf("\n");
    }
}

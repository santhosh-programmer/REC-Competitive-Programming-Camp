// Pascal's triangle giving binomial coefficients is well known.

// In this triangle, elements in each row can be obtained by adding two adjacent elements in the previous row. The pyramid of numbers we construct in this problem is similar to the Pascal triangle.

// We start with six numbers at the base of the pyramid, and construct the pyramid one layer at a time by adding the two adjacent numbers in the previous layer.

// For Example, starting with the numbers 1 2 3 4 5 6 in the base, we get the following pyramid. The apex of the pyramid is filled with the product of the numbers in the row below instead of the sum.

//         48  64

//       20  28  36

//     8   12  16  20

//   3   5   7    9    11

// 1   2   3    4    5     6

// In the above pyramid, the apex is filled with the number 48 x 64 =3072. The aim is to get the largest number possible at the apex of the pyramid.

// The input will be a set of N positive integers. Six need to be chosen from these and arranged at the base to get the largest possible number at the top.

// Input Format:

// · The first line of the input is N, the total number of integers that will be given.

// · The second line is a set of N (not necessarily distinct) comma separated positive integers from which the six numbers at the base need to be selected.

// Output Format:

// The output is one line with an integer representing the maximum value of the apex of the pyramid when six integers are selected and arranged suitably at the base.

// Constraints:

// · N < 13

// · Integers provided for selection ≤ 100 

// Example 1

// Input

// 8

// 10 4 74 61 8 37 2 35

// Output

// 746415

// Explanation

// There are 8 numbers given, from which the 6 numbers in the base are to be selected and arranged so as to maximize the apex number. One way of doing this is in the figure below.

//         855 873

//       378  477 396

//     145 233 244  152

//   47  98  135  109  43

// 10  37  61  74   35    8


#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n], arr[6];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(a[j]<a[j+1]) {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    arr[2]=a[0]; arr[3]=a[1];
    if( abs((arr[2] + a[2]) - (arr[3] + a[3])) < abs((arr[2] + a[3]) - (arr[3] + a[2])) ) {
        arr[1]=a[2];
        arr[4]=a[3];
    }
    else {
        arr[1]=a[3];
        arr[4]=a[2];
    }
    if( abs((arr[2] + arr[1] + a[4]) - (arr[3] + arr[4] + a[5])) < abs((arr[2] + arr[1] + a[5]) - (arr[3] + arr[4] + a[4])) ) {
        arr[0]=a[4];
        arr[5]=a[5];
    }
    else {
        arr[0]=a[5];
        arr[5]=a[4];
    }
    for(int i=0;i<4;i++) {
        int t[5-i],l=0,r=1;
        for(int j=0;j<5-i;j++) {
            t[j]=arr[l]+arr[r];
            l++;r++;
        }
        for(int j=0;j<5-i;j++) arr[j]=t[j];
    }
    printf("%d",arr[0]*arr[1]);
}

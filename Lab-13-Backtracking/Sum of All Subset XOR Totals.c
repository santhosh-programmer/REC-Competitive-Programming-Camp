// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.

// Given an array nums, return the sum of all XOR totals for every subset of nums. 

// Note: Subsets with the same elements should be counted multiple times.

// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

// Example 1:

// Input: 

// 2

// 1 3

// Output: 

// 6

// Explanation: The 4 subsets of [1,3] are:

// - The empty subset has an XOR total of 0.

// - [1] has an XOR total of 1.

// - [3] has an XOR total of 3.

// - [1,3] has an XOR total of 1 XOR 3 = 2.

// 0 + 1 + 3 + 2 = 6

// Example 2:

// Input: 

// 3

// 5 1 6

// Output: 

// 28

// Explanation: The 8 subsets of [5,1,6] are:

// - The empty subset has an XOR total of 0.

// - [5] has an XOR total of 5.

// - [1] has an XOR total of 1.

// - [6] has an XOR total of 6.

// - [5,1] has an XOR total of 5 XOR 1 = 4.

// - [5,6] has an XOR total of 5 XOR 6 = 3.

// - [1,6] has an XOR total of 1 XOR 6 = 7.

// - [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.

// 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28

// Example 3:

// Input: 

// 6

// 3 4 5 6 7 8

// Output: 

// 480

// Explanation: The sum of all XOR totals for every subset is 480.

// Constraints:

// 1 <= nums.length <= 12

// 1 <= nums[i] <= 20

#include<stdio.h>
int ans=0;
void find(int n,int a[],int index,int temp) {
    if(index<n) {
        temp^=a[index];
        find(n,a,index+1,temp);
        temp^=a[index];
        find(n,a,index+1,temp);
    }
    else ans+=temp;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    find(n,a,0,0);
    printf("%d",ans);
}

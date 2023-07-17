// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: 

// 4

// 1 2 3 1

// Output: 

// 4

// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).

// Total amount you can rob = 1 + 3 = 4.

// Example 2:

// Input:

// 5

// 2 7 9 3 1

// Output: 

// 12

// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).

// Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:

// 1 <= nums.length <= 100

// 0 <= nums[i] <= 400

#include<stdio.h>
int max(int a,int b) {
    return (a>b) ? a : b;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n],dp[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    if(n==1) printf("%d",a[0]);
    else if(n==2) printf("%d",a[1]);
    else if(n==3) printf("%d",max(a[1], a[2] + a[0]));
    else {
        dp[0]=a[0],dp[1]=a[1],dp[2]=max(a[1], a[2] + a[0]);
        for(int i=3;i<n;i++) dp[i]=a[i]+max(dp[i-2],dp[i-3]);
    }
    printf("%d",max(dp[n-1],dp[n-2]));
}

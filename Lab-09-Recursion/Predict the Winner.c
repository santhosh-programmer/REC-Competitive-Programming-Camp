// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

// Example 1:

// Input:

// nums = [1,5,2]

// Output:

// false

// Explanation:

// Initially, player 1 can choose between 1 and 2.

// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).

// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.

// Hence, player 1 will never be the winner and you need to return false.

// Example 2:

// Input:

// nums = [1,5,233,7]

// Output:

// true

// Explanation:

// Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.

// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

// Constraints:

// 1 <= nums.length <= 20

// 0 <= nums[i] <= 107

// For example:

// Input	Result
// 3
// 1 5 2
// false
// 4
// 1 5 233 7
// true

#include<stdio.h>
int f=0;
int max(int a,int b) {
    return (a>b) ? 1 : 0;
}
void find(int n, int a[],int p1Score, int p2Score, int curr,int l,int r) {
    if(n==0) {
        if(p1Score>=p2Score) f=1;
    }
    else{
        if(curr%2==1) {
            if(l+1==r) {
                if(max(a[l],a[r])) {
                    p1Score+=a[l];
                    l++;
                }
                else {
                    p1Score+=a[r];
                    r--;
                }
                find(n-1,a,p1Score,p2Score,curr+1,l,r);
            }
            else {
                find(n-1,a,p1Score+a[l],p2Score,curr+1,l+1,r);
                find(n-1,a,p1Score+a[r],p2Score,curr+1,l,r-1);
            }
        }
        else {
            if(l+1==r) {
                if(max(a[l],a[r])) {
                    p2Score+=a[l];
                    l++;
                }
                else {
                    p2Score+=a[r];
                    r--;
                }
                find(n-1,a,p1Score,p2Score,curr+1,l,r);
            }
            else {
                find(n-1,a,p1Score,p2Score+a[l],curr+1,l+1,r);
                find(n-1,a,p1Score,p2Score+a[r],curr+1,l,r-1);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    find(n,a,0,0,1,0,n-1);
    if(f==0) printf("false");
    else printf("true");
}

// Sometimes instructions are straightforward, and other times they are not. For example, if Shaktimaan had just drafted you as a normal intern, you wouldn't be in this mess.

// What's the mess? Well, you were able to cure Phoenix by getting the antidotes. The problem was that the antidotes also released so much energy that you got caught in a wormhole. And just your luck - you landed in a maze at the side of Wonder Woman.

// Wonder Woman is racing through the 2D maze. She starts at a position A and wants to go to position B. She can move only 1 block at a time - either vertically or horizontally. Also, her vertical moves and horizontal move can only be in 1 direction each.

// Let' say she starts at A (1,1) and needs to reach B (3,3). Vertically she is allowed to move only to the South S and horizontally to the E. No matter what moves she makes, it's impossible to reach B, because she can never go North

// However, if she is allowed to move NE, which means vertically North and horizontally East, she has many ways of reaching B:



// Totally she has 6 ways. of reaching her destination.

// Given the coordinates of her starting and and desired ending positions, you need tell either impossible if it's not possible to reach, or print the total ways possible to reach B from A

// Input format

// · The first line of input contains T, the number of test cases

// · The first line contains the x and y coordinates of A

// · The second line contains the x and y coordinates of B

// · This is followed by the direction string. The first character contains S or N, the second one E or W

// 0 <= x,y <= 15

// Output format

// For each test case, print impossible or the total way possible to reach B from A

// Example Input

// 4

// 1 1

// 3 3

// NE

// 10 10

// 1 1

// NE

// 3 7

// 5 3

// SW

// 1 4

// 0 6

// NW

// Example Output

// Total Ways: 6

// impossible

// impossible

// Total Ways: 3

// Explanation

// 1. The first case is explained above

// 2. The second case requires us to move S and W, but allowed is N and E. Hence it's impossible

// 3. The third case requires us to move E for 3 -> 5, and S for 7 -> 3. We need SE, but we have SW. Hence it's impossible

// 4. The last case is possible. The possible paths are: 1,4 -> 1,5 -> 1,6 -> 0,6, 1,4 -> 0,4 -> 0,5 -> 0, 6, 1,4 -> 1,5 -> 0,5 -> 0,6


// For example:

// Input	Result
// 4
// 1 1
// 3 3
// NE
// 10 10
// 1 1
// NE
// 3 7
// 5 3
// SW
// 1 4
// 0 6
// NW
// Total Ways: 6
// impossible
// impossible
// Total Ways: 3


#include<stdio.h>
int total=0;
void find(int l,int r,int b[2],char x,char y) {
    if(l==b[0] && r==b[1]) total++;
    else {
        if(x=='N' && r<b[1]) find(l,r+1,b,x,y);
        if(x=='S' && r>b[1]) find(l,r-1,b,x,y);
        if(y=='E' && l<b[0]) find(l+1,r,b,x,y);
        if(y=='W' && l>b[0]) find(l-1,r,b,x,y);
    }
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int a[2],b[2]; char d[2];
        scanf("%d%d",&a[0],&a[1]);
        scanf("%d%d",&b[0],&b[1]);
        scanf("\n%s",d);
        if(b[0]>a[0] && b[1]>a[1] && (d[0]!='N' || d[1]!='E')) printf("impossible\n");
        else if(b[0]<a[0] && b[1]>a[1] && (d[0]!='N' || d[1]!='W')) printf("impossible\n");
        else if(b[0]<a[0] && b[1]<a[1] && (d[0]!='S' || d[1]!='W')) printf("impossible\n");
        else if(b[0]>a[0] && b[1]<a[1] && (d[0]!='S' || d[1]!='E')) printf("impossible\n");
        else if(a[0]==b[0] && b[1]>a[1] && d[0]!='N') printf("impossible\n");
        else if(a[0]==b[0] && b[1]<a[1] && d[0]!='S') printf("impossible\n");
        else if(a[1]==b[1] && b[0]>a[0] && d[1]!='E') printf("impossible\n");
        else if(a[1]==b[1] && b[0]<a[0] && d[1]!='W') printf("impossible\n");
        else {
            find(a[0],a[1],b,d[0],d[1]);
            printf("Total Ways: %d\n",total);
        }
        total=0;
    }
}

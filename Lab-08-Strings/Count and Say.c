// The count-and-say sequence is the sequence of integers beginning as follows:

// 1, 11, 21, 1211, 111221, . . .

// 1 is read off as one 1 or 11.

// 11 is read off as two 1s or 21.

// 21 is read off as one 2, then one 1 or 1211.

// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

// Example:

// if n = 2,

// the sequence is 11.


// For example:

// Input	Result
// 2
// 11
// 3
// 21

#include<stdio.h>
#include<string.h>
int main(){
    char ans[10000];
    int n;
    scanf("%d",&n);
    ans[0]='1';
    for(int i=1;i<n;i++) {
        char temp[10000];
        int index=0,count=1;
        for(int j=0;j<strlen(ans);j++) {
            if(ans[j]==ans[j+1]) count++;
            else {
                temp[index]=count+'0';
                temp[index+1]=ans[j];
                count=1;
                index+=2;
            }
        }
        strcpy(ans,temp);
    }
    for(int i=0;i<strlen(ans);i++) printf("%c",ans[i]);
}

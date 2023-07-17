// Input

// 4

// 1 0 0 0

// 1 1 1 1

// 0 1 0 0 

// 1 1 1 1

// Output

// 1 0 0 0 

// 1 1 0 0 

// 0 1 0 0 

// 0 1 1 1 

#include<stdio.h>
int find(int n,int a[n][n],int x,int y,int ans[n][n]) {
    for(int i=y;i<n;i++) {
        if(a[x][i]) {
            if(x+1==n && i+1==n) {
                for(int k=y;k<n;k++) ans[x][k]=1;
                return 1;
            }
            if(x+1!=n && a[x+1][i] && find(n,a,x+1,i,ans)) {
                for(int k=y;k<=i;k++) ans[x][k]=1;
                return 1;
            }
        }
        else return 0;   
    }
    return 0;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n][n],ans[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
            ans[i][j]=0;
        }
    }
    find(n,a,0,0,ans);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d ",ans[i][j]);
        printf("\n");
    }
}

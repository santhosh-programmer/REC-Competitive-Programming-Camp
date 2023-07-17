// Some prime numbers can be expressed as Sum of other consecutive prime numbers.

// For example

// 5 = 2 + 3

// 17 = 2 + 3 + 5 + 7

// 41 = 2 + 3 + 5 + 7 + 11 + 13

// Your task is to find out how many prime numbers which satisfy this property are present in the range 3 to N subject to a constraint that summation should always start with number 2.

// Write code to find out number of prime numbers that satisfy the above mentioned property in a given range.

// Input Format:

// First line of input contains k - the number of inputs

// The next k lines contains a number N.

// Output Format:

// Print the total number of all such prime numbers which are less than or equal to N.

// Example:

// Input:

// k = 2

// N = 20

// N = 15

// Output:

// 2 (there are 2 such numbers: 5 and 17)

// 1


// For example:

// Input	Result
// 2
// 20
// 15
// 2
// 1


#include<stdio.h>
#include<math.h>

int isPrime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%2==0) return 0;
    }
    return 1;
}

void findPrime(int n,int prime[]) {
    for(int i=2;i<n;i++) {
        if(prime[i]) {
            if(isPrime(i)) {
                for(int j=i*2;j<n;j+=i) {
                    prime[j]=0;
                }
            }
        } 
    }
}

int main() {
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++) {
        int n;
        scanf("%d",&n);
        int prime[n+1];
        for(int j=0;j<n;j++) prime[j]=1;
        findPrime(n,prime);
        int ans=0;
        for(int j=4;j<n;j++) {
            if(prime[j]) {
                int sum=0;
                for(int k=2;k<n;k++) {
                    if(prime[k]) {
                        sum+=k;
                        if(sum==j) {
                            ans++;
                            break;
                        }
                        else if(sum>j) break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}

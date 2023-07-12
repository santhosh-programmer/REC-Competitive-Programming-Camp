// Given a string S of odd length L, the program must print it twice as diagonals with the middle letter being the point of intersection. 

// Input Format:

// The first line contains the value of S.

// Boundary Conditions:

// The length of the String S is from 3 to 20.

// 1 <= L (Length of S) <= 20

// Output Format:

// L lines printing the desired pattern.

// Example Input/Output 1:

// Input:

// PROGRAM

// Output:

// P     M  

//  R   A  

//   O R   

//    G  

//   O R  

//  R   A

// P     M

// Example Input/Output 2:

// Input:

// CABLE

// Output:

// C   E

//  A L

//   B

//  A L

// C   E


// For example:

// Input	Result
// PROGRAM
// P     M  
//  R   A   
//   O R    
//    G   
//   O R  
//  R   A 
// P     M
// CABLE
// C   E
//  A L
//   B
//  A L
// C   E


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    char s[25];
    scanf("%s",s);
    int len=strlen(s),middleSpace=-(len-2);
    int l=0,r=len-1;
    for(int i=0;i<len;i++,l++,r--) {
        printf("%*s",(i>len/2) ? len-i-1 : i,"");
        printf("%c",s[ (i>len/2) ? r : l ]);
        printf("%*s",abs(middleSpace),"");
        if(i!=len/2) middleSpace+=2;
        if(l!=r)
        printf("%c",s[ (i>len/2) ? l:r ]);
        printf("\n");
    }
}

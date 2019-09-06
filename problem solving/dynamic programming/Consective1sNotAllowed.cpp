//problem URL: https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

ui count_using_recursion (int n){

    static ui index= 1;

    //saves the number of binary strings of length index-->n where, bitStreamEndBy0 carrys the number
    //of binary strings of length index to n that ends with 0 and bitStreamEndBy1 carrys the number of
    //.... that ends with 1. Check the URL to know how that information benefit us to find the solution
    static ui bitStreamEndBy0, bitStreamEndBy1;

    //if in the first iteration(index==1), initiate our static variables
    if(index==1) 
        { bitStreamEndBy0= bitStreamEndBy1= 1;}

    //if reached the end (index==n), reset index for if this function will be used again on 
    //a different testcase and return the answer
    if(index==n)
        {index=1; return bitStreamEndBy0+ bitStreamEndBy1;}
    else index+=1;

    //update state variables and recall the function
    ui temp= bitStreamEndBy0;
    bitStreamEndBy0= (bitStreamEndBy0+ bitStreamEndBy1);
    bitStreamEndBy1= temp;
    return count_using_recursion(n);
}

ui count_using_dp(int n){
    ui a[n+1], b[n+1];
    a[1]= b[1]= 1;
    for(int i=2; i<=n; i++){
        a[i]= a[i-1]+ b[i-1];
        b[i]= a[i-1];
    }
    return a[n]+ b[n];
}

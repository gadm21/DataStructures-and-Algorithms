// problem URL:: https://practice.geeksforgeeks.org/problems/maximum-profit/0

#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int

const int N= 31;
int arr[N];
int n, K;

int maximum_profit_recursion(int buy=-1,int index=0, int k=0){
    if(index== n || k==K) return 0;

    if(buy>-1) 
        return max( (arr[index]- buy)+ maximum_profit_recursion(-1, index+1, k+1), maximum_profit_recursion(buy, index+1, k));


    return max( maximum_profit_recursion(arr[index], index+1, k), maximum_profit_recursion(-1, index+1, k));
}


int main(){
    int t; cin>>t;
    while(t--){

        cin>>K>>n;
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<< maximum_profit_recursion()<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

const int N= 100;
int dp[N][N];
string s1, s2;

void initial_fill(int n1, int n2){for(int i=0; i<n1; i++) for(int j=0; j<n2; j++) dp[i][j]= -1;}

void print_dp(int n1,int n2){
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int fill_dp(int p1, int p2){
    if(p1<0 || p2<0) return 0;

    if(dp[p1][p2]==-1){
        int with_current_char= ((s1[p1]==s2[p2])? 1: 0)+ fill_dp(p1-1, p2-1);
        int without_current_char= max(fill_dp(p1-1, p2), fill_dp(p1, p2-1));
        dp[p1][p2]= max(with_current_char, without_current_char);
    }
    return dp[p1][p2];
}



int main(){
    cin>>s1>>s2;
    initial_fill(s1.length(), s2.length());

    cout<<fill_dp(s1.length()-1, s2.length()-1)<<endl;
    
    //print_dp(s1.length(), s2.length());
}
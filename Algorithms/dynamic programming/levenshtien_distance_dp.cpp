

#include <bits/stdc++.h>
using namespace std;


int levenshtien_distance_dp(string s1, string s2){
    int l1 = s1.length()+1, l2 = s2.length()+1;

    vector< vector<int> > dp(l1, vector<int>(l2));
    for(int i=0; i<l1; i++) dp[i][0] = i;
    for(int i=0; i<l2; i++) dp[0][i] = i;

    for(int i=1; i<l1; i++)
        for(int j=1; j<l2; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(1 + dp[i][j-1],
                                min(1 + dp[i-1][j],
                                2 + dp[i-1][j-1]));
        }
    
    return dp[s1.length()][s2.length()];
}


int main(){
    string s1= "hello";
    string s2= "";
    int distance = levenshtien_distance_dp(s1, s2);
    cout<<distance<<endl;
}
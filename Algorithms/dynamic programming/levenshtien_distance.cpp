/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 17 - problem 2
 */


#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector< vector<int> > dp){
    for (auto row : dp){
        for(auto element : row) cout<<element<<" ";
        cout<<endl;
    }
}

int levenshtien_distance_dp(string a, int a_index, string b, int b_index, vector<vector< int> > & dp){
    if (a_index < 0) return b_index +1;
    if (b_index < 0) return a_index +1;

    if(dp[a_index][b_index] == -1){
        if(a[a_index] == b[b_index]) dp[a_index][b_index]= levenshtien_distance_dp(a, a_index-1, b, b_index-1, dp);
        else{
            int substitute_last= levenshtien_distance_dp(a, a_index-1, b, b_index-1, dp);
            int add_last= levenshtien_distance_dp(a, a_index, b, b_index-1, dp);
            int delete_last= levenshtien_distance_dp(a, a_index-1, b, b_index-1, dp);
            dp[a_index][b_index]= 1 + min(substitute_last, min(add_last, delete_last));
        }
    }
    return dp[a_index][b_index];
}

int levenshtien_distance(string a, string b){
    vector< vector< int> > dp(a.length(), vector<int> (b.length(), -1));

    return levenshtien_distance_dp(a, a.length()-1, b, b.length()-1, dp);

    
}

int main(){
    string a= "siste";
    string b= "hello";
    
    cout<<levenshtien_distance(a, b);
}
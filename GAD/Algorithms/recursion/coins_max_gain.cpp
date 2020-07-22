#include <bits/stdc++.h>
using namespace std;

int recursive_R(vector<int> coins, int a, int b, vector< vector<int> > R){
    if(a> b) return 0;

    if(R[a][b]==0){
        int choosing_A= coins[a]+ min(recursive_R(coins, a+2, b, R), recursive_R(coins, a+1, b-1, R));
        int choosing_B= coins[b]+ min(recursive_R(coins, a, b-2, R), recursive_R(coins, a+1, b-1, R));
        R[a][b]= max(choosing_A, choosing_B);
    }
    return R[a][b];
}

int compute_max_gain(vector<int> coins){
    vector< vector< int> > R(coins.size()-1, vector<int> (coins.size()-1));
    return recursive_R(coins, 0, coins.size()-1, R);
}

int main(){
    vector<int> coins= {25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10};
    cout<<compute_max_gain(coins);
}
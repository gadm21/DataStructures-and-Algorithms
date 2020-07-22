#include <bits/stdc++.h>
using namespace std;

int compute_moves(int n, int k, vector<int> moves){
    if(n<=1) return 1;
     if(moves[n]==0) for(int j=1; j<=n && j<=k; j++) moves[n]+= compute_moves(n-j, k, moves);
    return moves[n];
}

int count_moves_for_n_stairs(int n, int k){
    vector<int> moves(n+1);
    int ans= compute_moves(n, k, moves);
    return ans;
}

int main(){
    cout<<count_moves_for_n_stairs(4, 2);
}
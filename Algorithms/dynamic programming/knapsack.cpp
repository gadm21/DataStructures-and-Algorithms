#include <bits/stdc++.h>
using namespace std;

const int N= 10;
int dp[N][N];

void initial_fill(){for(int i=0; i< N; i++) for (int j=0; j<N; j++) dp[i][j]=-1;}

void print_items(vector<pair<int, int> > &items){
    for(int i=0; i< items.size(); i++)
        cout<<items[i].first<<"  "<<items[i].second<<endl;
    cout<<endl;
}

void print_dp(int n, int k){
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}







int fill_dp(vector<pair<int, int> > items, int k, int i){
    if(i<0 || k==0) return 0;

    if(dp[i][k]==-1){
        int without_current_item= fill_dp(items, k, i-1);
        int with_current_item= (items[i].first> k)? 0: items[i].second+ fill_dp(items, k- items[i].first, i-1);
        dp[i][k]= max(without_current_item, with_current_item);
    }
    return dp[i][k];
}

int main(){
    int n, capacity; cin>>n>>capacity;
    vector<pair<int, int> > items;
    initial_fill();
    for(int i=0; i<n; i++){
        int weight, value; cin>>weight>>value;
        items.push_back(make_pair(weight, value));
    }

    cout<<fill_dp(items, capacity, items.size()-1)<<endl;

    //print_dp(n, capacity);
}
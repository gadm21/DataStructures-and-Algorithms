#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    vector<int> profits(n);
    vector<int> clicks(n);
    for(int i=0; i<n; i++) cin>>profits[i];
    for(int i=0; i<n; i++) cin>>clicks[i];

    sort(profits.begin(), profits.end());
    sort(clicks.begin(), clicks.end());

    long long result = 0;
    for(int i=0; i<n; i++) result += ((long long) profits[i]*clicks[i]);
    cout<<result<<endl;
}
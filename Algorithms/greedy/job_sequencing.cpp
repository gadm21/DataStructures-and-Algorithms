//problem URL:: https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0

#include <bits/stdc++.h>
using namespace std;

void sum(int &duration, int &profit, vector<pair<int, bool> > &v){
    int counter=0;
    int total=0;
    for(int i=0; i<v.size(); i++) 
        if(v[i].second){
            counter++;
            total+= v[i].first;
        }
    duration= counter;
    profit= total;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int, bool> > v(n+1, make_pair(-1, false));
        while(n--){
            int id, deadline, profit; cin>>id>> deadline>>profit;
            for(int d=deadline; d>0; d--) 
                if(!v[d].second || v[d].first< profit){
                    v[d].second= true;

                    v[d].first= profit;
                    break;
                }
        }
        int duration, profit;
        sum(duration, profit, v);
        cout<<duration<<" "<<profit<<endl;
    }
}
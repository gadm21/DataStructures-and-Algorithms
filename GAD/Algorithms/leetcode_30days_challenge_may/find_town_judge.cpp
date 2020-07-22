

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int findJudge(int N, vector<vector<int> > & trust){
        if(N==1 && trust.size()==1) return 1;
        map<int, int> trusting;
        map<int, int> trusted;
        for(auto t : trust){
            trusted[t[1]] ++;
            trusting[t[0]] ++;
        }
        for(auto t : trusted){
            if(t.second!=N-1) continue ;
            if(trusting[t.first]==0) return t.first;
        }
        return -1;
        
    }
};


vector<vector<int> > get_trust(){
    //vector<int> t1 = {1,2};
    //vector<int> t2 = {2,3};
    vector<int> t1 = {1,3};
    vector<int> t2 = {1,4};
    vector<int> t3 = {2,3};
    vector<int> t4 = {2,4};
    vector<int> t5 = {4,3};
    vector<vector<int> > trust = {t1,t2,t3,t4,t5};
    return trust;
}

int main(){
    Solution sol ; 
    auto trust = get_trust() ;
    cout<<sol.findJudge(4,trust)<<endl ;
    
}
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool is_jewel(string J, char s){
        for (int i=0; i<J.length(); i++) if(J[i]==s) return true;
        return false;
    }
    int numJewelsInStones(string J, string S) {
        int jewels_num = 0 ;
        for(int i=0; i<S.length(); i++) if (is_jewel(J,S[i])) jewels_num++;
        return jewels_num;
    }
};


int main(){
    vector<string> j = {"aA", "Z"};
    vector<string> s = {"aAAbbbb", "zz"};
    Solution sol;
    for (int i=0; i<j.size(); i++) cout<<sol.numJewelsInStones(j[i],s[i])<<endl;
}
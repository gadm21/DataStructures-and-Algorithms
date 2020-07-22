#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int firstUniqChar(string s){
        map<char,int> m;
        for(auto c : s) m[c]++;
        for(int i=0; i<s.length(); i++) if(m[s[i]] == 1) return i;
        return -1 ;
    }

};

int main(){
    Solution sol ;
    cout<<sol.firstUniqChar("leetcode")<<endl;
    cout<<sol.firstUniqChar("loveleetcode")<<endl;
}
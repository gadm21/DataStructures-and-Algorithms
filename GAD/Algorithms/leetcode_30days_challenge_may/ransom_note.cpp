#include <bits/stdc++.h>
using namespace std;


vector<char> to_vec(string s){
    vector<char> vec;
    for(int i=0; i<s.length(); i++) vec.push_back(s[i]);
    return vec;
}

class Solution{
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<char> mag = to_vec(magazine);

        for(int i=0; i<ransomNote.length(); i++){
            auto iter = find(mag.begin(), mag.end(), ransomNote[i]);
            if(iter == mag.end()) return false ;
            mag.erase(iter);
        }
        return true;
    }
};


int main(){
    Solution sol ;
    vector<string> ransomNotes = {"a","aa","aa"};
    vector<string> magazines = {"b","ab","aab"};

    for (int i=0; i<ransomNotes.size(); i++) cout<<sol.canConstruct(ransomNotes[i], magazines[i])<<endl;
}
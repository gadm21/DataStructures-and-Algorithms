#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string clean(string raw){
        string cleaned = "";
        for(auto c : raw){
            if (c == '#') { if (!cleaned.empty()) cleaned.pop_back();} 
            else cleaned += c;
        }      
        return cleaned;
    }

    bool backspaceCompare(string S, string T) {
        string true_s = clean(S) ;
        string true_t = clean(T) ; 
        return true_s == true_t ; 
    }
};

int main(){
    Solution sol;
    cout<<sol.backspaceCompare("a#c", "b")<<endl;
    cout<<sol.backspaceCompare("a##c", "#a#c")<<endl; 
    cout<<sol.backspaceCompare("ab##", "c#d#")<<endl; 
}
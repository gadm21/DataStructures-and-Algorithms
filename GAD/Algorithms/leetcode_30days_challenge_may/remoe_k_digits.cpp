#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long 


/*  time expensive solution

class Solution{
public:
    ul minn = LONG_MAX;
    void solve(string num, int k){
        
        if (k==0){
            if (num.empty()) minn=0;
            else if (stoul(num) < minn) minn = stoul(num);
            return;
        }
        for (int i=0; i<num.length(); i++){
            string newnum = num.substr(0,i) + num.substr(i+1);
            solve(newnum,k-1);
        }
    }
    string removeKdigits(string num, int k){
        if (num.length()==k) return "0";
        solve(num, k);
        return to_string(minn);
    }
};

*/ 

class Solution{
public:
    string removeKdigits(string num, int k){
        stack<char> st;
        string ret = "";

        for(auto c : num){
            while(k && !st.empty() && st.top() > c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        while(k--) st.pop();
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        
        int i=0;
        for(; i<ret.length() && ret[i]=='0'; i++);
        string answer = ret.substr(i);
        return answer.length() ? answer : "0";
        
    }
};


int main(){
    Solution sol;
    string h = "hello";
    reverse(h.begin(), h.end());
    cout<<h<<endl;
    //cout<<sol.removeKdigits(get_string(),1000)<<endl;
}


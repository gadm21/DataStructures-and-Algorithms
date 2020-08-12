#include <bits/stdc++.h>
using namespace std;


bool isin(vector<char> & chars, char i){
    for(auto c : chars) if(c == i) return true;
    return false;
}

void print(vector<string> & v){
    for(auto word : v) cout<<word<<endl;
    cout<<endl;
}



vector<string > get_order_possibilities(vector<string> & dict){
    vector<string> alphabets;
    vector<char> chars;

    int max_len = 0;
    for(auto word : dict) if (max_len < word.length()) max_len = word.length();
    
    for(int i=0; i<max_len; i++){
        string level_alphabets;
        for(auto word : dict){
            if (word.length() <= i || isin(chars, word[i])) continue ; 
            chars.push_back(word[i]);
            level_alphabets += word[i];
        }
        if (level_alphabets.size()) alphabets.push_back(level_alphabets);
    } 
    return alphabets;
}

string get_any_order_from_order_possibilities(vector<string> & alphabets){
    string order = "";

    bool done = false;
    while(!done){
        done = true;
        for(int i=0; i<alphabets.size(); i++){
            if (alphabets[i].empty()) continue;
            if (alphabets[i][0] != ' ') order += alphabets[i][0];
            alphabets[i] = alphabets[i].substr(1);
            done = false;
        }
    }
    return order;
}


int main(){
    int T = 1;
    int N = 5;
    int K = 4;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};

    while(T--){
        
        vector<string > alphabet = get_order_possibilities(dict); 
        string order = get_any_order_from_order_possibilities(alphabet) ;

        cout<<order<<endl;
    }
}
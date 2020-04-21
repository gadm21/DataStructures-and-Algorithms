

#include <bits/stdc++.h>
using namespace std;



bool test1(vector<string> v){
    for(int i=0; i<v.size(); i++) {
        if (v[i][0] != '*') return false;
        string s = v[i];
        for(int c=1; c< s.length(); c++) if(s[c] == '*') return false;
    }
    return true;
}

bool test2(vector<string> v){
    
    for(int i=0; i<v.size(); i++){
        int temp_c =0;
        string s = v[i];
        for(int j=0; j<s.length(); j++) if (s[j]=='*') temp_c++;
        
        if (temp_c>1) return false;
    }
    return true;
}

int longest_length(vector<string> v){
    int res= 0;
    int index= -1;
    for(int i=0; i<v.size(); i++) {
        if (res < v[i].length()) {
            res = v[i].length();
            index = i;
        }
    }

    return index;
}

string solve_test1(vector<string> v){
    int longest_index = longest_length(v);
    int l = v[longest_index].length();
    string s_long = v[longest_index];

    for(int i=0; i<v.size(); i++){
        if(v[i].length() == 1) continue ;
        string s = v[i];
        int s_l = s.length();
        int start = l-s_l+1;
        
        if(s.substr(1) != s_long.substr(start)) return "*";
    }
    return s_long.substr(1);
}

bool live(vector<string> v, vector<int> inds){
    for(int i=0; i<inds.size(); i++){
        if(inds[i] < v[i].length() && v[i][inds[i]] != '*') return true;
    }
    return false;
}

bool live2(vector<string> v, vector<int> inds){
    for(int i=0; i<inds.size(); i++){
        if(inds[i] >= 0 && v[i][inds[i]] != '*') return true;
    }
    return false;
}

int where_is_astresk(string s){
    for(int i=0; i<s.length(); i++) if(s[i] == '*') return i;
    return -1;
}

int where_is_astresk_back(string s){
    for(int i=s.length()-1; i>=0; i--) if(s[i] == '*') return i;
    return -1;
}

int big_before(vector<string> v){
    int index = -1;
    int biggest = 0;
    for(int i=0; i<v.size(); i++){
        int ast_ind = where_is_astresk(v[i]);
        int len = ast_ind - 0 ;
        if (index == -1 || biggest < len){
            index = i;
            biggest = len;
        }
    }   
    return index ;
}

int big_after(vector<string> v){
    int index = -1;
    int biggest = 0;
    for(int i=0; i<v.size(); i++){
        int ast_ind = where_is_astresk_back(v[i]);
        int len = v[i].length() - ast_ind -1 ;
        if (index == -1 || biggest < len){
            index = i;
            biggest = len;
        }
    }
    return index;
}

string get_result(vector<string> v){
    
    int b_after = big_after(v);
    string b_after_str = v[b_after];
    b_after_str = b_after_str.substr(where_is_astresk(b_after_str)+1);

    int b_before = big_before(v);
    string b_before_str(v[b_before]);
    b_before_str = b_before_str.substr(0, where_is_astresk(b_before_str));
    
    return b_before_str + b_after_str;

    /*
    int index = longest_length(v);
    string s = v[index];
    int ast_index = where_is_astresk(s);
    string result = "";
    for(int i=0; i<s.length(); i++) if(s[i]!= '*') result+= s[i];
    return result;
    */
}

bool both_directions(vector<string> v){
    for(int i=0; i<v.size(); i++){
        string s = v[i];
        if (s[0] != '*' || s[s.length()-1] != '*') return false;
    }
    return true;
}

string clean_and_output(vector<string> v){
    string answer = "";
    for(int i=0; i<v.size(); i++){
        string s = v[i];
        for(int c=0; c<s.length(); c++) if(s[c] != '*') answer += s[c];
    }
    return answer;
}

string solve_test2(vector<string> v){

    //forward 
    vector<int> f_inds(v.size(), 0);
    
    while(live(v, f_inds)){
        
        bool set = false ;
        char c = '*';
        for(int i=0; i<v.size(); i++){
            string s= v[i];
            int current_i = f_inds[i];
            if (current_i >= s.length()) return "*";
            if(s[current_i] == '*') continue ;
            if(!set){
                set = true;
                c = s[current_i];
                
            }else{
                if(s[current_i] != c) return "*";

            }
            f_inds[i]++;
        }
    }

    vector<int> b_inds(v.size());
    for(int i=0; i<v.size(); i++) b_inds[i] = v[i].length()-1;

    while(live2(v, b_inds)){
        
        bool set = false ;
        char c = '*';
        for(int i=0; i<v.size(); i++){
            string s= v[i];
            int current_i = b_inds[i];
            if (current_i < 0) return "*";
            if(s[current_i] == '*') continue ;
            if(!set){
                set = true;
                c = s[current_i];
                
            }else{
                if(s[current_i] != c) return "*";

            }
            b_inds[i]--;
        }
    }

    if (both_directions(v)) return clean_and_output(v);
    else{
        string result = get_result(v);
        return result;        
    }

}


void print_v(vector<string> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<endl;
}
int main(){
    


    int T; cin>>T;
    for(int t=1; t<=T; t++){
        int N; cin>>N;
        vector<string> ns(N);
        for(int n=0; n<N; n++) cin>>ns[n];
        
        if (test1(ns)){
            
            string res = solve_test1(ns);
            cout<<"Case #"<<t<<": "<<res<<endl;
        }else {
            string res = solve_test2(ns);
            cout<<"Case #"<<t<<": "<<res<<endl;
        }
    }
}
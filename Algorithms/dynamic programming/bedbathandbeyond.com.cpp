
#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int


void print_dp(int n1,int n2, vector< vector<int> > dp){
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int fill_dp(string s1, string s2, vector< vector<int> > dp){
    
    for(int i=0; i<s1.length(); i++) if(s1[i]== s2[0]) dp[i][0]=1; else dp[i][0]= 0;
    for(int j=0; j<s2.length(); j++) if(s1[0]== s2[j]) dp[0][j]=1; else dp[0][j]= 0;
    
    int maxy=0;

    for(int i=1; i<s1.length(); i++){
        for(int j=1; j<s2.length(); j++){
            if(s1[i]==s2[j]){
                dp[i][j]=1+ dp[i-1][j-1]; 
                if (dp[i][j]> maxy) maxy= dp[i][j];   
            } 
            else dp[i][j]= 0;
        }
    }
    return maxy;

}

vector<string> find_keywords(const string s, const vector<string> &dic){
    ui length1= s.length();
    ui length2=0;

    for_each(dic.begin(), dic.end(),
    [&](string s) {if(length2< s.length()) length2=s.length();});
    
    /*
    ui** dp;
    dp=(ui**) calloc(length1, sizeof(ui*));
    for_each(dp, dp+length1, 
    [&](ui* i) {i= (ui*) calloc(length2, sizeof(ui));});  */

    vector< vector<int> > dp(length1, vector<int>(length2));

    vector<string> *ans= new vector<string>;

    for(int i=0; i<dic.size(); i++) 
        if(fill_dp(s, dic[i], dp)== dic[i].length()) ans->push_back(dic[i]);

    //delete dp;

    return *ans; 
}


int main(){
    string s; cin>>s;
    int dic_length; cin>>dic_length;

    vector<string> dic(dic_length);
    for(int i=0; i<dic_length; i++) cin>>dic[i];

    vector<string> ans= find_keywords(s, dic);

    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" "; 

    delete &ans;

    cout<<endl;
}
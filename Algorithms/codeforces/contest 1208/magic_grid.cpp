//contest URL:: https://codeforces.com/contest/1208/problems

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
}
void print(vector< vector<int> > &v){
    for(int i=0; i<v.size(); i++){
        print_v(v[i]);
        cout<<endl;
    }
}

void check(vector< vector<int> > &v){
    for(int i=0; i<v.size(); i++){
        vector<int> newv= v[i];
        int ans= v[i][0];
        for(int j=1; j<newv.size(); j++) ans^= newv[j];
        cout<<ans<<"  ";
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;

    vector< vector< int > > v(n, vector<int>(n));

    int counter=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j+=2){
            v[i][j]= counter;
            v[i][j+1]= ~counter;
            counter++;
        }
    }

    print(v);

}

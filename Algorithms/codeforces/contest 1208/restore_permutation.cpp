//contest URL:: https://codeforces.com/contest/1208/problems

#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

void print_backward(vector<int> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    vector<int> perm(n);
    vector<int> ans(n);


    for(int i=0; i<n; i++) cin>>perm[i];
    for(int i=0; i<n; i++) v[i]= i+1;

    for(int i=n-1; i>=0; i--){
        ui temp= 0;
        int j=0;
        for(; j<n; j++)
            if(perm[i]> temp) temp+= v[j];
            else break;

        ans[i]= v[j];
        v.erase(v.begin()+ j);

    }

    print_backward(ans);


}

#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n, l; cin>>n>>l;
        vector<string> v(n);
        while(n--) cin>>v[n];
        int index= -1;
        for(int i=1; i<l; i++){
            if(v[0][i-1]!= v[0][i]) continue;
            int found= true;

            for(int j=0; j<v.size(); j++){
                string s= v[j];

                for(int k= i-1, kk= i; k>=0 && kk<l; k--, kk++)
                    if(s[k]!= s[kk]) found= false;
                 if(!found) break;
            }
            if(found){index= i; break;}
        }
        if(index>-1) cout<<index+1<<endl;
        else cout<<index<<endl;
        v.clear();
    }
}


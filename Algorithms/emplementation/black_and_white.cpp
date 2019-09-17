//problem URL:: https://practice.geeksforgeeks.org/problems/black-and-white/0

#include <bits/stdc++.h>
using namespace std;

int t, n, m;

inline int within(int x, int y){
    if( x>=0 && y>=0 && x<n && y<m) return 1;
    return 0;
}

int all_possible_withins(int i, int j){
    return within(i- 1, j- 2)+
           within(i+ 1, j- 2)+
           within(i+ 2, j- 1)+
           within(i+ 2, j+ 1)+
           within(i- 2, j- 1)+
           within(i- 2, j+ 1)+
           within(i- 1, j+ 2)+
           within(i+ 1, j+ 2);
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        unsigned area= n*m;
        int j=0;
        unsigned result=0;
        for(int i=0; i<=n; i++){
            if(i==n) if(j<(m-1)) i=0, j+=1; else break;
            result+= area- all_possible_withins(i, j);
        }
        result-= area;
        cout<<result<<endl;
    }
}


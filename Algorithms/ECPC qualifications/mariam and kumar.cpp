#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int tiles, steps; cin>>tiles>>steps;
        vector<int> v(tiles);
        int index= -1, direction= 0, score=0;
        for(int i=0; i<tiles; i++){
            int x; cin>>x;
            if(x==0) x=1;
            else {
                if(x>1){ index= i; direction= x; x= 0;}
                else x= 0;
            }
            v[i]= x;
        }
        if(direction==2) direction= 1; else direction = -1;
        for(int i= index; steps!=0; i+= direction, steps--){
            score+= v[i];
            if(i==tiles-1 || i==0) direction*=-1;
        }
        cout<<score<<endl;


    }
}

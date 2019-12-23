//URL:: https://practice.geeksforgeeks.org/problems/eulerian-path-in-an-undirected-graph/0

#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        bool has_eular_path= true;
        int vertices; cin>>vertices;
        
        int odd_vertices_counter= 0;
        for(int i=0; i< vertices; i++){
            int vertices_counter=0;
            for(int j=0; j< vertices; j++){
                int x; cin>>x;

                if(x) vertices_counter++;
            }
            if(vertices_counter%2 ==1) odd_vertices_counter++;
        }
        if(odd_vertices_counter != 2) cout<<0<<endl; else cout<<1<<endl;
    }
}
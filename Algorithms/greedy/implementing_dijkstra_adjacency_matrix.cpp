//URL::https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

bool exist_not_visited(vector<bool> v){
    for (int i=0; i<v.size(); i++) if(!v[i]) return true;
    return false;
}

void print_v(vector<int> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

void dijkstra(vector< vector<int> > graph, int source, int n){
    vector<int> answer(n);
    for(int i=0; i<n; i++) answer[i]= graph[source][i];
    //answer[source]= 0;
/*
3
3 1 0 9 34 21 6 78 43
1
*/
    vector<bool> visited(n, false);
    //visited[source]= true;

    while(exist_not_visited(visited)){
        for (int i=0; i<n; i++){
            //if (i==source) continue;
            vector<int> current_vertex= graph[i];
            for (int j=0; j<n; j++){
                //if (j==source || j==i) continue;
                if (answer[i] + graph[i][j] < answer[j]){
                    answer[j]= answer[i]+ graph[i][j];
                    visited[j]= false;
                }
            }
            visited[i]= true;
        }
    }
    print_v(answer);
}



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector< vector<int> > matrix(n, vector<int> (n));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) 
                cin>>matrix[i][j];
        int source; cin>>source;
        dijkstra(matrix, source, n);
        
    }
}
//URL::https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

#define DISCARD 10

class Edge{
    public:
    int weight, U, V;
    Edge(int w, int u, int v){
        weight= w;
        U= u;
        V= v;
    }
    bool operator == (Edge const & e){
        return U == e.U && V == e.V;
    }
    void print(){
        cout<<"w:"<<weight<<" v:"<<V<<" u:"<<U<<endl;
    }
};

bool sort_edge_weights(Edge a, Edge b){
    return a.weight > b.weight;
}

int add_weights(vector <vector< Edge> > & trees){
    int weights= 0;
    vector<Edge> tree= trees[0];
    for(int i=0; i<tree.size(); i++)
        weights+= tree[i].weight;
    
    return weights;
}

void merge_trees(vector< vector<Edge> > & trees, int i, int j){
    vector<Edge> tree1= trees[i];
    vector<Edge> tree2= trees[j];
    trees.erase(trees.begin() + i);
    trees.erase(trees.begin() + j);
    tree1.insert(tree1.end(), tree2.begin(), tree2.end());
    trees.push_back(tree1);
}

int check_existance_in_tree( vector< Edge> & tree, Edge edge){
    int edge_u= edge.U, edge_v= edge.V;
    for (int i=0; i<tree.size(); i++){
        if (tree[i].U == edge_u || tree[i].V == edge_u) edge_u= -1;
        if (tree[i].U == edge_v || tree[i].V == edge_v) edge_v= -1;
    }


    return (edge_u == -1 && edge_v == -1 ) ? DISCARD : min(edge_u, edge_v);

}


int check_existance_in_trees(vector< vector<Edge> > & trees, Edge edge){
    int merge1=-1, merge2= -1;

    for (int i=0; i<trees.size(); i++){
        vector<Edge> tree= trees[i];
        int response= check_existance_in_tree( tree, edge);
        if (response== DISCARD) return DISCARD;
        if (response== -1){
            if (merge1 > -1) merge2= i;
            else merge1= i;
        }
    }

    if (merge1 > -1 && merge2 > -1){
            merge_trees(trees, merge1, merge2);
            int new_tree_index= trees.size()-1;
            return new_tree_index;
    }
    return max(merge1, merge2);
}

void print_trees(vector< vector< Edge> > & trees){
    cout<<".............print_trees...................."<<endl;
    for (int i=0; i<trees.size(); i++){
        vector<Edge> tree= trees[i];
        for (int j=0; j<tree.size(); j++){
            cout<<"W:"<<tree[j].weight<<" V:"<<tree[j].V<<" U:"<<tree[j].U<<endl;
        }
        cout<<endl;
    }
    cout<<"........................................."<<endl;
}

int solve(vector<Edge> edges, int n){
    sort(edges.begin(), edges.end(), sort_edge_weights);
    vector< vector<Edge> > trees;

    int tree_id= -1;
    while (! edges.empty()){
        
        Edge edge= edges[edges.size()-1];
        
        edges.pop_back();
        int response= check_existance_in_trees(trees, edge);
        //cout<<"response:"<<response<<endl;
        if(response != DISCARD){
            if (response > -1)
                trees[response].push_back(edge);
            else{
                vector<Edge> temp_v; 
                temp_v.push_back(edge);
                trees.push_back(temp_v);                                                            
            }
        }
    }
    
    int weights= add_weights(trees);
    return weights;
}

int main(){
    

    int t; cin>>t;
    while(t--){
        int n, e; cin>>n>>e;
        vector<Edge> edges;
        for (int i=0; i<e; i++){
            int u, v, w; cin>>u>>v>>w;
            int temp= u;
            u= min(u, v);
            v= max(temp, v);

            edges.push_back( Edge(w, u, v));
        }
        int solution= solve(edges, n);
        cout<<solution<<endl;  
    }
}

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
};

bool sort_edge_weights(Edge a, Edge b){
    return a.weight > b.weight;
}

int check_existance_in_trees(vector< vector<Edge> > & trees, Edge edge){
    int tree_id= -1, other_vertex_id= -1;

    for (int i=0; i<trees.size(); i++){
        vector<Edge> tree= trees[i];
        for (int j=0; j<tree.size(); j++){
            if(tree[j].U == edge.U && tree[j].V== edge.V) return DISCARD;
            cout<<"here"<<endl;
            if(tree[j].U==edge.U ){
                if (tree_id == -1){
                    tree_id= j;
                    other_vertex_id= edge.V;
                }else if((tree_id == j && other_vertex_id == edge.V) ||  tree_id != j) return DISCARD;
            }else if (tree[j].V == edge.V){
                if(tree_id == -1){
                    tree_id= j;
                    other_vertex_id= edge.U;
                }else if((tree_id == j && other_vertex_id == edge.U ) || tree_id != j) return DISCARD;
            }
        }
    }
    return tree_id;
}

void print_trees(vector< vector< Edge> > & trees){
    for (int i=0; i<trees.size(); i++){
        vector<Edge> tree= trees[i];
        for (int j=0; j<tree.size(); j++){
            cout<<"W:"<<tree[j].weight<<" V:"<<tree[j].V<<" U:"<<tree[j].U<<endl;
        }
        cout<<endl;
    }
}

int solve(vector<Edge> edges, int n){
    sort(edges.begin(), edges.end(), sort_edge_weights);
    vector< vector<Edge> > trees;

    int tree_id= -1;
    while (! edges.empty()){
        cout<<"size:"<<edges.size()<<endl;
        Edge edge= edges[edges.size()-1];
        edges.pop_back();
        int response= check_existance_in_trees(trees, edge);
        if(response != DISCARD){
            if (response > -1)
                trees[response].push_back(edge);
            else{
                vector<Edge> temp_v; temp_v.push_back(edge);
                trees.push_back(temp_v);
            }
        }
    }
    cout<<"treesize:"<<trees.size()<<endl;
    print_trees(trees);
    return 0;
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
            int solution= solve(edges, n);
        }
    }
}

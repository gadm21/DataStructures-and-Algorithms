#include <bits/stdc++.h>
using namespace std;

const int MAX= 4;

bool backprob(int m[MAX][MAX], int n, int i, int j, char &answer);

bool valid(pair<int, int> cell, int n, int m[MAX][MAX]){
    if(cell.first >= n || cell.second >= n) return false;
    if(!m[cell.first][cell.second]) return false;

    return true;
}

bool check_all(vector< vector< pair<int, int> > > roads, int n){
    for(auto road: roads)
        if(road[road.size()-1].first != n-1 && road[road.size()-1].second != n-1) return false;
    
    return true;
    
}

string cvt2str(vector<pair<int, int> > road){
    vector<int> next_call_x= {0, 0, -1, 1};
    vector<int> next_call_y= {1, -1, 0, 0};   
    vector<char> directions= {'L', 'R', 'U', 'D'};
    string result;

    for(int step= 1; step< road.size(); step++){
        int inc_x= road[step].first- road[step-1].first;
        int inc_y= road[step].second- road[step-1].second;
        int i=0;
        for(; i<next_call_x.size(); i++) if(inc_x==next_call_x[i] && inc_y==next_call_y[i]) break;
        result+= directions[i];
    }

    return result;
}

vector<string> printPath(int m[MAX][MAX], int n)
{

    vector<int> next_call_x= {0, 0, -1, 1};
    vector<int> next_call_y= {1, -1, 0, 0};
    vector< vector<pair<int, int> > > roads (1, vector<pair<int, int> > (1, pair<int, int>(0, 0)));

    for (int r=0; r<roads.size(); r++){
        auto road= roads[r];
        roads.erase(roads.begin()+ r);

        for(int i=0; i<next_call_x.size(); i++){
            auto cand_dest_cell= pair<int, int> (road[road.size()-1].first+ next_call_x[i], road[road.size()-1].second+ next_call_y[i]);
            if(valid(cand_dest_cell, n, m)) roads.push_back(road);
        }

        if(check_all(roads, n)) break;
    }
    
    vector<string> results;
    for (auto road : roads) results.push_back(cvt2str(road));

    return results;

}

int main(){
    int n= 4;
    int m[n][4]= { {1, 0, 0, 0},{1, 1, 0, 1} ,{1, 1, 0, 0} ,{0, 1, 1, 1} };
    

    vector<string> s= printPath(m, n);
    cout<<s.size()<<endl;
    
}




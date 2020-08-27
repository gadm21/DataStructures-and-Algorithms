#include <bits/stdc++.h>
using namespace std;

bool compare_pairs(pair<double, double> p1, pair<double, double> p2){
    return (p1.first / p1.second) > (p2.first / p2.second);
}

void print(vector<pair<double, double> >  & v){
    for(auto p : v) cout<<p.first<<" "<<p.second<<endl;
    cout<<endl;
}

double solve(vector<pair<double, double> > & items, double capacity){
    sort(items.begin(), items.end(), compare_pairs);
    //print(items);

    double result = 0;
    for(auto item : items){
        if (capacity <= 0) break;
        double value_per_unit = item.first / item.second;
        double min_weight = item.second < capacity ? item.second : capacity;
        capacity -= min_weight;
        result += (value_per_unit * min_weight);
    }
    return result;
}

int main(){
    int n; cin>>n;
    double W; cin>>W;
    vector<pair<double, double> > items(n);
    for(int i=0; i<items.size(); i++){
        double v, w; cin>>v>>w;
        items[i] = make_pair(v,w);
    }

    double max_value = solve(items, W);
    cout<<setprecision(9)<<max_value<<endl;
}
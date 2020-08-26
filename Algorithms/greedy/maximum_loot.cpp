#include <bits/stdc++.h>
using namespace std;

bool compare_pairs(pair<double,double> p1, pair<double, double> p2){
    return p1.first > p2.first;
}

void print_pairs(vector<pair<double, double> > & v){
    for (auto i : v) cout<<i.first<<" "<<i.second<<endl;
}

long double max_fit(vector<pair<double, double> > & k, double W){
    //print_pairs(k);
    sort(k.begin(), k.end(), compare_pairs); 
    long double result = 0;
    for(int i=0; i<k.size() && W > 0 ; i++){
        double chop = k[i].second < W ? k[i].second : W; // min(k[i].second, W);
        cout<<"chop:"<<chop<<endl;
        W-=chop; 
        result += ( k[i].first*chop );
    }
    return result;
}

int main(){
    int n, W; cin>>n>>W;
    vector<pair<double, double> > knapsacks(n);
    for(int i=0; i<knapsacks.size(); i++){
        double v, w; cin>>v>>w;
        knapsacks[i] = make_pair((double)v/w,w) ;
    }
    double t1 = 32.9;
    double t2 = 432.2;
    cout<<t1/t2<<endl;
    cout<<max_fit(knapsacks, W);
}
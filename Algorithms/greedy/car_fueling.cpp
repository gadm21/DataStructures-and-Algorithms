#include <bits/stdc++.h>
using namespace std;


void print(vector<int> & v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}

int main(){
    int goalmiles, milespertank, numstops ; cin>>goalmiles>>milespertank>>numstops;
    numstops += 2; //first element for begining spot and last element for final spot 
    vector<int> stops(numstops);
    stops[0] = 0;
    stops[numstops-1] = goalmiles;
    for(int i=1; i<numstops-1; i++) cin>>stops[i];

    int numfuels = 0;
    int current = 0;
    //print(stops);
    for(int i=0; i<numstops-1; ){
        while(i+1 < numstops && stops[i+1]-stops[current] <= milespertank) i++;
        //cout<<"i:"<<i<<" current:"<<current<<" numfuels:"<<numfuels<<endl;
        if (i==current) {numfuels=-1; break;} 
        current = i;
        if (i!= numstops-1) numfuels++;
    }
    cout<<numfuels<<endl;
}
#include <bits/stdc++.h>
using namespace std;



int main(){
    int goalmiles, milespertank, numstops ; cin>>goalmiles>>milespertank>>numstops;
    numstops +=1;
    vector<int> stops(numstops+1);
    stops[0] = 0;
    stops[numstops] = goalmiles;
    for(int i=1; i<numstops; i++) cin>>stops[i];


    int numfuels = 0;
    for(int i=0; i<numstops+1; i++){
        int next_stop = i;
        while(next_stop+1 < numstops+1 && (stops[next_stop+1]-stops[i])<=milespertank) next_stop++;
        if (next_stop==i){
            numfuels = -1;
            break;
        }else numfuels+=1, i= next_stop;
        //cout<<"nextstop:"<<stops[next_stop]<<" numfuels:"<<numfuels<<endl;
        
    }
    cout<<numfuels<<endl;
}
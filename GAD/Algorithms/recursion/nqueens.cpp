/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 16 - problem 2
 */

#include <bits/stdc++.h>
using namespace std;


vector< vector<int> > results;


void print_matrix(vector<int > v){
    vector< vector<int> > matrix(v.size(), vector<int> (v.size(), 0));
    for(int i=0; i<v.size(); i++) matrix[i][v[i]]= 1;

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
void print_vv(vector<vector<int> > v){
    for(int i=0; i<v.size(); i++){
        vector<int> inside_v= v[i];
        for(int j=0; j<inside_v.size(); j++)
            cout<<inside_v[j]<<" ";
        cout<<endl;
    }
}
void print_v(vector<int> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}
inline bool checker(vector<int> &v, int index){
    if(!index) return true;
    if(index>= v.size()){
        cout<<"error"<<endl;
        return false;
    }

    for(int i=0; i<index; i++) if(abs(v[index]- v[i])== (index- i)) return false;
    
    return true;
}

void placer(vector<int> v, vector<int> cols, int index=0){

    if(index==v.size()){
        results.push_back(v);
        return;
    }

    for(int i=0; i< cols.size(); i++){
        int temp= cols[i];
        v[index]= temp;
        if(checker(v, index)){
            cols.erase(cols.begin()+ i);
            placer(v, cols, index+1);
            cols.insert(cols.begin()+i, temp);
        }
    }
}

int main(){

    int n=4;

    vector<int> v(n);
    vector<int> available_columns(n); for(int i=0; i<n; i++) available_columns[i]= i;  

    placer(v, available_columns);  

    //print_vv(results);
    cout<<results.size()<<endl;
    if(!results.empty()) print_matrix(results[0]);
}
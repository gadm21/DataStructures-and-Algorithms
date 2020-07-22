/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 16 - problem 1
 */

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<string> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

void print_state(vector< vector<string> > v, string option= ""){


    for(int level=3; level>=0; level--) {
        for(int i=0; i<v.size(); i++) if(v[i].size()> level) cout<<v[i][level]<<"  |  ";  else cout<<"      |  ";
        cout<<endl;
    }
    string line="_________________________________________________________________________________________";
    cout<<line+'\n'+line.substr(0, line.length()/2 - option.length()/2)
        +option+ line.substr(0, line.length()/2- option.length()/2)+ '\n';
    cout<<endl<<endl;
}


void compute_tower_hanoi_steps(vector< vector<string> > &pegs, int rings, int from, int to, int use, string option= ""){
    print_state(pegs, option+" "+ to_string(rings));
    if(rings>0){
        compute_tower_hanoi_steps(pegs, rings-1, from, use, to, "main call");

        string d= *(--(pegs[from].end())); pegs[from].pop_back();
        pegs[to].push_back(d);
        cout<<"element:"<<d<<" moved from:"<< from<< " to:"<<to<<endl;

        compute_tower_hanoi_steps(pegs, rings-1, use, to, from, "secondary call");
    }
}

void compute_tower_hanoi(){
    vector< vector< string> > pegs(3, vector<string>(0));
    pegs[0]= {"xlar", "larg", "medi", "smal"};

    compute_tower_hanoi_steps(pegs, 4, 0, 1, 2);

    
}


int main(){
    compute_tower_hanoi();
    cout<<"done"<<endl;
}
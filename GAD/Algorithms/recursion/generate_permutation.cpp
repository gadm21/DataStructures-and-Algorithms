/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 16 - problem 3
 */


#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > permutations;


void generate_permutation(vector<int> src, vector<int> dst, int index=0){
    if(src.empty()){
        
        permutations.push_back(dst);
        return;
    }

    for(int i=0; i<src.size(); i++){
        int temp= src[i];
        dst[index]= temp;

        src.erase(src.begin()+ i);
        generate_permutation(src, dst, index+1);
        src.insert(src.begin()+i, temp);

    }
}

void print_results(){
    for(int i=0; i<permutations.size(); i++){
        for(int j=0; j<permutations[i].size(); j++) cout<<permutations[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    vector<int> v= {2, 5, 6, 55};
    vector<int> s(v.size());
    generate_permutation(v, s);
    print_results();
}
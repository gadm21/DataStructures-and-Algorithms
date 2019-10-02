/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 12 - problem 6
 */

#include <bits/stdc++.h>
using namespace std;

bool matrix_binary_search(int target, vector< vector<int> > m){
    int row= 0;
    int col= m[0].size()-1;
    while(row< m.size() && col>=0){
        if(m[row][col]< target) row++;
        else if(m[row][col]> target) col--;
        else return true;
    }
    return false;
}


int main(){
    vector <vector< int> > m(4, vector<int> (3));
    m[0]= {1, 2, 3};
    m[1]= {4, 5, 6};
    m[2]= {7, 8, 9};
    m[3]= {10, 11, 12};
    for(int i=0; i<20; i++) cout<<i<<": "<<matrix_binary_search(i, m)<<endl;
}
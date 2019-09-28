/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 12 - problem 4
 */

#include <bits/stdc++.h>
using namespace std;

int compute_int_sqrt(int k){
    if(!k) return 0;
    int n= sqrt(k); 
    vector<int> candidates(n+1);
    for(int i=0; i<=n; i++) candidates[i]= i+1;

    int first= 0;
    int last= n;
    while(last>= first){
        int middle= first+ (last- first)/2;
        int ans= (int)pow(candidates[middle], 2);
        int next_ans= ((middle+1)< candidates.size())? pow(candidates[middle+1], 2): ans;

        if(ans<= k && next_ans>= k) return candidates[middle];
        else if(ans< k) first= middle+1;
        else last= middle;
    }
    return -1; //this is just for code convention, but you shouldn't reach here ever.
}

int compute_int_sqrt_2(int k){
    int first= 0;
    int last= k;
    while(first<=last){

        int mid= first+ (last- first)/2;
        int sq= pow(mid, 2);
        if(sq<= k) first= mid+ 1;
        else if(sq> k) last= mid-1;
    }
    return first-1;
}


int main(){
     cout<<compute_int_sqrt(300)<<endl;
     cout<<compute_int_sqrt_2(300)<<endl;
}
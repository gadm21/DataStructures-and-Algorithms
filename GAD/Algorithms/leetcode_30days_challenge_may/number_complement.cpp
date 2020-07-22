#include <bits/stdc++.h>
using namespace std; 


class Solution{
public:
    int findComplement(int num){
        int first = 0;
        while (num>>first) first++;
        for(int i=0; i<first; i++) num^=(1<<i);
        return num;
    }
};


int main(){
    Solution sol ;
    sol.findComplement(5);
    sol.findComplement(1);
}
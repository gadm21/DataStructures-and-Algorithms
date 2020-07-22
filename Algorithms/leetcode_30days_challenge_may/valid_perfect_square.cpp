

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    bool isPerfectSquare(int num){
        return sqrt(num) == (int) sqrt(num);
    }
};


int main(){
    Solution sol;
    vector<int> v = {4,6,8,15,16};
    for(int e : v) cout<<e<<" is perfectSquare? "<<sol.isPerfectSquare(e)<<endl;
}
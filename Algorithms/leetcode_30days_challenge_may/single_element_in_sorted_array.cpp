#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int singleNonDuplicate(vector<int> & nums){
        int answer = 0;
        for(auto e : nums) answer ^= e;
        return answer;
    }
};


int main(){
    vector<int> v = {1,1,2,3,3,4,4,8,8};
    Solution sol;
    cout<<sol.singleNonDuplicate(v)<<endl;
}
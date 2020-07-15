#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int majorityElement(vector<int> & nums){
        int c = nums[0];
        map<int,int> freq;
        for(auto e : nums) freq[e]++;

        for(auto e : freq) if (e.second > freq[c]) c = e.first;
        return c;
    }

};

int main(){
    Solution sol ;
    vector<int> n = {3,3,4};
    vector<int> n2 = {2,2,1,1,1,2,2};

    cout<<sol.majorityElement(n)<<endl;
    cout<<sol.majorityElement(n2)<<endl;
}
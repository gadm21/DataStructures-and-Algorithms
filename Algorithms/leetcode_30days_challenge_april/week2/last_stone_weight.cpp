#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int> & stones){
        while(stones.size() >= 2){
            auto max1 = max_element(stones.begin(), stones.end());
            int max1_int = *max1;
            stones.erase(max1);

            auto max2 = max_element(stones.begin(), stones.end());
            int max2_int = *max2;
            stones.erase(max2);
            int diff = abs(max2_int - max1_int); 
            
            if (diff > 0) stones.push_back(diff);
        }
        return stones.empty()? 0 : stones[0];
    }
};


int main(){
    vector<int> test = {4,8} ;
    Solution s;
    cout<<s.lastStoneWeight(test)<<endl;
}
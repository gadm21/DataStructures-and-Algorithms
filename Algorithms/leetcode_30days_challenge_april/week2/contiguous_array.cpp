#include <bits/stdc++.h>
using namespace std;


class Solution {
public: 

    bool reduce_acc(vector<int> & nums, int diff, int & acc, int & size){
        if (nums.empty() || (*nums.begin() ==0 && *nums.end()==0)) return false;
        
        //cout<<"reduce_acc:";
        //for(auto it: nums) cout<<it<<" ";
        //cout<<endl;
        bool changed = false;
        while(!nums.empty() && * nums.begin() == 1 && diff){
            changed = true;
            nums.erase(nums.begin());
            diff--;
            size--;
            acc--;
        }
        while(!nums.empty() && nums.back() == 1 && diff){
            changed = true;
            nums.pop_back();
            diff--;
            size--;
            acc--;
        } 

       // cout<<"reduce_acc_after:";
       // for(auto it: nums) cout<<it<<" ";
       // cout<<"changed:"<<changed<<endl;
        return changed;
    }
    
    bool reduce_size(vector<int> & nums, int diff, int & acc, int & size){
        if (nums.empty() || (*nums.begin() ==1 && *nums.end()==1)) return false;
        
       // cout<<"reduce_size:";
        //for(auto it: nums) cout<<it<<" ";
       // cout<<endl;
        bool changed = false;
        while(!nums.empty() && * nums.begin() == 0 && diff){
            changed = true;
            nums.erase(nums.begin());
            diff--;
            size--;
        }
        while(!nums.empty() && nums.back() == 0 && diff){
            changed = true;
            nums.pop_back();
            diff--;
            size--;
        }      

      //  cout<<"reduce_size_after:";
       // for(auto it: nums) cout<<it<<" ";
       // cout<<"changed:"<<changed<<endl;      
        return changed;
    }

    int findMaxLength(vector<int>& nums) {
        //cout<<"starting with:";
        for(auto it: nums) //cout<<it<<" ";
        //cout<<endl;
        if (nums.empty()) return 0;
        int acc = accumulate(nums.begin(), nums.end(), 0) ;
        int size = nums.size();

        while((acc*2) != size){
            int diff = abs((acc*2)-size);
            bool changed = false;
            if (acc*2 > size) changed = reduce_acc(nums, diff, acc, size);
            else changed = reduce_size(nums, diff, acc, size);
            if (!changed){
                int b = nums.back();
                nums.pop_back();
                if (b) acc--;
                diff--;
                size--;
            }
            
        } 

        //for(auto i : nums) cout<<i<<" ";
        //cout<<endl;
         
        return nums.size();
    }
};


int main(){
    Solution sol;
    vector<int> v = {0,1,1,0,1,1,1,0};
    cout<<sol.findMaxLength(v)<<endl;
}
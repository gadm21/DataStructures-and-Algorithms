
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> results(100, vector<int>());

void maxSubArray(vector<int>& nums, int index=0) {
    if(nums.size()==1) return;

    int last = nums[nums.size()-1];
    nums.pop_back();
    results[index].push_back(last);
    results[index+1].push_back(last);
    maxSubArray(nums, index+1);
    maxSubArray(nums, index+2);
    
}

vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
void print(vector<int> v){
    for(int a: v) cout<<a<<" ";
    cout<<endl;
}
void print_big(vector<vector<int> > v){
    for (auto s : v){
        if (s.empty()) return ;
        print(s);
    }
}
void zeros(vector<int> v){
    int l =0, r= 0;
    while(r!=v.size()){
        if (v[l]==0){
            swap(v[l], v[r]);
            l--;
            r++;                
        }
        
        print(v);
        l++;
        
    
    }   
}
int main(){
    maxSubArray(a);
    print_big(results);
}
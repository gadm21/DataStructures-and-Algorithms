
#include <bits/stdc++.h>
using namespace std;


/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


int maxSubArray(vector<int> nums) {
    
    int a = 0;
    int ans = INT_MIN;
    for(int x : nums){
        a += x;
        //change the order of line 1 & line 2 based on the 
        //problem statement. If the subarray sum should be 
        //at least zero then change the order of these lines.
        ans = max(ans, a);  //line 1
        a = max(a, 0);      //line 2
        
    }
    return ans ;
}

vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};


int main(){
    
    int x = maxSubArray(a);
    cout<<x<<endl;
}
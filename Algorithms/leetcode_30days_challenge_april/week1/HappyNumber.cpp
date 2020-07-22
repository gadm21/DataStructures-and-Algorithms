

#include <bits/stdc++.h>
using namespace std;


/*

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


*/


class Solution {
public:
    vector<int> history;
    vector<int> separate(int n){
        vector<int> v;
        for(; n; n/=10) v.push_back(n%10);
        return v;
    }
    int add(vector<int> v){
        int result = 0;
        for (int a : v) result += (a*a);
        return result ;
    }
    bool check(int n){return n==1;}
    bool in_history(int n){
        for(int a : history) if(n==a) return true;
        return false;
    }
    bool isHappy(int n) {
        
        while(true){
            vector<int> sep = separate(n);
            n = add(sep);
            if (in_history(n)) return false;
            else{
                history.push_back(n);
                if(check(n)) return true;
            }
        }
    }
};
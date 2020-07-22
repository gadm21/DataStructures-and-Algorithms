/*
https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
this solution wasn't accepted because it's complexity is O(n^2) and thus it gets TLE.
another accepted solution with complexity of O(n) can be found it DataStructures/Stack where 
you can find two implementations, python and c++, using a stack-based approach 
*/

/*
 *
 * Also, today I've learnt from a bug in this solution. when I used an unsigned long long in a backward for
 * loop, for(ull j=i; j>=0; j--), it gave me error because this loop will never end. figure out why yourself.
 * I had to change re #define ull to long long instead of unsigned long long
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;
#define ull long long



int main(){
    int t; cin>>t;
    while(t--){
        ull n; cin>>n;
        vector<ull> v(n);
        for(ull i=0; i<n; i++) cin>>v[i];

        ull result= 0;
        for(ull i= (n-1); i>=0; i--){
            ull min_bar= v[i];
            for(ull j=i; j>=0; j--){
                if(min_bar< v[j]) min_bar= v[j];
                ull new_result= min_bar*(i-j+1);
                if(new_result> result) result= new_result;
            }
            
        }

        cout<<result<<endl;
    }
}
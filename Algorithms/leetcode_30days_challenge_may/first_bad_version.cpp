

#include <bits/stdc++.h>
using namespace std;



vector<bool> arr(100, false);

void print(vector<bool> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}
void make_versions(int target, int n = 100){
    arr = vector<bool> (n, false);
    for(int i=target; i<arr.size(); i++) arr[i] = true ; 
}

bool isBadVersion(int t){ return arr[t];}


class Solution {
public:
    
    int found(int i, int n, bool bad){
        if(bad) if (i==0 || i==n-1) return i ;
            
        if (bad && ! isBadVersion(i-1)) return i;
        if (!bad && isBadVersion(i+1)) return i+1;
        
        return -1 ;
        
    }
    int firstBadVersion(int n) {
        int l = 0, r = n;
        
        while(l<r){
            int m = (int) l + (r-1)/2 ; 
            //cout<<"index:"<<m<<endl;

            bool bad = isBadVersion(m);
            //cout<<"isBad:"<<bad<<endl; 

            int f = found(m,n,bad);
            //cout<<"found:"<<f<<endl;
            if (f != -1) return m;
            
            if (bad) r = m;
            else l = m;
        }
        
    }
};




void test(){
    Solution s;
    for (int i=0; i<10; i++){
        int t = rand() % 100 ;
        int n = t + rand() % 500 ;
        make_versions(t, n);
        cout<<"true target:"<<t<<endl;
        int predicted_t = s.firstBadVersion(100);
        cout<<"predicted target:"<<predicted_t<<endl;
        cout<<endl;
    }
}

int main(){
    test();
}
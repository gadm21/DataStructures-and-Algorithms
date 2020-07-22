//this solution gets a runtime error on 
//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0#_=_

#include "Stack.cpp"
#define ul long long 
#define ui unsigned int
#define ull unsigned long long

int LargestRectangleArea(vector<int> v){
    int result= 0;
    Stack<int> s(v.size());
    s.push(-1);


    for (int i=0; i<v.size(); i++){
        while((*s.GetTop())!= -1 && v[(*s.GetTop())]>= v[i]){
            int lastStacked= *(s.pop());
            result= max(result,
             v[lastStacked]* (i- (*s.GetTop()) -1));
        }
        s.push(i);
    }

    int v_size= v.size();
    while((*s.GetTop())!= -1){
        int lastStacked= *(s.pop());
        result= max(result,
        v[lastStacked]* (v_size- (*s.GetTop()) -1) );
    }

    return result;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        cout<<LargestRectangleArea(v)<<endl;
    }
}
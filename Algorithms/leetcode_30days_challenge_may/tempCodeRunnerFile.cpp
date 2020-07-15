#include <bits/stdc++.h>
using namespace std; 


class Solution{
public:
    int findComplement(int num){
        int num2 = ~num;
        cout<<num2<<endl;
        string binary = bitset<32>(num).to_string();
        string binary2 = bitset<32>(num2).to_string();
        return num2;
    }
};


int main(){
    int n = 1;
    int t = n<<2;
    cout<<t<<endl;
}
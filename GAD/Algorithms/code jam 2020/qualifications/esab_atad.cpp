#include <bits/stdc++.h>
using namespace std;

#define REVERSE 10
#define NOTHING  0
#define FLIP 20
#define BOTH 5

int query(int i){
    cout<<i<<endl;
    int value;
    cin>>value;
    return value;
}

int what_happened(vector<int> answer, int found, int found_diff){
    if(found==-1){
        //can check for : 
        //flipped
        //reversed
        int new_value = query(found_diff);
        if (answer[found_diff] != new_value) return FLIP ;
        else return NOTHING;

    }else if(found_diff==-1){
        //can check for :
        //flipped
        //both
        int new_value = query(found);
        if(answer[found] != new_value) return FLIP;
    }else{
        //can check for:
        //flip
        //reverse
        //both
        int new_equal = query(found);
        int new_diff = query(found_diff);
        if (answer[found] != new_equal){
            if(answer[found_diff] != new_diff) return BOTH;
            else return FLIP;
        }else{
            if(answer[found_diff] != new_diff) return REVERSE;
            else return NOTHING;
        }
        
    }
}

void test_case(int B){

    int L=0, R=B;
    int qn = 1; //query number
    vector<int> answer(B+1);
    for(int i=1; i<= B/2; i++){
        if(i%10==1 && i!=1){
        
            int found=-1, found_diff=-1;
            for (int j=1; j<=i; j++)
                if (answer[j]==answer[B-j+1]) found = j;
                else found_diff = j;
                
            int response = what_happened(answer, found, found_diff);
            if (response == FLIP){
                for(int j=1; j<=i; j++){
                    answer[j]^=1;
                    answer[B-j+1]^=1;
                }
            }else if(response == REVERSE){
                reverse(answer.begin()+1, answer.end());
            }else if(response == BOTH){
                reverse(answer.begin()+1, answer.end());
                for(int j=1; j<=i; j++){
                    answer[j]^=1;
                    answer[B-j+1]^=1;
                }
            }
            
        }
        answer[i] = query(i);
        answer[B-i+1] = query(B-i+1);
        
    }
    for(int i=1; i<=B; i++){
        cout<<answer[i];
    }
    cout<<endl;
    string s;
    cin>>s;
    return;
}

int main(){
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        //printf("Case #%d: ", t);
        test_case(50);
    }
}
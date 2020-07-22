
#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int> > m){
    int s= m.size();
    for (int i=0; i<s; i++){
        for (int j=0; j<s; j++) 
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

}

int calc_trace(vector< vector<int> > m){
    int s= m.size(); 
    int result= 0;
    for(int i=0; i<s; i++) result+= m[i][i];
    return result;
}

int calc_repeated(vector< vector<int> > m){
    int s= m.size();
    int repeated= 0;
    for(int i=0; i<s; i++){
        sort(m[i].begin(), m[i].end());
        for(int j=1; j<s; j++)
            if(m[i][j] == m[i][j-1]){
                repeated+= 1;
                break;
            }
        
    }
    return repeated;
}


int main(){
    

    int T; cin>>T;
    for (int t=1 ; t<=T ; t++){
        int N; cin>>N;
        vector< vector<int> > matrix(N, vector<int> (N));
        vector< vector<int> > matrix_cols(N, vector<int> (N));

        for(int i=0 ; i<N; i++)
            for(int j=0; j<N; j++){
                cin>>matrix[i][j];
                matrix_cols[j][i] = matrix[i][j];
            }
                
            
        int trace = calc_trace(matrix);
        int repeated_rows = calc_repeated(matrix);
        int repeated_cols = calc_repeated(matrix_cols);
        
        cout<<"Case #"<<t<<": "<<trace<<" "<<repeated_rows<<" "<<repeated_cols<<endl;
    }
}
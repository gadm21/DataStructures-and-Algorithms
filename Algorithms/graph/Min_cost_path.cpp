#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int

vector< vector<int> > matrix;

ui min_cost_path1(int m, int n){
    if(!m && !n) return matrix[0][0];
    else if(m<0 || n<0) return INT_MAX;
    
    ui cost= matrix[m][n];
    return min(
        min(
            cost+ min_cost_path1(m- 1, n- 1),
            cost+ min_cost_path1(m- 1, n)
        ),
        cost+ min_cost_path1(m, n-1)
    );
}


//...........................................................
//...........................................................

/*
this is my implementation, it's good but I didn't take into consideration the constraint that:
"You can only traverse down, right and diagonally lower cells from a given cell, 
i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed." which would have made the solution much simpler.
*/

ui REF_COST= 0;

ui min_cost(int i, int j, int m, int n, ui my_cost= 0){
    
    if(i < 0 || j< 0 || i== matrix.size() || j== matrix[0].size() || my_cost> REF_COST ) return INT_MAX;
    my_cost+= matrix[i][j];
    
    if(i==m && j==n){
        if(my_cost< REF_COST)REF_COST= my_cost; 
       
        return my_cost;
    }
    
    return min(min( min_cost(i+1, j+1, m, n, my_cost),
                    min_cost(i+1, j, m, n, my_cost)),
                    min_cost(i, j+1, m, n, my_cost)
    );
    
}

ui min_cost_path2(int m, int n){
    
    ui i=0, j=0;
    do{REF_COST+= matrix[i++][j]; cout<<"ref_cost:"<<REF_COST<<endl;}while(i< m);
    do{REF_COST+= matrix[i][j++]; cout<<"ref_cost:"<<REF_COST<<endl;}while(j<=n);
    
    return min_cost(0, 0, m, n);
}


//...........................................................
//...........................................................

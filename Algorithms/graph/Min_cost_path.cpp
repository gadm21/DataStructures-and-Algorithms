#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int

vector< vector<int> > matrix; //this represents the graph

ui min_cost_recursion(int m, int n){
    if(m<0 || n<0) return INT_MAX; // stop if any of the indicies became neg
    
    //calculate the cost of the current cell
    ui cost= matrix[m][n];
    return min(
        min(
            cost+ min_cost_recursion(m- 1, n- 1),  //what if I moved diagonally 
            cost+ min_cost_recursion(m- 1, n)  //what if I moved up
        ),
        cost+ min_cost_recursion(m, n-1)  //what if I moved left
    );
}

ui min_cost_dp(int m, int n){
    ui out_size= matrix.size();
    ui in_size= matrix[0].size();

    vector< vector <int> > dp(out_size, vector<int> (in_size)); //make a temperary matrix to save cumulative costs

    //initialize rows and columns
    for(int i=0; i<in_size; i++) dp[0][i]= (i) ? (matrix[0][i]+ dp[0][i-1]) : (matrix[0][0]);
    for(int j=0; j<out_size; j++) dp[j][0]= (j) ? (matrix[j][0]+ dp[j-1][0]) : (matrix[0][0]);

    //for each cell, choose the minimal cost path to reach it, either from top, left, or diagonally.
    //this is a down-top dp approach as we start with finding the costs of columns and rows (the prev two loops)
    //then we go cell after cell building cumulative costs on each others' calculations.
    for(int i=1; i<= m; i++)
        for(int j=1; j<= n; j++)
            dp[i][j]= matrix[i][j]+ min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
    
    return dp[m][n];
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
    
    //stop if any of the endicies got out of boundaries
    if(i < 0 || j< 0 || i== matrix.size() || j== matrix[0].size() || my_cost> REF_COST ) return INT_MAX;
    my_cost+= matrix[i][j];
    
    if(i==m && j==n){
        //update the reference cost If my bath is smaller,
        //so that following trials will not bother trying to beat an old reference cost I've already beaten.
        if(my_cost< REF_COST)REF_COST= my_cost; 
       
        return my_cost;
    }
    
    return min(min( min_cost(i+1, j+1, m, n, my_cost),
                    min_cost(i+1, j, m, n, my_cost)),
                    min_cost(i, j+1, m, n, my_cost)
    );
    
}

ui min_cost_path2(int m, int n){
    /* 
    this function calculates a rough cost for the both so that it can be used as a reference cost to 
    eliminate the candidate pathes that exceed this cost
    */
    ui i=0, j=0;
    do{REF_COST+= matrix[i++][j]; }while(i< m);
    do{REF_COST+= matrix[i][j++]; }while(j<=n);
    
    return min_cost(0, 0, m, n);
}


//...........................................................
//...........................................................


void print(vector<vector<int > > &matrix){
    ui out_size= matrix.size();
    ui in_size= matrix[0].size();
    
    for(int i=0; i<out_size; i++){
        for(int j=0; j<in_size; j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}



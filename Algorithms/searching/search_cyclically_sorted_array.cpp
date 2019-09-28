#include <bits/stdc++.h>
using namespace std;


int find_smallest(int* arr, int size){
    int f= 0;
    int l= size-1;
    while(f<=l){
        int m= f+ (l-f)/2;
        if(arr[m]< arr[l]) l= m;
        else f= m+1;
    }
    return l;
}

int binary_cyclic_search(int* arr, int x, int size){
    /* the find_smallest function assumes that every element only exits once, otherwise you'll
    have to use linear approach i.e. inspect each element to find the smallest one */
    int first= find_smallest(arr, size); 
    int last= (!first)? size-1: first-1;

    while(first!= last){
        
        int middle=  (last> first)?  (first+ (last- first)/2)
                                  :  (first+ ((size- first)+ last)/2) % size;
        if(arr[middle]< x) first= middle+1;
        else if(arr[middle]> x) last= middle;
        else return middle;
    }

    
    return (arr[first]==x)? first : -1;
   
}

int main(){
    int arr[7]= {3, 4, 5, 6, 7, 1, 2};
    for(int i=0; i<9; i++)
        cout<<binary_cyclic_search(arr, i, 7)<<endl;

    

}
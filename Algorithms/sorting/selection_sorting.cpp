#include <bits/stdc++.h>
using namespace std;

void swap(int & i, int & j){
    int temp= i;
    i= j;
    j= temp;
}


void selection_sorting(int * arr, int size){
    bool sorted= false;

    for(int j=0; j<size && !sorted; j++){
        sorted= true;
        int smallest_index= j;
        int biggest_index= j;

        for(int i= j+1; i<size; i++){
            if(arr[i] < arr[smallest_index]) smallest_index= i;
            if(arr[i] < arr[i-1]) sorted= false;
        }

        if(smallest_index != j) swap(arr[smallest_index], arr[j]);
    }

}

void print_arr(int * arr, int size){
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}


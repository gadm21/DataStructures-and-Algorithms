#include <bits/stdc++.h>
using namespace std;


void merge(int *arr, int first, int middle, int last){
    int size1= middle- first+ 1;
    int size2= last- middle;

    vector<int> v1(size1);
    vector<int> v2(size2);

    for(int i=0; i<size1; i++) v1[i]= arr[first+ i];
    for(int i=0; i<size2; i++) v2[i]= arr[middle+ 1+ i];

    int i=0, j=0, k=first;
    while(i< size1 && j< size2){
        if(v1[i]<= v2[j]) arr[k++]= v1[i++];
        else arr[k++]= v2[j++];
    }

    while(i<size1) arr[k++]= v1[i++];
    while(j<size2) arr[k++]= v2[j++];
}

void merge_sort(int *arr, int first, int last){
    if(first< last){
        int middle= first+ (last- first)/2;

        merge_sort(arr, first, middle);
        merge_sort(arr, middle+1, last);

        merge(arr, first, middle, last);
    }
}

void print(int* arr, int size){
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

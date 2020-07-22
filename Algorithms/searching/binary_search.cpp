#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int size, int target, int first=0, int last=-1){
    if(last==-1) last= size;

    while(last> first){
        int middle= first+ (last- first)/2;
        
        if(arr[middle]== target) return middle;
        else if(arr[middle]< target) first= middle+1;
        else last= middle;
    }

    return -1;
}


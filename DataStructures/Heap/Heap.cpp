#include "Heap.h"
using namespace std;


void swap(int &a, int &b){
    int temp= a;
    a= b;
    b= temp;
}

MinHeap::MinHeap() : MinHeap(10){  }
MinHeap::MinHeap(int capacity_){
    capacity= capacity_;
    arr= (int*) malloc(capacity * sizeof(int));
    current_size= 0;
}

MinHeap::~MinHeap(){ delete arr;}

void MinHeap::insert(int key_){
    if(current_size== capacity){
        cout<<"overflow, can't insert another element"<<endl;
        return;
    }
    
    int i= current_size;
    arr[current_size++] = key_;
    
    cout<<"key:"<<key_<<" parent:"<<arr[get_parent(i)]<<" i:"<<i<<endl;
    //heapify
    while(i!= 0 && arr[get_parent(i)] > arr[i]){
        swap(arr[i], arr[get_parent(i)]); 
        i= get_parent(i);
    }
        

}
bool MinHeap::remove(int index){
    if(index >= current_size) return false;
    current_size--;
    arr[index]= INT_MAX;
    MinHeapify(index);
    return true;
}
void MinHeap::MinHeapify(int index){
    if(index >= current_size-1) return ;

    int left_index= get_left(index);
    int right_index= get_right(index);
    int smallest_index= index;

    if(arr[left_index] < arr[index]) smallest_index= left_index;
    if(arr[right_index] < arr[smallest_index]) smallest_index= right_index;

    if(smallest_index != index){
        swap(arr[smallest_index], arr[index]);
        MinHeapify(smallest_index);
    }

}

bool MinHeap::getMin(int & key){
    if(!current_size) return false;
    key= arr[0];
    return true;
}
bool MinHeap::extractMin(int & key){
    if(!current_size) return false;
    current_size--;
    key= arr[0];
    if(current_size){
        arr[0]= arr[current_size];
        MinHeapify(0);
    }
    return true;
        
}
int MinHeap::get_parent(int index_){  return (index_-1)/2;}
int MinHeap::get_left(int index_){ return (index_*2)+1; }
int MinHeap::get_right(int index_){ return (index_*2)+2;}

void MinHeap::print(){
    for(int i=0; i< current_size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    MinHeap m;
    int kk=0;
    
    m.insert(34);
    m.insert(67);
    m.insert(69);
    m.insert(24);
    m.print();
    m.extractMin(kk);
    m.print();
}
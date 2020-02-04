#include "../Heap.cpp"


int main()
{
    Heap<int, MAX_HEAP> max_heap;
    Heap<int, MIN_HEAP> min_heap;

    for(int i=0; i<15; i++){
        int x= rand() ;
        max_heap.insert(x);
        min_heap.insert(x);
    }

    max_heap.print();
    min_heap.print();
}
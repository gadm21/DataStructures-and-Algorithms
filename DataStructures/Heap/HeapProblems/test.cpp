#include "../Heap.cpp"


int main()
{
    Heap<int, MAX_HEAP> max_heap;
    Heap<int, MIN_HEAP> min_heap;

    for(int i=0; i<15; i++){
        int x= rand() % 100  ;
        max_heap.insert(x);
        min_heap.insert(x);
    }

    for(int i=0; i<4; i++){
        max_heap.remove(0);
        min_heap.remove(0);
    }
    max_heap.print();
    min_heap.print();
}
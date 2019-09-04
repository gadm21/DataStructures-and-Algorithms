

template<class T>
class Node{
    public:
        T Data;
        Node *Prev, *Next;
        Node(T data, Node* prev= nullptr, Node* next= nullptr){
            Data= data;
            Prev= prev;
            Next= next;
        }

        void print(){
            std::cout<<Data<<std::endl;
        }
};


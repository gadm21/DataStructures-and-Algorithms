class Node():
    def __init__(self, data= None, next= None):
        self.data= data
        self.next= next
    
    def __str__(self):
        return str(self.data)
    
    
class SingleLinkedList():
    def __init__(self):
        self.head= None
        self.size= 0
    
    def push_back(self, data):
        node= Node(data)
        if not self.head:
            self.head= node
        else:
            temp= self.head
            while temp.next: 
                temp= temp.next
            temp.next= node
        self.size+=1
    def push_front(self, data):
        node= Node(data)
        node.next= self.head
        self.head= node
        self.size+= 1
    
    def delete(self, data):
        temp= self.head
        if not temp or temp.data== data: 
            self.head= self.head.next
            self.size-=1
            return

        while temp and temp.next:
            if temp.next.data== data: break
            else: temp= temp.next
        
        if temp.next:
            temp.next= temp.next.next
        else:
            print("element not found")

        self.size-=1 

    def search(self, data):
        temp= self.head
        while temp:
            if temp.data== data: break
            else: temp= temp.next
        
        if temp: return True
        else: return False
    def binary_search(self, data):
        end= self.size
        first= 0

        while end> first:
            current_index= first+ (end- first)/2
            current_node= self[current_index]
            if current_node.data== data:
                return True
            elif current_node.data< data:
                first= current_index
            else: end= current_index
        
        return False



    def merge(self, first, middle, last):
        size1= middle- first + 1
        size2= last- (middle+1) + 1

        v1= []
        v2= []

        for i in range(0, size1):
            v1.append(self[i+ first].data)
        for i in range(0, size2):
            v2.append(self[middle+1+i].data)
        
        i=0
        j=0
        k=first
        while i< size1 and j< size2:
            if v1[i]< v2[j]: 
                self[k].data= v1[i]
                i+= 1
                k+= 1
            else:
                self[k].data= v2[j]
                j+= 1
                k+= 1
        
        while i< size1:
            self[k].data= v1[i]
            i+= 1
            k+= 1
        while j< size2:
            self[k].data= v2[j]
            j+= 1
            k+= 1

    def sort(self, first=-1, last= -1):
        if first== -1:
            self.sort(0, self.size-1)
        else:
            if first< last:
                middle= first+ (last- first)/2

                self.sort(first, middle)
                self.sort(middle+1, last)

                self.merge(first, middle, last)

    def Print(self):
        temp= self.head
        
        while temp:
            print(temp)   
            temp= temp.next 

    def __getitem__(self, index):
        if index>= self.size: return None

        temp= self.head
        for _ in range(index):
            if not temp: break
            temp= temp.next
        
        return temp
    



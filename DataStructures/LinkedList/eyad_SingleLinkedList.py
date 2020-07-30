class node:
    def __init__(self,data=None):
        self.data=data
        self.next=None
class SingleLinkedList:
    def __init__(self):
        self.head= node()   

    def __str__(self):
        cur=self.head
        elements=[]
        while cur.next is not None:
            cur=cur.next 
            elements.append(cur.data) 
     
        str1 = ""  
        for ele in elements:
            ele=str(ele)  
            str1 += ele     
        return str1        

    def __getitem__(self,position):
        node=self.getNode(position)
        return node.data

    def __add__(self, AnotherList):
        lastnode_list1=self.getLastNode()
        lastnode_list1.next=AnotherList.head.next
        cur=self.head
        elements=[]
        while cur.next is not None:
            cur=cur.next 
            elements.append(cur.data)   
        return elements
        

    def insert(self, data, position = None): 
        newnode=node(data)
        

        if self.listlen() ==0:
            if position is not None :
                if position ==0:
                    self.head.next=newnode
                    return True
                else:

                     return False        
            

            else:
                self.head.next=newnode
                return True
        else:
            if position is not None:
                
                cur_node=self.getNode(position)
                prev_node=self.getNode(position-1)
                newnode.next=cur_node
                prev_node.next=newnode
                
                return True

           
            else :
                cur_node= self.getLastNode()
                cur_node.next=newnode
                return True

    def delete(self, position=None , data=None):
        
        if self.listlen()==0:
            
            return False
        
        else:
           
            if not data and not position :
               
                return False

        
            elif not data and position :
                
                if position< 0 or position >= self.listlen():
                    return False
                else:
                    
                    cur_node=self.getNode(position)
                    prev_node=self.getNode(position-1)
                    prev_node.next=cur_node.next
                     
                    return True
            
            elif data and not position :
                if self.listlen()==0:
                    return False
                elif self.find(data):
                    cur_node= self.getNode(self.search(data))
                    prev_node= self.getNode( (self.search(data))-1 )
                    prev_node.next=cur_node.next
                    
                    return True

            elif  data and position:
                if self.listlen()==0 or position< 0 or position >= self.listlen() :
                    return False
                
                elif self.find(data):
                    if position== self.search(data) :
                        cur_node=self.getNode(position)
                        prev_node=self.getNode(position-1)
                        prev_node.next=cur_node.next
                         
                        return True
                    else:
                        return False
            
            else:
                return False                

    def find(self, data):
        if self.listlen()==0:
            return False
        else:

            curnode=self.head
            while curnode:                         
                curnode=curnode.next
                if curnode.data == data:
                    return True
                
            return False 
   
    def getNode(self ,position):
        indx=-1
        curnode=self.head
        
        if position < -1 or position > self.listlen():
            
            return False
        else :
            
            while True:
                if indx == position:
                   
                    return curnode
                curnode = curnode.next
                indx += 1 
    
    def getLastNode(self):
        cur=self.head
        while cur.next is not None:
            cur=cur.next 
               
        return cur
       
    def search(self, data):
        if self.listlen()==0:
            return False
        else:
            curnode=self.head.next 
            curindx=0
            while curnode:
                if curnode.data == data:
                    return curindx
                curnode=curnode.next
                curindx+=1
            return False
         
    def listlen(self):
        cur=self.head
        len = 0
        while cur.next is not None:
            cur=cur.next 
            len+=1   
        return len

    def printNodes(self):
        cur=self.head
        elements=[]
        while cur.next is not None:
            cur=cur.next 
            elements.append(cur.data)   
        print(elements)
    
    def merge(self, AnotherList, position = None):
                
        if  AnotherList and self :
            if AnotherList.listlen()==0 or self.listlen()==0 :
                return False

            elif  position :
                if position >= self.listlen() or position <0 :
                    return False

                else:
                  
                    cur_node=self.getNode(position)
                    prev_node=self.getNode(position)
                    lastnode_list2= AnotherList.getLastNode()
                    lastnode_list2.next= cur_node
                    prev_node.next =AnotherList.head.next
                    return True

            elif not position:
                lastnode_list1=self.getLastNode()
                lastnode_list1.next=AnotherList.head.next

        else:
            return False
   
    def sortlist(self):
        cur=self.head
        a=[]
        while cur.next is not None:
            cur=cur.next
            a.append(cur.data)
            self.delete(None,cur.data)
        a=list(map(int,filter(lambda x:x.isdigit(),sorted(map(str,a)))))+list(filter(lambda x:x.isalpha(),sorted(map(str,a))))
        for i in a:
            self.insert(i)

        
L1 = SingleLinkedList()
L2 = SingleLinkedList()

L1.insert(1) 
L1.insert(3,1) 
L1.insert(0,0)
L1.insert(2,1)
#L1 should be [0,1,2,3]

L2.insert(10) 
L2.insert(L1.getLastNode()) 
L2.insert(L2.listlen(), 0) 
#L2 should be [2,10,3] 

print(L1)  #should print [0,1,2,3]
L2.sortlist()
print(L2)  #should print [2,3,10]


L3 = L1 + L2 
#L3 should be [0,1,2,3,2,3,10] 

print(L3) #should print  [0,1,2,3,2,3,10] 





#sortlist() should return a sorted linkedList. DONOT change the current state of nodes
#add other functions to the test (like delete() and find()) and fix bugs until you pass all tests
#add binary_search() 
#remove merge() and allow insert() to accept number, list, or linkedList


     



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
            str1=str1+ ele+" "     
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
      
        if type(data) is int or type(data) is str:
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

        elif type(data) is SingleLinkedList and  not position:
            return self.merge(data)
        elif type(data) is SingleLinkedList and  position:
            return self.merge(data, position)
        elif type(data) is list :
            L=SingleLinkedList()
            return self.merge((L.List2Linkedlist(data)),position)
    def delete(self, position=None , data=None):
        if self.listlen()==0:
            
            return False
        
        else:
           
            if not data and not position :
               
                return False

        
            elif not data and position :
                
                if position< 0 or position > self.listlen():
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
    
    def deleteNodes(self):
        cur=self.head
        while cur.next is not None:
            cur=cur.next 
            self.delete(cur.data)   
        return self

    def printNodes(self):
        cur=self.head
        elements=[]
        while cur.next is not None:
            cur=cur.next 
            elements.append(cur.data)   
        print(elements)
    
    def merge(self, AnotherList, position = None):
        AnotherList=AnotherList.Linkedlist2List()
        
        if  AnotherList and self :
            if  self.listlen()==0 :

                self.List2Linkedlist(AnotherList)
                return self

            elif  position or position==0:
                
                if position >= self.listlen() or position <0 :
                    return False

                else:
                    for i in AnotherList:
                        self.insert(i,position)
                        position+=1
                    return self

            elif not position or position!=0:
            
                self.List2Linkedlist(AnotherList)
                
                return self

        else:
            return False
   
    def copylist(self):
        cur=self.head
        l=SingleLinkedList()
        while cur.next is not None:
            cur=cur.next
            l.insert(cur.data)
        return l       

    def sortlist(self):
        cur=self.head
        a=[]
        while cur.next is not None:
            cur=cur.next
            a.append(cur.data)
            self.delete(None,cur.data)
        a.sort(key=lambda v: (isinstance(v, str), v))
        for i in a:
            self.insert(i)

        return self    
     
    def List2Linkedlist(self,listt):
        for i in listt:
            self.insert(i)
        
        return self
    def Linkedlist2List(self):
        cur=self.head
        elements=[]
        while cur.next is not None:
            cur=cur.next 
            elements.append(cur.data)   
        return(elements)

    def binarySearch(self,value):

       start = self.head
       last = None
       while True :  
           mid = self.middle(start, last) 
           if (mid == None):  
               return None
    
           if (mid . data == value): 
                return mid 
    
           elif (mid . data < value): 
                start = mid . next
    
           else: 
                last = mid 
           if not (last == None or last != start): 
                 break
       return None          
    def middle(self,start, last): 
  
         if (start == None): 
            return None

         mid = start
         mid2 = start . next
    
         while (mid2 != last): 
        
            mid2 = mid2 . next
            if (mid2 != last): 
            
                mid = mid . next
                mid2 = mid2. next
            
         return mid


L1 = SingleLinkedList()
L2 = SingleLinkedList()
L3 = SingleLinkedList()
L2.insert(1)
L2.insert(2)
 
L1.insert(0)

L1.insert([1,2,3])

L1.insert(L2)

L1.insert(20,1) 

L2.insert([4,5,9],0)
print("L1:",L1)
print("L2:",L2)



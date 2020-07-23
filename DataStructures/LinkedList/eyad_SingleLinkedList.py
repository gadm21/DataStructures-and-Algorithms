class node:
    def __init__(self,data=None):
        self.data=data
        self.next=None
class SingleLinkedList:
    def __init__(self):
        self.head= node()   

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
                    cur_node.next=None
                    return True
            
            elif data and not position :
                if self.listlen()==0:
                    return False
                elif self.find(data):
                    cur_node= self.getNode(self.search(data))
                    prev_node= self.getNode( (self.search(data))-1 )
                    prev_node.next=cur_node.next
                    cur_node.next=None
                    return True

            elif  data and position:
                if self.listlen()==0 or position< 0 or position >= self.listlen() :
                    return False
                
                elif self.find(data):
                    if position== self.search(data) :
                        cur_node=self.getNode(position)
                        prev_node=self.getNode(position-1)
                        prev_node.next=cur_node.next
                        cur_node.next=None
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
        
        if position < -1 or position >= self.listlen():
            
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

    def sort(self):
        if self.head is None or self.head.next is None :
            return False



        pass  

   
#add [] feature
#add printability feature 
#add + feature aginst other lists 
L=SingleLinkedList()
f=SingleLinkedList()


L.insert(1)
L.insert(2)
L.insert(3)
L.insert(4)
f.insert(5)
L.merge(f)

L.printNodes()
print(L.listlen())


     




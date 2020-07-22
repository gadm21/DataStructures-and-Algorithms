
def LargestRectangleArea (heights):

    stack= [-1]
    maxArea= 0

    for i in xrange(len(heights)):

        '''keep popping from the stack while it's empty and the element in consideration is 
            < the last element in the stack '''
        while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
            lastElementIndex= stack.pop()
            maxArea= max(maxArea,
                        heights[lastElementIndex]* (i- stack[-1]-1))
        
        stack.append(i)

    '''we went through all elements of heights array
        lets check if we've something left in the stack'''
    while stack[-1] != -1:
        lastElementIndex= stack.pop()
        maxArea= max(maxArea,
                    heights[lastElementIndex]* (len(heights)- stack[-1]-1))
    
    return maxArea


if __name__ == "__main__":
    
    t= input()
    for j in range(t):
        n= input()
        elements= raw_input()
        l= [int(i) for i in elements.split(' ')]
            
        result= LargestRectangleArea(l)
        print(result)
    
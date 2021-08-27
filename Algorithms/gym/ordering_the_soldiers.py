
from utils import * 

def run():
    T = int(read()) 
    for t in range(T):
        N = int(read()) 
        nums = list(map(int, read().split()))
        
        answers = []
        n = N
        charge = 0
        for i in nums[::-1]:
            answers.append(n-i)
            if i == 0 : 
                n-= charge+1 
                charge = 0
            else: charge += 1
        answers = answers[::-1]
        print(*answers)



run()
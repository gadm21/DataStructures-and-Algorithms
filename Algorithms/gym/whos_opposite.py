


# https://codeforces.com/problemset/problem/1560/B

def read(): 
    return input() 

# from utils import * 


def solve():
    answers = []
    for t in range(int(read())):
        a, b, c = list(map(int, read().split()))
        num, a, b = abs(a-b) * 2, min(a, b), max(a, b)
        if num > 3 and c <= num and abs(a-b) >= min(a,b):
            if c <= num/2 : answers.append(c+num//2)
            else: answers.append(c-num//2)
        else: 
            answers.append(-1) 
        print(answers[-1])
    return answers 




answers = solve()
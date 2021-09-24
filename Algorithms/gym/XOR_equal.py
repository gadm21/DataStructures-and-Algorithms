

# https://www.codechef.com/problems/PALINT


from collections import defaultdict, Counter
from typing import DefaultDict 
# from utils import * 
def read():
    return input() 

T = int(read()) 

for t in range(1, T+1):
    _, X = list(map(int, read().split()))
    nums = list(map(int, read().split()))
    freq = DefaultDict(int) 
    count = Counter(nums) 
    for num in nums :
        freq[num] += 1
        freq[num^X] += 1
    most_freq_v, operations = 0, 0
    for k, v in freq.items() :
        if v > most_freq_v or (v == most_freq_v and operations > v - count[k]):
            most_freq_v = v
            operations = v - count[k] 
            # print("k:{} v:{} count[k]:{}".format(k, v, count[k]))
    print(most_freq_v, operations)

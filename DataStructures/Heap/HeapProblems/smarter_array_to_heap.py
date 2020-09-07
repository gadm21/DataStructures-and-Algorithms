
def get_swaps(arr):
    swaps = [] 
    for i in range(len(arr)):
        if i >= arr[i][1] : continue
        swaps.append([i, arr[i][1]])
    return swaps

n = int(input())
i = [int(x) for x in input().split()]

arr = [[x, index] for index,x in enumerate(i)]  
arr2 = sorted(arr, key = lambda x : x[0]) 

swaps = get_swaps(arr2)

print(len(swaps)) 
for swap in swaps:
    print(swap[0]," ", swap[1])
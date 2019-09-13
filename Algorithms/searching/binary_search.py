
def binary_search(arr, target, first= 0, last=-1):
    if last==-1: last= len(arr)

    while last> first:
        middle= first+ (last- first)/2

        if arr[middle]== target: return middle
        elif arr[middle]< target: first= middle+1
        else: last= middle

    return None


def expand(s):
    s_int = [s[0]]
    for i in range(1, len(s)):
        if s[i] == s_int[-1][0] : s_int[-1] += s[i]
        else : s_int.append(s[i])

    
    return s_int 


def add_par(s_list, pars) :
    if pars == 0 : return s_list 
    p_begin = "(" * pars 
    p_end = ")" * pars 
    s_list.insert(0, p_begin) 
    s_list.append(p_end)
    return s_list 

def split_by(s_list, m):
    if len(s_list) == 1 : return []

    ind_lists = [] 
    start= 0

    for i, e in enumerate(s_list):
        if e[0] == m and start != i : 
            ind_lists.append([start, i])
            start= i + 1
    if start < len(s_list) : 
        ind_lists.append([start, len(s_list)])
    
    lists = [] 
    for ind in ind_lists:
        lists.append(s_list.copy()[ind[0]:ind[1]])
    
    return lists 


def solve(s_list, global_par = 0 ) :
    result_list = [] 
    s_list_int = [int(x) % 10 for x in s_list]
    m = min(s_list_int) 
    new_global_par = m - global_par 
  
    lists = split_by(s_list, str(m))
    
    if len(lists) == 0 :
        return add_par([str(m)], new_global_par)
    elif len(lists) == 1:
        l = solve(lists[0], new_global_par) 
        new_m = add_par([str(m)], new_global_par) 
        if int(s_list[0]) % 10 == str(m) : l.insert(0, new_m) 
        else : l.append(new_m) 
        return l
    elif len(lists) == 2:
        l1= solve(lists[0], new_global_par) 
        l2= solve(lists[1], new_global_par) 
        new_m = add_par([str(m)], new_global_par) 
        l = l1 + new_m + l2 
        return l 

def flatten(l):
    result= [] 
    for i in l : 
        if isinstance(i, list):
            for j in i :
                result.append(j) 
        else : result.append(i) 
    
    return result 

def solver(s_list):
    s_list2 = solve(s_list) 
    index= 0
    for i in range(len(s_list2)):
        if '(' in s_list2[i] or ')' in s_list2[i]  : continue 
        s_list2.pop(i)
        s_list2.insert(i, s_list[index]) 
        index += 1

    l= flatten(s_list2)  
    l = ''.join(i for i in l) 
    return l 


T = int(input() )
for i in range(1, T+1):
    s = str(input() )
    s = expand(s)
    s = solver(s) 
    print(s) 

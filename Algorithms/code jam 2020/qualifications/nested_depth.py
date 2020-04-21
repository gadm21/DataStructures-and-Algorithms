
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
    if len(s_list) == 1 : return [m]

    final_list = [] 
    temp_list = []

    for s in s_list : 
        if m in s : 
            if len(temp_list) > 0:
                final_list.append(temp_list) 
                temp_list = []
            final_list.append(m)
        else :
            temp_list.append(s) 
    
    if len(temp_list) > 0 : final_list.append(temp_list) 

    return final_list 


def extract_result ( lists):
    innocent_list = []
    for l in lists:
        if not isinstance(l, list):
            innocent_list.append(l) 
        else:
            another_list = extract_result (l) 
            for ll in another_list : 
                innocent_list.append(ll) 
    return innocent_list


def solve(s_list, global_par = 0 ) :
    s_list_int = [int(x) % 10 for x in s_list]
    m = min(s_list_int) 
    new_global_par = m - global_par 
    
    lists = split_by(s_list, str(m))
    

    result = []
    for l in lists : 
        if isinstance(l, list) :
            r = solve(l, new_global_par)
            result.append(r)
        else : result.append(str(m)) 
    result = add_par(result, new_global_par) 

    return result 

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
    s_list2 = extract_result(s_list2)

    index= 0
    for i in range(len(s_list2)):
        if '(' in s_list2[i] or ')' in s_list2[i]  : continue 
        s_list2.pop(i)
        s_list2.insert(i, s_list[index]) 
        index += 1

    #l= flatten(s_list2)  
    
    l = ''.join(i for i in s_list2) 
    
    return l 


T = int(input() )
for i in range(1, T+1):
    s = str(input() )
    s = expand(s)
    s = solver(s) 
    
    print("Case #{:d}: {:s}".format(i, s))

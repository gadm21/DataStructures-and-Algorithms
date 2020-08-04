def solve(n) :
    for ii in range(1,n+1) :
        
        num=input()
        s=""
        for i in num:
            s=s+(int(i)*"(")+i+(int(i)*")")
        while (')(' in s ) :
            s = s.replace(')(', '')
        print("Case #{:d}: {:s}".format(ii, s))
        


t = int(input()) 
solve(t) 
for i in range(int(input())):
    x,k = map(int,input().split())
    if x*2 <= x*k:
        mini = x*2 
    elif x%2!=0:
        mini = x*(x+1)
    else:
        mini = x*(x+2)
    
    maxi = (x*k)*(x*k-1)

    print(mini,maxi)

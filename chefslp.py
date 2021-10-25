for i in range(int(input())):
    n,l,x = map(int,input().split())
    r = n-l
    pairs = min(l,r)
    total_cost = pairs*x
    print(total_cost)

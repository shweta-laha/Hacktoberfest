# cook your dish here
t=int(input())
for kk in range(t):
    n=int(input())
    l=[]
    for y in range(n):
        spv=input().split()
        s=int(spv[0])
        p=int(spv[1])
        v=int(spv[2])
        inc=(p//(s+1))*v
        l.append(inc)
    print(max(l))

#k=7
x=list(input())
i=len(x)
for t in range(i):
    y=int(ord(x[t])-7)
    y=chr(y)
    print(y,end="")
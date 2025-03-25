n=int(input())
for i in range(n):
    x=input().split()
    x[0]="".join(reversed(x[0]))
    x[1]="".join(reversed(x[1]))
    y=int(x[0])+int(x[1])
    y=str(y)
    y="".join(reversed(y))
    print(int(y))
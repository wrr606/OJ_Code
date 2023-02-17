import math
n=int(input())
for i in range(n):
    x=input().split()
    x=list(map(int,x))
    y=0
    for j in range(len(x)):
        for a in range(len(x)):
            if j==a:
                continue
            if y<math.gcd(x[j],x[a]):
                y=math.gcd(x[j],x[a])
    print(y)
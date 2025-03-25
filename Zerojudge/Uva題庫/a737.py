import math
n=int(input())
for i in range(n):
    x=input().split()
    x=list(map(int,x))
    fristnum=x[0]
    del x[0]
    x.sort()
    if(fristnum%2==0):
        y=(x[int(len(x)/2)]+x[int(len(x)/2-1)])/2
    elif(fristnum%2!=0):
        y=x[int((len(x)-1)/2)]
    counter=0
    for j in range(len(x)):
        counter+=abs(y-x[j])
    print(int(counter))
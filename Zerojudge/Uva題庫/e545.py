counter=int(input())
for a in range(counter):
    n=input()
    x1=bin(int(n))
    b1=0
    for i in x1:
        if(i=='1'):
            b1+=1
    x2=list(n)
    b2=0
    for i in x2:
        con=bin(int(i))
        for j in con:
            #print(j)
            if(j=='1'):
                b2+=1
    #print(n,b1,b2)
    print(b1,b2)
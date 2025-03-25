while 1:
    n=int(input())
    if n==0:
        break
    n=list(bin(n))
    counter=0
    del n[0]
    del n[0]
    for i in n:
        if i=='1':
            counter+=1
    print("The parity of ",end='')
    for i in n:
        print(i,end='')
    print(" is",counter,"(mod 2).")
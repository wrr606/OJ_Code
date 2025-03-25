nu=int(input())
fibnum={}
fibnum[1]=1
fibnum[2]=2
for f in range(3,45):
    fibnum[f]=fibnum[f-1]+fibnum[f-2]
for con in range(nu):
    dec=int(input())
    dec1=dec
    for i in range(dec+1):
        x=fibnum[i+1]
        if(dec/x<1):
            break
    arr=[0]*i
    arr[0]=1
    #print(arr)
    dec-=fibnum[i]
    counter=1
    #print(dec)
    if(i==1):
        print("1 = 1 (fib)")
        continue
    for j in range(i-1,0,-1):
        #print("+++")
        if(dec==0):
            print(dec1,"= ",end='')
            for k in range(i):
                print(arr[k],end='')
            print(" (fib)")
            break
        if(counter==1):
            counter=0
            continue
        x=fibnum[j]
        if(dec/x>=1):
            dec-=x
            arr[i-j]=1
            counter=1
        if(dec==0):
            print(dec1,"= ",end='')
            for k in range(i):
                print(arr[k],end='')
            print(" (fib)")
            break
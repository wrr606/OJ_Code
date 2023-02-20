while 1:
    try:
        x=list(map(int,input().split()))
        if x[0]==-1 or x[1]==-1:
            break
        x.sort()
        print(min(abs(x[0]+100-x[1]),x[1]-x[0]))
    except:
        break
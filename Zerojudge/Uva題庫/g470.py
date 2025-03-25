while 1:
    try:
        x=list(map(int,input().split()))
        if x[0]==0 and x[1]==0:
            break
        print(x[1]//5-x[0]//5+1)
    except:
        break
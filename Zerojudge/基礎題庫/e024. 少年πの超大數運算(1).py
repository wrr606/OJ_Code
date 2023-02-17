while 1:
    try:
        x=list(map(int,input().split()))
        if not(x[0] or x[1]):
            break
        print(x[0]**x[1])
    except:
        break
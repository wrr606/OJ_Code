while 1:
    try:
        x=input().split()
        x=list(map(int,x))
        print(abs(x[1]-x[0]))
    except:
        break
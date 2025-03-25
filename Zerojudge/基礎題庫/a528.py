while 1:
    try:
        j=int(input())
        i=0
        x=list()
        while 1:
            x.append(int(input()))
            i=i+1
            if i==j:
                break
        x.sort()
        len1=len(x)
        for o in range(len1):
            print(x[o])
    except:
        break
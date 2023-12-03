while 1:
    try:
        x=int(input())
        z=1
        y=1
        q=[]
        while 1:#x/2=z...y
            if z==0:
                break
            z=x//2
            y=x%2
            q.append(y)
            x=z
        q.reverse()
        for i in q:
            print(i,end='')
        print("")
    except:
        break
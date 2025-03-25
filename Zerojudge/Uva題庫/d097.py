while 1:
    try:
        x=input().split()
        x=list(map(int,x))
        n=x[0]
        del x[0]
        y=[]
        for i in range(n-1):
            y=y+[abs(x[i+1]-x[i])]
        y.sort()
        bool=0
        counter=0
        for i in range(1,n):
            if(y[counter]!=i):
                bool=1
            counter+=1
        if(bool==1):
            print("Not jolly")
        else:
            print("Jolly")
    except:
        break
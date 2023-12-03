while 1:
    try:
        x=list(input())
        y={}
        x=list(map(ord,x))
        x.sort()
        for i in range(len(x)):
            y[x[i]]=0
        for i in range(len(x)):
            y[x[i]]+=1
        min=9999999999
        counter=len(y)
        #print(y)
        while counter!=0:
            for i in y:
                if(min>=y[i]):
                    min=y[i]
                    key=i
            print(key,min)
            min=999999999
            del y[key]
            counter-=1
    except:
        break
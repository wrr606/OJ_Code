while 1:
    z=input().split()
    z=list(map(int,z))
    if(z[0]==0 and z[1]==0):
        break
    if z[0]>=z[1]:
        x=list(str(z[0]))
        y=list(str(z[1]))
    else:
        x=list(str(z[1]))
        y=list(str(z[0]))
    x=list(map(int,x))
    y=list(map(int,y))
    if(len(x)>=len(y)):#99999
        boolnum=len(y)    #11
    else:
        boolnum=len(x)#1010
    counter=0
    for i in range(boolnum):#0 1 2
        if x[len(x)-1-i]+y[len(y)-1-i]>=10:#555 999
            counter+=1
            #x[len(x)-1-i]=x[len(x)-1-i]+y[len(y)-i]-10
            
            x[len(x)-2-i]+=1
    if(x[len(x)-2-i]>=10):
        for j in range(len(x)-1-i):#0 1 2
            if x[len(x)-2-i-j]>=10:
                counter+=1
                if len(x)-3-i-j!=-1:
                    x[len(x)-3-i-j]+=1
                else:
                    break
    if(counter==0):
        print("No carry operation.")
    elif(counter>1):
        print(counter,"carry operations.")
    elif(counter==1):
        print(counter,"carry operation.")
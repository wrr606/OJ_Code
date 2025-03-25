arr=[[] for a in range(200)]
lsit=[str]
len1={}
counter=0
try:
    while 1:
        x=input()
        arr[counter]=x
        lsit=list(x)
        len1[counter]=len(lsit)
        counter+=1
except:
    maxlen=0
    for i in range(counter):
        if(maxlen<len1[i]):
            maxlen=len1[i]
    for i in range(maxlen):
        for j in range(counter-1,-1,-1):
            #print("\ni=",i)
            #print("len1=",len1[j])
            if(i>=len1[j]):#0 1
                print(" ",end='')#1 0
            else:
                print(arr[j][i],end='')#1 0
        print()
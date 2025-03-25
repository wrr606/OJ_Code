n=int(input())
for p in range(n):
    inp=input()
    ture=input()
    print("Case ",p+1,": ",sep='',end='')
    bool=0
    y=list(inp.replace(" ",""))
    inp=list(inp)
    x=list(ture.replace(" ",""))
    ture=list(ture)
    counter1=0
    counter2=0
    #print(x,y,inp,ture)
    if len(x)!=len(y):
        print("Wrong Answer")
        continue
    for i in range(len(x)):
        if x[i]!=y[i]:
            bool=1
            break
    if bool==1:
        print("Wrong Answer")
        continue
    for i in range(len(ture)):
        if ture[i]==' ':
            counter1+=1
    for i in range(len(inp)):
        if inp[i]==' ':
            counter2+=1
    if counter1!=counter2:
        bool=2
    if bool==1:
        print("Wrong Answer")
    elif bool==2:
        print("Output Format Error")
    else:
        print("Yes")
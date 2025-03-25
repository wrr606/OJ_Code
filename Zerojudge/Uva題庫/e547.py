t=int(input())
for o in range(t):
    y=input().split('=')
    counter0=""
    counter1=""
    x=0
    k=0
    b=0
    for i in range(0,len(y[0])):
        if b:
            b=0
            continue
        if y[0][i]=='x':
            if counter0=="-" or counter0=="" or counter0=="+":
                counter0+='1'
            x-=int(counter0)
            if i!=len(y[0])-1:
                counter0=y[0][i+1]
                b=1
            else:
                counter0="0"
        elif  y[0][i]=='+' or y[0][i]=='-':
            k+=int(counter0)
            if i!=len(y[0])-1:
                counter0=y[0][i]
        else:
            counter0+=y[0][i]
    #2x-4+5x+300    98x
    k+=int(counter0)
    b=0
    #print(counter0,k,x)
    for i in range(0,len(y[1])):
        if b:
            b=0
            continue
        if y[1][i]=='x':
            if counter1=="-" or counter1=="" or counter1=="+":
                counter1+='1'
            x+=int(counter1)
            if i!=len(y[1])-1:
                counter1=y[1][i+1]
                b=1
            else:
                counter1="0"
        elif  y[1][i]=='+' or y[1][i]=='-':
            k-=int(counter1)
            if i!=len(y[1])-1:
                counter1=y[1][i]
        else:
            counter1+=y[1][i]
    #2x-4+5x+300    98x
    k-=int(counter1)
    if x==0 and k==0:
        print("IDENTITY")
    elif x==0:
        print("IMPOSSIBLE")
    else:
        print(k//x)
#2x-4+5x+300    98x
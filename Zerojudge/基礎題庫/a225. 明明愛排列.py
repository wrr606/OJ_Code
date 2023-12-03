while 1:
    try:
        len=int(input())
        x=input().split()
        x=list(map(int,x))
        x.sort(reverse=1)
        w=0
        for i in range(len):#38 106 98 26 13
            for j in range(len-i-1):
                if(x[j]%10>x[j+1]%10):
                    w=x[j]
                    x[j]=x[j+1]
                    x[j+1]=w
        for a in range(len):
            print(x[a],end=' ')
        print('\n')
    except:
        break
while 1:
    try:
        x=input()
        x=list(map(int,input().split()))
        x.sort()
        for i in x:
            print(i,'',end='')
        print()
    except:
        break
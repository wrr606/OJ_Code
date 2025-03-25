while 1:
    try:
        x=int(input())
        equation=list(map(int,input().split()))
        counter=0
        count=0
        for i in range(len(equation)-2,-1,-1):
            counter+=pow(x,count)*equation[i]*(count+1)
            count+=1
        print(counter)
    except:
        break
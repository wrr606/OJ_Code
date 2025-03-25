while 1:
    try:
        n=int(input())
        for o in range(n):
            divisor={}
            x=input()
            if x=="1":
                print(1)
                continue
            lenght=len(x)
            x=int(x)
            for i in range(9,1,-1):
                if x%i==0:
                    divisor[i]=1
            #print(divisor)
            reset=x
            y=""
            while x!=1:
                counter=0
                n=1
                for i in divisor:
                    if x%i==0:
                        y+=str(i)
                        x//=i
                        n=0
                        counter+=1
                        break
                if n:
                    x=reset
                    y=""
                    break
            if y!="":
                print("".join(reversed(y)))
            else:
                print(-1)
    except:
        break
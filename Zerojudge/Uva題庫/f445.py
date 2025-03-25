while 1:
    try:
        n=input()
        if(n=="0"):
            break
        print("Original number was",n)
        temp=""
        counter=0
        list1=[]
        while n not in list1:
            counter+=1
            list1.append(n)
            n=sorted(n)
            n=''.join(n)
            n0=''.join(reversed(n))
            print(int(n0),"-",int(n),"= ",end="")
            n=str(int(n0)-int(n))
            print(n)
        print("Chain length",counter)
    except:
        break
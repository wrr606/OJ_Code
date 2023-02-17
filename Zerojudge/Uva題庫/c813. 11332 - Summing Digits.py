while 1:
    try:
        x=input()
        if x=="0":
            break
        lenght=len(x)
        while(lenght!=1):
            counter=0
            for i in x:
                counter+=int(i)
            x=str(counter)
            lenght=len(x)
        print(x)
    except:
        break
dict_123={1:"one",2:"two",3:"three"}
while 1:
    try:
        n=int(input())
        for o in range(n):
            x=input()
            if len(x)==3:
                counter1=0
                counter2=0
                for i in range(3):
                    if x[i]==dict_123[1][i]:
                        counter1+=1
                    if x[i]==dict_123[2][i]:
                        counter2+=1
                if counter1>counter2:
                    print(1)
                else:
                    print(2)
            else:
                print(3)
    except:
        break
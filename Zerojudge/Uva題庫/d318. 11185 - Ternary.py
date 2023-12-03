while 1:
    try:
        x=int(input())
        if x<0:
            break
        elif x==0:
            print(0)
            continue
        y=""
        while x!=0:
            #print(x%3)
            y+=str(x%3)
            x//=3
        print(''.join(reversed(y)))
    except:
        break
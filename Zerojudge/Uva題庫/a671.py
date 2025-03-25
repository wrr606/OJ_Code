while 1:
    try:
        n=int(input())
        p=int(input())
        print(int(pow(p,1/n)+0.0001))
    except:
        break
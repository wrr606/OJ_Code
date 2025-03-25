while 1:
    try:
        a,b = list(map(int,input().split()))
        print("Ok!" if a == 0 or (b != 0 and a % b == 0) else "Impossib1e!")
    except:
        break
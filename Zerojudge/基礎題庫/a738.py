import math
while 1:
    try:
        n=input()
        n=n.split()
        print(math.gcd(int(n[0]),int(n[1])))
    except:
        break
def is_prime(x):
    for i in range(2,int(x ** 0.5)+1):
        if x % i == 0:
            return 0
    return 1

while 1:
    try:
        x=input()
        emirp=''.join(reversed(x))
        x=int(x)
        emirp=int(emirp)
        bool=0
        if is_prime(x)==0:
            print(x,"is not prime.")
        else:

            if x==emirp:
                print(x,"is prime.")
            elif is_prime(emirp)==1:
                print(x,"is emirp.")
            else:
                print(x,"is prime.")
    except:
        break
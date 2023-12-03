def f91(n):
    if n>=101:
        return n-10
    else:
        return f91(f91(n+11))

while 1:
    try:
        x=int(input())
        if x==0:
            break
        print("f91(",x,")"," = ",f91(x),sep='')
    except:
        break
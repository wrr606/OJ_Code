i=int(input())
for t in range(i):
    x=1
    x=input()
    y=list(x.split())
    num1=int(y[0])
    num2=int(y[1])
    num3=int(y[2])
    num4=int(y[3])
    d1=num2-num1
    d2=num3-num2
    r1=int(num2/num1)
    r2=int(num3/num2)
    if d1==d2:#1 2 3 4
        print("{} {} {} {} {}".format(num1,num2,num3,num4,num4+d1))
    elif r1==r2:#1 2 4 8
        print("{} {} {} {} {}".format(num1,num2,num3,num4,num4*r1))
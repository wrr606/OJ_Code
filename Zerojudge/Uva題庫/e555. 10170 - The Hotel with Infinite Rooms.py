import math

while 1:
    try:
        x=list(map(int,input().split()))
        y=(math.sqrt(1-4*x[0]+4*pow(x[0],2)+8*x[1])-1)/2
        if y-int(y)==0:
            y=int(y)
        else:
            y=int(y)+1
        print(y)
    except:
        break
def x(num):
    if(num==1):
        return 1
    elif(num%2==0):
        return x(num/2)
    else:
        return x(num-1)+x(num+1)

y=int(input())
print(x(y))
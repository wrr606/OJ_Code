def xxx(n):
    if(n>=10000000):#123456789123456
        xxx(n//10000000)#12345678   #1
        print("kuti ",end='')#12345678
        n%=10000000#12345678
    if(n>=100000):
        xxx(n//100000)
        print("lakh ",end='')
        n%=100000
    if(n>=1000):
        xxx(n//1000)
        print("hajar ",end='')
        n%=1000
    if(n>=100):
        xxx(n//100)#
        print("shata ",end='')
        n%=100
    if(n!=0):
        print(n," ",sep='',end='')

counter=0
while 1:
    try:
        counter+=1
        x=int(input())
        print(counter,". ",sep='',end='')
        
        if(x):
            xxx(x)
        else:
            print('0')
        print('\n')
    except:
        break
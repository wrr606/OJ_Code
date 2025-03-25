#d219. 00374 - Big Mod

#快速冪
def qpow(x,y,z):
    ans=1
    while y>0:
        if y&1==1:
            ans*=x%z
        x*=x%z
        y>>=1
    return ans%z

while 1:
    try:
        x=list(map(int,input().split()))
        print(qpow(x[0],x[1],x[2]))
    except:
        break
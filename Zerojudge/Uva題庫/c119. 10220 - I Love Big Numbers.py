#c119. 10220 - I Love Big Numbers
import math
while 1:
    try:
        n=int(input())
        n=math.factorial(n)
        ans=0
        for i in str(n):
            ans+=int(i)
        print(ans)
    except:
        break
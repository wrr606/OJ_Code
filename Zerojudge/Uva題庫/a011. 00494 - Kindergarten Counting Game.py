import re
while 1:
    try:
        x=input()
        x=re.split(r'\W+',x)
        y=len(x)
        if(x[-1]==''):
            y-=1
        print(y)
    except:
        break
#a263. 日期差幾天
from datetime import datetime

while 1:
    try:
        x=list(map(int,input().split()))
        y=list(map(int,input().split()))
        date1=datetime(x[0],x[1],x[2])
        date2=datetime(y[0],y[1],y[2])
        print(abs((date1-date2).days))
    except:
        break
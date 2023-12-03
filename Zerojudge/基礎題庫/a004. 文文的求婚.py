x=1
try:
    while 1:
        x=int(input())
        if x%4==0 and x%100!=0:
            print("閏年")
        elif x%400==0:
            print("閏年")
        else:
            print("平年")
except:
    pass
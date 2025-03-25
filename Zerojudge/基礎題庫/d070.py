#d070. 格瑞哥里的煩惱 (0 尾版)
x=1
while 1:
    try:
        x=int(input())
        if(x==0):
            break
        if x%4==0 and x%100!=0:
            print("a leap year")
        elif x%400==0:
            print("a leap year")
        else:
            print("a normal year")
    except:
        break
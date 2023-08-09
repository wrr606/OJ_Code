#d067. 格瑞哥里的煩惱 (1 行版)
x=1
x=int(input())
if x%4==0 and x%100!=0:
    print("a leap year")
elif x%400==0:
    print("a leap year")
else:
    print("a normal year")
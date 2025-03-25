#d069. 格瑞哥里的煩惱 (t 行版)
n=int(input())
for i in range(n):
    x=int(input())
    if x%4==0 and x%100!=0:
        print("a leap year")
    elif x%400==0:
        print("a leap year")
    else:
        print("a normal year")
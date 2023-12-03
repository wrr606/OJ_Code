#d072. 格瑞哥里的煩惱 (Case 版)
n=int(input())
for i in range(1,n+1):
    x=int(input())
    print(f"Case {i}: ",end="")
    if x%4==0 and x%100!=0:
        print("a leap year")
    elif x%400==0:
        print("a leap year")
    else:
        print("a normal year")
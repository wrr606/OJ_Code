x=input().split()
x=list(map(int,x))
y=x[0]*60+x[1]
if(450<=y and y<1020):
    print("At School")
else:
    print("Off School")
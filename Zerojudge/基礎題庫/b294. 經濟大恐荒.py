n=int(input())
x=input().split()
x=list(map(int,x))
num=0
for i in range(1,n+1):
    num+=i*x[i-1]
print(num)
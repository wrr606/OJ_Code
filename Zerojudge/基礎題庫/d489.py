#d489. 伏林的三角地
x=list(map(int,input().split()))
a=x[0]
b=x[1]
c=x[2]
print(int(((a+b+c)/2)*((a+b+c)/2-a)*((a+b+c)/2-b)*((a+b+c)/2-c)))
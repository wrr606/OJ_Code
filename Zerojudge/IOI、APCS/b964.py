n=int(input())
x=list(map(int,input().split()))
x.sort()
mid=-1
for i in range(len(x)):
    print(x[i],end=' ')
    if x[i]<60:
        mid=i
print()
if mid!=-1:
    print(x[mid])
else:
    print("best case")
if mid!=len(x) and mid+1<len(x):
    print(x[mid+1])
else:
    print("worst case")
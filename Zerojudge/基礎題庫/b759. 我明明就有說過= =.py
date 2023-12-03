x=list(input())
len1=len(x)
for i in x:
    x=x+[i]
for i in range(len1):
    for j in range(i,len1+i):
        print(x[j],end='')
    print()
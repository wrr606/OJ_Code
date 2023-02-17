n=int(input())
for p in range(n):
    url={}
    for o in range(10):
        x=input().split()
        x[1]=int(x[1])
        url[x[0]]=x[1]
    max=0
    for i in url:
        if url[i]>max:
            max=url[i]
    print("Case #",p+1,":",sep='')
    for i in url:
        if url[i]==max:
            print(i)
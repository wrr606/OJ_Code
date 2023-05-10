arr=list(map(int,input().split()))
data=[]
if 0 not in arr:
    print(arr)
elif 0 in arr:
    for i in arr:
        data.append(i)
        if i==0:
            data.append(0)
        if len(arr)==len(data):
            print(data)
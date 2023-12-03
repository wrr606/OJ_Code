x=input()
len1=len(x)
if len1%2==0:#4
    for i in range(0,len1):#0 1 2 3
        if x[i]!=x[len1-1-i]:
            print("no")
            break
        if i==len1-1:
            print("yes")
else:#5
    for j in range(0,len1):#0 1 2 3 4
        if x[j]!=x[len1-1-j]:
            print("no")
            break
        if j==len1-1:
            print("yes")
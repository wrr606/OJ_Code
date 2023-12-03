a=int(input())
n=0
b=2
while(a!=1):
    n=0
    if a%b==0:
        print(b,end="")
    while a%b==0:
        a=a/b
        n=n+1
    if n>1:
        n=str(n)
        print("^"+n,end="")
        n=int(n)
    if n>=1 and a!=1:
        print(" * ",end="")
    b=b+1
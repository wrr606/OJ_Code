import sys
sys.setrecursionlimit(10000)
def x(n):
    if(n==1):
        return 2
    else:
        return 2*(n-1)+x(n-1)

while 1:
    try:
        n=int(input())
        #1:2    2:4     3:8     4:14
        print(x(n))
    except:
        break
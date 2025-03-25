#e529. 00482 - Permutation Arrays
n=int(input())
b=False
for t in range(n):
    if(b):
        print()
    b=True
    space=input()
    index=list(map(int,input().split()))
    array=input().split()
    dict={}
    for i in range(len(array)):
        dict[index[i]]=array[i]
    for i in range(1,len(array)+1):
        print(dict[i])
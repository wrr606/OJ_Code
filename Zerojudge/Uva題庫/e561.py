n=int(input())
for p in range(n):
    L=int(input())
    len1=input().split()
    len1=list(map(int,len1))
    counter=0
    for i in range(L):
        for j in range(L-i-1):
            if(len1[j]>=len1[j+1]):#bubble sort
                asd=len1[j]
                len1[j]=len1[j+1]
                len1[j+1]=asd
                counter+=1
    print("Optimal train swapping takes",counter,"swaps.")
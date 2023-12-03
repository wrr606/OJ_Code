#d532. 文文的求婚 (三)
a,b=map(int,input().split())
ans=0
for i in range(a,b+1):
    if i%4==0 and i%100!=0:
        ans+=1
    elif i%400==0:
        ans+=1
print(ans)
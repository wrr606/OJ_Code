#a307. NOIP2011 1.数字反转
n=input()
s=""
if(n[0]=='-'):
    s+='-'
    n=n[1:]
for i in range(len(n)-1,-1,-1):
    s+=n[i]
print(int(s))
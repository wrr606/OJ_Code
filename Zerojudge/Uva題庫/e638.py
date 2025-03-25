#e638. 10176 - Ocean Deep! Make it shallow!!
s=""
while 1:
    try:
        n=input()
        s+=n
        if n[-1]=='#':
            s=int(s[:-1],2)%131071
            if s==0:
                print("YES")
            else:
                print("NO")
            s=""
    except:
        break
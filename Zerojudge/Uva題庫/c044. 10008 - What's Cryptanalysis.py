n=int(input())
worddict={'A':0,'B':0,'C':0,'D':0,'E':0,'F':0,'G':0,'H':0,'I':0,'J':0,'K':0,'L':0,'M':0,'N':0,'O':0,'P':0,'Q':0,'R':0,'S':0,'T':0,'U':0,'V':0,'W':0,'X':0,'Y':0,'Z':0}
for i in range(n):
    x=list(input())
    for j in range(len(x)):
        if(ord('z')>=ord(x[j]) and ord(x[j])>=ord('a')):
            worddict[chr(ord(x[j])+(ord('A')-ord('a')))]+=1
        elif(ord('Z')>=ord(x[j]) and ord(x[j])>=ord('A')):
            worddict[x[j]]+=1
for i in range(ord('A'),ord('Z')+1):
    if(worddict[chr(i)]==0):
        del worddict[chr(i)]
for i in range(len(worddict)):
    max=0
    for j in worddict:
        #print(j)
        if(max<worddict[j]):
            max=worddict[j]
            con=j
    del worddict[con]
    print(con,max)
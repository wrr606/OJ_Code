lost=[[0]*51 for i in range(51)]
s=input().split()
s=list(map(int,s))
while 1:
    try:
        inp=input().split()
        x=int(inp[0])
        y=int(inp[1])
        if(inp[2]=='N'):
            dir=0
        elif(inp[2]=='E'):
            dir=3
        elif(inp[2]=='W'):
            dir=9
        elif(inp[2]=='S'):
            dir=6
        ins=list(input())
        for i in range(len(ins)):
            if(ins[i]=='L'):
                dir-=3
            elif(ins[i]=='R'):
                dir+=3
            booln=dir%12
            if(booln==0):
                inp[2]='N'
            elif(booln==3 or booln==-9):
                inp[2]='E'
            elif(booln==9 or booln==-3):
                inp[2]='W'
            else:
                inp[2]='S'
            if(lost[x][y]!=1 and ins[i]=='F'):#在標記位置無法移動
                if(booln==0):
                    y+=1
                elif(booln==3 or booln==-9):
                    x+=1
                elif(booln==9 or booln==-3):
                    x-=1
                else:
                    y-=1
            elif(lost[x][y]==1 and ins[i]=='F'):
                if(booln==0 and y+1<=s[1]):
                    y+=1
                elif((booln==3 or booln==-9) and x+1<=s[0]):
                    x+=1
                elif((booln==9 or booln==-3) and x-1>=0):
                    x-=1
                elif((booln==-6 or booln==6) and y-1>=0):
                    y-=1
            if(x<0 or y<0 or x>s[0] or y>s[1]):
                if(booln==0):
                    y-=1
                elif(booln==3 or booln==-9):
                    x-=1
                elif(booln==9 or booln==-3):
                    x+=1
                else:
                    y+=1
                lost[x][y]=1
                print(x,y,inp[2],"LOST")
                break
            elif(i==len(ins)-1):
                print(x,y,inp[2])
    except:
        break
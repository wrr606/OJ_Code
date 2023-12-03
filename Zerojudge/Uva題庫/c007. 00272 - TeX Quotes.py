import re
counter=0
while 1:
    try:
        x=re.split(r"(\")",input())
        x=list(map(str,x))
        for i in range(len(x)):
            if(x[i]=='\"' and counter%2==0):
                x[i]="``"
                counter+=1
            elif(x[i]=='\"' and counter%2==1):
                x[i]="''"
                counter+=1
        for j in range(len(x)):
            print(x[j],end='')
        print()
    except:
        break
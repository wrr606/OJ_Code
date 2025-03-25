"""
羅馬數字	數目
I	1
V	5
X	10
L	50
C	100
D	500
M	1,000
"""
while 1:
    txt=input()
    if txt=="#":
        break
    x=list(txt.split())
    x1=list(x[0])
    x2=list(x[1])#MM II
    num1=0
    num2=0
    len1=len(x1)
    len2=len(x2)#M 1000 C 100 M 1000 X 0 C 90 V I I I       I
    for i in range(len1):#MCMXCVIII I
        if x1[i]=="I":
            x1[i]=1
        if x1[i]=="V":
            x1[i]=5
        if x1[i]=="X":
            x1[i]=10
        if x1[i]=="L":
            x1[i]=50
        if x1[i]=="C":
            x1[i]=100
        if x1[i]=="D":
            x1[i]=500
        if x1[i]=="M":
            x1[i]=1000
    for i in range(len1-1):
        if x1[i]<x1[i+1]:
            x1[i+1]=x1[i+1]-x1[i]
            x1[i]=0
    for i in range(len1):
        num1=num1+x1[i]
    for j in range(len2):
        if x2[j]=="I":
            x2[j]=1
        if x2[j]=="V":
            x2[j]=5
        if x2[j]=="X":
            x2[j]=10
        if x2[j]=="L":
            x2[j]=50
        if x2[j]=="C":
            x2[j]=100
        if x2[j]=="D":
            x2[j]=500
        if x2[j]=="M":
            x2[j]=1000
    for j in range(len2-1):
        if x2[j]<x2[j+1]:
            x2[j+1]=x2[j+1]-x2[j]
            x2[j]=0
    for j in range(len2):
        num2=num2+x2[j]
    answer=abs(num1-num2)
    if answer==0:
        answer="ZERO"
        print(answer)
        continue
#1997
    four=""
    if answer//1000==0:
        four=""
    if answer//1000==1:
        four="M"
    if answer//1000==2:
        four="MM"
    if answer//1000==3:
        four="MMM"
    if answer//1000==4:
        four="MMMM"
    answer=answer-(answer//1000)*1000
    three=""
    if answer//100==0:
        three=""
    if answer//100==1:
        three="C"
    if answer//100==2:
        three="CC"
    if answer//100==3:
        three="CCC"
    if answer//100==4:
        three="CD"
    if answer//100==5:
        three="D"
    if answer//100==6:
        three="DC"
    if answer//100==7:
        three="DCC"
    if answer//100==8:
        three="DCCC"
    if answer//100==9:
        three="CM"
    answer=answer-(answer//100)*100
    two=""
    if answer//10==0:
        two=""
    if answer//10==1:
        two="X"
    if answer//10==2:
        two="XX"
    if answer//10==3:
        two="XXX"
    if answer//10==4:
        two="XL"
    if answer//10==5:
        two="L"
    if answer//10==6:
        two="LX"
    if answer//10==7:
        two="LXX"
    if answer//10==8:
        two="LXXX"
    if answer//10==9:
        two="XC"
    answer=answer-(answer//10)*10
    one=""
    if answer==0:
        one=""
    if answer==1:
        one="I"
    if answer==2:
        one="II"
    if answer==3:
        one="II"
    if answer==4:
        one="IV"
    if answer==5:
        one="V"
    if answer==6:
        one="VI"
    if answer==7:
        one="VII"
    if answer==8:
        one="VIII"
    if answer==9:
        one="IX"
    print(four+three+two+one)
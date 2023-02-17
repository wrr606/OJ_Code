dict={'A':10,'B':11,'C':12,'D':13,'E':14,'F':15,'G':16,'H':17,'I':34,'J':18,'K':19,'L':20,'M':21,'N':22,'O':35,'P':23,'Q':24,'R':25,'S':26,'T':27,'U':28,'V':29,'W':32,'X':30,'Y':31,'Z':33}
num_list=list(input())
first_num=dict[num_list[0]]
answer1=first_num%10*9+first_num//10
answer2=0
for i in range(1,9):
    j=9-i
    answer2=answer2+(int(num_list[i]))*j
answer0=answer1+answer2+int(num_list[9])
if(answer0%10==0):
    print("real")
elif(answer0%10!=0):
    print("fake")
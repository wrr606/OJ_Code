x=list(input())
counter=0
for i in range(0,len(x)):
    counter+=pow(9,i)*int(x[len(x)-1-i])
print(counter)
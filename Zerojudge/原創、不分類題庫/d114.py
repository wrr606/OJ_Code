from math import factorial
counter=1
for i in range(1,101):
    counter*=factorial(i)
counter=str(counter)
for i in range(len(counter)):
    print(counter[i])
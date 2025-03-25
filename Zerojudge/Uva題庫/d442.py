counter=1
t=int(input())
for j in range(t):
    n=int(input())
    print(f'Case #{counter}: ',end='')
    y=n
    while 1:
        temp=0
        for i in str(n):
            temp+=pow(int(i),2)
        n=temp
        if n==1:
            print(f'{y} is a Happy number.')
            break
        if n==y or n==4:
            print(f'{y} is an Unhappy number.')
            break
    counter+=1
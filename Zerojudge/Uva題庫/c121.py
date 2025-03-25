dp=[0,1,1]
for i in range(2,5001):
	dp.append(dp[i-1]+dp[i])

while 1:
    try:
        x=int(input())
        print("The Fibonacci number for",x,"is",dp[x])
    except:
        break
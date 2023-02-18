dp=[0,1,1]
for i in range(2,200):
	dp.append(dp[i-1]+dp[i])

while 1:
    try:
        x=int(input())
        print(dp[x+1])
    except:
        break
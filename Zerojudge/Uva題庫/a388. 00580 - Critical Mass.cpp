#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main() {
	int n;
	while(cin>>n&&n){
		int dp[32][4]={};
		dp[1][0]=dp[1][1]=1;
		for(int i=2;i<=30;i++){
			dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
			dp[i][1]=dp[i-1][0];
			dp[i][2]=dp[i-1][1];
			dp[i][3]=dp[i-1][3]*2+dp[i-1][2];
		}
		cout<<dp[n][3]<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		vector<vector<unsigned long long int> > dp(n+1,vector<unsigned long long int>(4));
		dp[1][1]=1;
		dp[1][2]=1;
		dp[1][3]=1;
		dp[1][0]=3;
		for(int i=2;i<=n;i++){
			dp[i][2]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
			dp[i][1]=dp[i-1][1]+dp[i-1][2];
			dp[i][3]=dp[i-1][2]+dp[i-1][3];
			dp[i][0]=dp[i][1]+dp[i][2]+dp[i][3];
		}
		cout<<dp[n][0]<<'\n';
	}
}
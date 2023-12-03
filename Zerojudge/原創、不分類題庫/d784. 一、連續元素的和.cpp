#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n){
		while(n--){
			cin>>m;
			vector<int> dp(m+1);
			for(int i=1;i<=m;i++){
				cin>>dp[i];
			}
			int mx=dp[1];
			for(int i=2;i<=m;i++){
				if(dp[i-1]>0)
					dp[i]+=dp[i-1];
				mx=max(mx,dp[i]);
			}
			cout<<mx<<endl;
		}
	}
}
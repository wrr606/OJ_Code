#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		vector<int> a(n+1);
		vector<unsigned long long int> dp(m+1);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=m;j>=0;j--){
				for(int k=1;k<=a[i];k++){
					if(k+j<=m){
						dp[k+j]+=dp[j];
						dp[k+j]%=1000007;
					}
				}
			}
		}
		cout<<dp[m]<<'\n';
	}
}
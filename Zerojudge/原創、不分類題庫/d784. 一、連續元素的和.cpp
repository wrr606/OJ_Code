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
			for(int o=1;o<=m;o++){
				cin>>dp[o];
			}
			int max=dp[1];
			for(int i=2;i<=m;i++){
				if(dp[i-1]>0)
					dp[i]+=dp[i-1];
				if(dp[i]>max)
					max=dp[i];
			}
			cout<<max<<endl;
		}
	}
}
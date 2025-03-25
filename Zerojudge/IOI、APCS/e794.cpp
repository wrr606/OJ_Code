#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<long long int> dp;
	dp.push_back(1);
	dp.push_back(1);
	for(int i=1;i<=45;i++){
		dp.push_back(dp[i-1]+dp[i]);
	}
	int n;
	while(cin>>n&&n){
		cout<<dp[n-1]<<":"<<dp[n]<<endl;
	}
}
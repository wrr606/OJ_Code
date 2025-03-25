#include<bits/stdc++.h>
using namespace std;

unsigned long long int dp[99999]={},p[99999]={};
int w,m,wi,n;

int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n){
		while(n--){
			w=0;
			cin>>m;
			for(int o=1;o<=m;o++){
				cin>>p[o];
				w+=p[o];
			}
			wi=w/2;
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=m;i++){
				for(int j=wi;j>=p[i];j--){
					dp[j]=max(dp[j],p[i]+dp[j-p[i]]);
					//cout<<j<<endl;
				}
			}
			//cout<<"w:"<<w<<endl;
			cout<<w-dp[wi]*2<<'\n';
		}
	}
}
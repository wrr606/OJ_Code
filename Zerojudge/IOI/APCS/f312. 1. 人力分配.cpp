#include<bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x[3]={},y[3]={},n,y1=0,y2;
	cin>>x[0]>>x[1]>>x[2]>>y[0]>>y[1]>>y[2]>>n;
	y1=x[2];
	y2=y[0]*n*n+y[1]*n+y[2];
	int max=y1+y2;
	for(int i=1;i<=n;i++){
		y1=x[0]*i*i+x[1]*i+x[2];
		y2=y[0]*(n-i)*(n-i)+y[1]*(n-i)+y[2];
		if(max<y1+y2)
			max=y1+y2;
	}
	cout<<max<<'\n';
}
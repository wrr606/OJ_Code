#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	while(cin>>n&&n){
		vector<int> x(n);
		for(int i=0;i<n;i++)
			cin>>x[i];
		sort(x.begin(),x.end());
		for(auto i:x)
			cout<<i<<" ";
		cout<<'\n';
	}
}
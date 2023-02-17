#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	if(a%2!=b%2){
		return a%2<b%2;
	}
	else{
		if(a%2&&b%2){
			return a>b;
		}
		else{
			return a<b;
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		vector<int> x(n);
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		sort(x.begin(),x.end(),cmp);
		for(auto i:x){
			cout<<i<<" ";
		}
		cout<<'\n';
	}
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		map<int,int> x;
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			x[temp]=i+1;
		}
		for(int i=0;i<m;i++){
			cin>>temp;
			cout<<x[temp]<<endl;
		}
	}
}
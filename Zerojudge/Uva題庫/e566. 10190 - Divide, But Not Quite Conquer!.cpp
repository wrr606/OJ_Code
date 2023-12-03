#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	while(cin>>n&&cin>>m){
		if(m==0||n==0||n==1||m==1){
			cout<<"Boring!\n";
			continue;
		}
		vector<int> x;
		while(n%m==0){
			x.push_back(n);
			n/=m;
		}
		if(n==1){
			for(int i=0;i<x.size();i++){
				cout<<x[i]<<" ";
			}
			cout<<"1";
		}
		else{
			cout<<"Boring!";
		}
		cout<<endl;
	} 
}
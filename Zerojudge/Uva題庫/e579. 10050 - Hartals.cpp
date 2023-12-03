#include<iostream>
using namespace std;
int main(){
	int limit[9999]={},con=0,booln;
	for(int i=6;i<=9999;i+=7){
		limit[con]=i;
		con++;
	}
	int t;
	cin>>t;
	for(;t>=1;t--){
		int n,p,counter=0;
		cin>>n>>p;
		int hi[p]={},x[9999]={0};
		for(int i=0;i<p;i++){
			cin>>hi[i];
			for(int j=hi[i];j<=n;j+=hi[i]){
				booln=0;
				for(int h=0;limit[h]<n;h++){
					if(j==limit[h] || x[j]==1){
						booln=1;
						break;
					}
				}
				if(booln==0&&j%7!=0){
					counter++;
					x[j]=1;
				}
			}
		}
		cout<<counter<<endl;
	}
}
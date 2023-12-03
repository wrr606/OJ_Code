#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long int n;
	while(cin>>n){
		if(n==0)
			break;
		long long int x[n]={};
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n-1;i++){
			x[i+1]=abs(x[i]*x[i+1])/__gcd(x[i],x[i+1]);
		}
		cout<<x[n-1]<<endl;
	}
}
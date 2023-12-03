#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	while(cin>>n&&cin>>k){
		int counter=n;
		while(n>=k){
			counter+=n/k;
			n=n%k+n/k;
		}
		cout<<counter<<endl;
	}
}
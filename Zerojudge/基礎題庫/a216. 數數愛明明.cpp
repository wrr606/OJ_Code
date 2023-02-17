#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
	long long int fn,fn1,n,gn,gn1;//f(n) = n + f(n-1)
	while(cin>>n){//g(n) = f(n) + g(n-1)
		fn1=0;
		gn1=0;
		for(int i=1;i<=n;i++){
			fn=i+fn1;
			fn1=fn;
			gn=fn+gn1;
			gn1=gn;
		}
		cout<<fn<<" "<<gn<<endl;
	}
}
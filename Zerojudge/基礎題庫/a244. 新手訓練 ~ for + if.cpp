#include<iostream>
#include<math.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(){
	long long int n,a,b,c;
	cin>>n;
	for(n;n>0;n--){
		cin>>a>>b>>c;
		if(a==1)
			cout<<b+c;
		else if(a==2)
			cout<<b-c;
		else if(a==3)
			cout<<b*c;
		else
			cout<<b/c;
		cout<<endl;
	}
}
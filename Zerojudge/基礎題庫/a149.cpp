#include<iostream>
#include<math.h>
#include<string.h>
//#include<string.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char a[9999]={};
	int ans;
	for(int i=0;i<n;i++){
		ans=1;
		cin>>a;
		for(int j=0;j<strlen(a);j++){
			//cout<<(int)a[j]<<"+++"<<endl;
			ans*=(int)a[j]-48;
		}
		cout<<ans<<endl;
	}
}
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			cout<<"_";
		} 
		for(int a=1;a<=i;a++){
			cout<<"*";
		}
		cout<<endl;
	}
}
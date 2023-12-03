#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int main(){
	char x[9999]={};
	cin>>x;
	cout<<x[0];
	for(int i=1;i<strlen(x);i++){
		cout<<"-"<<x[i];
	}
}
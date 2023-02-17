#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int main(){
	string x,y;
	cin>>y;
	getline(cin,x);
	for(int i=1;i<=x.length();i++){
		if(x[i]==' '){
			cout<<" "<<y<<" ";
		}
		else{
			cout<<x[i];
		}
	}
}
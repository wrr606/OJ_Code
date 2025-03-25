#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int main(){
	string x;
	getline(cin,x);
	cout<<(int)x[0];
	for(int i=1;i<x.length();i++){
		cout<<"_"<<(int)x[i];
	}
}
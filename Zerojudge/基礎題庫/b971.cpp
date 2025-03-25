#include<iostream>
using namespace std;
int main(){
	int a1,a99,d;
	cin>>a1>>a99>>d;
	if(a1>a99){
		for(int i=a1;i>=a99;i+=d){
			cout<<i<<" ";
		}
	}
	else if(a1<a99){
		for(int i=a1;i<=a99;i+=d){
			cout<<i<<" ";
		}
	}
	else if(a1==a99){
		cout<<a1;
	}
}
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x[n]={};
	int h=0,h1=0,h2=0;
	for(int i=n-1;0<=i;i--){
		cin>>x[i];
		if(x[i]%3==0){
			h=h+1;
		}
		else if(x[i]%3==1){
			h1=h1+1;
		}
		else if(x[i]%3==2){
			h2=h2+1;
		}
	}
	cout<<h<<" "<<h1<<" "<<h2;
}
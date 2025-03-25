#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int main(){
	int n,num=0;
	while(cin>>n){
		num=0;
		if(n==0)
			break;
		//1 1		2 5		3 14		4 30	
		for(int i=n;i>1;i--){
			num+=i*i;
		}
		cout<<num+1<<endl;
	}
}
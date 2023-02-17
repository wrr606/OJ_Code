#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	
	while(cin>>n){
		int x[n]={},num=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			num=num+x[i];
		}
		if((float)num/n>59){
			cout<<"no\n";
		}
		else{
			cout<<"yes\n";
		}
	}
}
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main() {
	long long int x,y,i;
	while(cin>>x>>y){
		if(y==0){
			cout<<"Go Kevin!!\n";
			continue;
		}
		for(i=1;i<=x;i+=y){
			if(i==x){
				cout<<"Go Kevin!!\n";
				break;
			}
		}
		if(i!=x)
			cout<<"No Stop!!\n";
	}
}
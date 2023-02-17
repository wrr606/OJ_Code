#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int main(){
	string n;
	while(cin>>n){
		cout<<(char)(n[0]+('A'-'a'));
		for(int i=1;i<=n.length();i++){
			cout<<n[i];
		}
		cout<<endl;
	}
}
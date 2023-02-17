#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n<0){
			cout<<-1;
			return 0;
		}
		else{
			printf("%o\n",n);
		}
	}
}
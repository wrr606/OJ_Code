#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n&&n){
		int counter=0;
		cout<<n<<" : ";
		for(int i=2;n!=1;i+=(i==2?1:2)){
			if(n%i==0){
				counter++;
				while(n%i==0){
					n/=i;
				}
			}
		}
		cout<<counter<<endl;
	}
}
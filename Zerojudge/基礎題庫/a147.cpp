#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n=1;
	while(n!=0){
		cin>>n;
		for(int i=1;i<n;i++){
			if(i%7!=0){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
}
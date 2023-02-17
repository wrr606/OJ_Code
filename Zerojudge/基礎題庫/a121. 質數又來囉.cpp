#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
	int max,min;
	while(cin>>min>>max){
	int counter=0,boolnum=0;
	for(int j=min;j<=max;j++){
		boolnum=0;
		for(int i=2;i<=sqrt(j);i+=(i==2?1:2)){
			if(j%i==0){
				boolnum=1;
				break;
			}
		}
		if(boolnum==0&&j!=0&&j!=1){
			counter++;
		}
	}
	cout<<counter<<endl;
	}
	
}
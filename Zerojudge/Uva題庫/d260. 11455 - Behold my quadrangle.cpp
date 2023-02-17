#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,x[4]={};
	cin>>n;
	for(n;n>=1;n--){
		for(int i=0;i<4;i++){
			cin>>x[i];
		}
		sort(x,x+4);
		if(x[0]==x[1]&&x[1]==x[2]&&x[2]==x[3]){
			cout<<"square\n";
		}
		else if(x[0]==x[1]&&x[2]==x[3]){
			cout<<"rectangle\n";
		}
		else if(x[3]<x[0]+x[1]+x[2]){
			cout<<"quadrangle\n";
		}
		else{
			cout<<"banana\n";
		}
	}
}
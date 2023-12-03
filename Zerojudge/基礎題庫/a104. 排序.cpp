#include<iostream>
#include<math.h>
#include<string.h>
//#include<string.h>
using namespace std;
int main(){
	int n;
	while (cin>>n){
		int x[n]={},y[n]={};
		for(int i=0;i<=n-1;i++){
			cin>>x[i];
		}
		int couter;
		for(int j=n-1;0<=j;j--){//7 9 0 4 1 8		0 0 0 0 0 0
			for(int a=0;a<=n-1;a++){
				if(x[a]>=y[j]){
					y[j]=x[a];
					couter=a;
				}
			}
			x[couter]=-1;
		}
		for(int o=0;o<=n-1;o++){
			cout<<y[o]<<" ";
		}
		cout<<endl;
	}
}
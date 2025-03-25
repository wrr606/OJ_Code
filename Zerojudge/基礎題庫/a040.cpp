#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int min,max;
	cin>>min>>max;
	int j,k,num,u,x=0;
	for(int i=min;i<=max;i++){
		j=i;
		k=0;
		num=0;
		u=i;
		while(j!=0){
			k++;
			j=j/10;//100 999
		}
		for(int l=k;l>0;l--){//3 2 1
			num=num+pow((int)(u/pow(10,l-1)),k);// 153 53
			u=u-pow(10,l-1)*(int)(u/pow(10,l-1));
		}
		if(num==i){
			cout<<i<<" ";
			x=1;
		}
	}
	if(x==0){
		cout<<"none";
	}
}
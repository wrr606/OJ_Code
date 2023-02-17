#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int x[3]={};
	while(cin>>x[0]>>x[1]>>x[2]){
		char y[3]={'A','B','C'};
		//select sort
		for(int i=0;i<3;i++){
			long long int min_pointer,min=x[i];
			for(int j=i;j<3;j++){
				if(min>=x[j]){
					min=x[j];
					min_pointer=j;
				}
			}
			swap(x[i],x[min_pointer]);
			swap(y[i],y[min_pointer]);
		}/*
		for(auto i:x){
			cout<<i<<'\t';
		}
		for(auto i:y)
			cout<<i<<'\t';*/
		x[1]+=x[0];
		if(x[2]>x[1])
			cout<<y[2]<<endl;
		else
			cout<<y[1]<<endl;
	}
}
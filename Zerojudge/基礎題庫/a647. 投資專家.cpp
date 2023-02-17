#include<iostream>
#include<math.h>
using namespace std;//m 是該藝術品投資的金額、p 是該藝術品目前的價值
int main(){
	int n;
	cin>>n;
	float m[n],p[n];
	float avg[n];
	for(int i=0;i<n;i++){
		cin>>m[i]>>p[i];
		avg[i]=(p[i]-m[i])/m[i];
		avg[i]=avg[i]*100;
		if(avg[i]>0)
			avg[i]=avg[i]+0.00001;
		if(avg[i]<0)
			avg[i]=avg[i]-0.00001;
		if(avg[i]>=10||avg[i]<=-7)
			printf("%.2f%% dispose\n",avg[i]);
		else
			printf("%.2f%% keep\n",avg[i]);
	}
	return 0;
}
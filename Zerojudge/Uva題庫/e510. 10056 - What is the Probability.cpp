#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int s;
	cin>>s;
	for(;s>=1;s--){
		double x[3]={},y=0;
		cin>>x[0]>>x[1]>>x[2];
		y=pow(1-x[1],x[2]-1)*x[1]/(1-pow(1-x[1],x[0]));
		printf("%.4f\n",y);
	}
}
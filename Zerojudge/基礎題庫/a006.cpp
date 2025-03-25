#include<iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c,x;
	float d1,d2;
	cin>>a>>b>>c;
	x=b*b-4*a*c;
	d1=(-b+pow(b*b-4*a*c,0.5))/(2*a);	
	d2=(-b-pow(b*b-4*a*c,0.5))/(2*a);
	if(x<0){
		cout<<"No real root";
	}
	else if(x>0)	
		cout<<"Two different roots x1="<<d1<<" , x2="<<d2;
	else if(x==0)
		cout<<"Two same roots x="<<d1;
	return 0;
}
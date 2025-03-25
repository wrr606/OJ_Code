#include<iostream>
using namespace std;
int main(){
	long long int a,b;
	while(cin>>a>>b){
		long long int x,y;
		int con,counter=0,max=0;
		x=b;
		y=a;
		if(a>=b){
			x=a;
			y=b;
		}
		for(long long int i=y;i<=x;i++){
			counter=0;
			con=i;
			while(con!=1){
				if(con%2==1){
					con=con*3+1;
				}
				else{
					con=con/2;
				}
				counter++;
			}
			counter++;
			if(max<counter){
				max=counter;
			}
		}
		cout<<a<<" "<<b<<" "<<max<<'\n';
	}
}
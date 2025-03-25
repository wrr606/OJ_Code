#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	switch(x){
		case 0 ... 10:
			cout<<6*x;
			break;
		case 11 ... 20:
			cout<<(x-10)*2+60;
			break;
		case 21 ... 39:
			cout<<(x-20)+80;
			break;
		case 40 ... 550:
			cout<<100;
			break;
	}
}
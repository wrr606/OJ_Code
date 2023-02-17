#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main() {
	char x[7]={};
	cin>>x;
	for(int i=0;i<6;i++){
		cout<<abs((int)x[i]-(int)x[i+1]);
	}
}
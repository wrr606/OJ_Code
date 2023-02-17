#include<iostream>
#include<math.h>
#include<string.h>
#include<ctype.h>
using namespace std;
void hnt(int n,char a,char b,char c){
	if(n==1){
		cout<<"Move ring "<<n<<" from "<<a<<" to "<<c<<endl;//Move ring 1 from A to C 
	}
	else{
		hnt(n-1,a,c,b);
		cout<<"Move ring "<<n<<" from "<<a<<" to "<<c<<endl;//Move ring 1 from A to C 
		hnt(n-1,b,a,c);
	}
}
int main(){
	int n;
	while(cin>>n)
		hnt(n,'A','B','C');
}
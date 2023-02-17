#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int df(int x,int i=1,int counter=1){
	if(counter==x){
		return i;
	}
	else{
		return df(x,i+counter,counter+1);
	}
}
int main() {
	int n;
	while(cin>>n){
		cout<<df(n)<<endl;
	}
}
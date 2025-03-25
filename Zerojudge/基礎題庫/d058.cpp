#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin>>x;
	if(!x){
		cout<<0;
	}
	else{
		cout<<x/abs(x);
	}
}
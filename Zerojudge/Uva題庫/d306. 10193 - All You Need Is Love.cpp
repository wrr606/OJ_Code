#include<bits/stdc++.h>
using namespace std;

long long int bin(string y){
	long long int x=0;
	for(int i=1;i<=y.size();i++){
		x+=pow(2,i-1)*((int)y[y.size()-i]-48);
	}
	return x;
}

int main(){
	int n;
	while(cin>>n){
		string s1,s2;
		long long int x1=0,x2=0;
		getline(cin,s1);
		for(int counter=1;counter<=n;counter++){
			getline(cin,s1);
			getline(cin,s2);
			x1=bin(s1);
			x2=bin(s2);
			cout<<"Pair #"<<counter<<": ";
			//cout<<x1<<endl<<x2<<endl;
			if(__gcd(x1,x2)==1){
				cout<<"Love is not all you need!\n";
			}
			else{
				cout<<"All you need is love!\n";
			}
		}
	} 
}
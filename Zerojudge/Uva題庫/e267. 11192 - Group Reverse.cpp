#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s,y;
	while(cin>>n&&n){
		cin>>s;
		int ssize=s.size();
		for(int i=0;i<ssize;i+=ssize/n){
			//cout<<"i:"<<i<<endl;
			y="";
			for(int j=i;j<i+ssize/n;j++){
				y+=s[j];
				//cout<<"j:"<<j<<endl;
			}
			reverse(y.begin(),y.end());
			cout<<y;
		}
		cout<<endl;
	}
}
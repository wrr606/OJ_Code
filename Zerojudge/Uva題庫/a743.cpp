#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string y;
	while(cin>>n){
		map<string,int> country;
		getline(cin,y);
		for(;n>0;n--){
			string x;
			getline(cin,y);
			for(auto i:y){
				if(i==' '){
					break;
				}
				x+=i;
			}
			country[x]++;
		}
		for(auto i:country){
			cout<<i.first<<" "<<i.second<<endl;
		}
	}
}
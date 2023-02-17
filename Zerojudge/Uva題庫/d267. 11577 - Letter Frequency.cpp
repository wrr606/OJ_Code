#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	while(cin>>n){
		getline(cin,s);
		while(n--){
			getline(cin,s);
			map<string,int> x;
			string temp;
			for(int i=0;i<s.size();i++){
				temp=s[i];
				if(s[i]<='Z'&&'A'<=s[i])
					temp=((int)s[i]+(int)('a'-'A'));
				if(temp<="z"&&"a"<=temp)
					x[temp]++;
			}
			cout<<endl;
			int max=-1;
			string pointer,re;
			string ans="";
			for(auto i:x){
				//cout<<i.second;
				if(i.second>max){
					max=i.second;
					pointer=i.first;
					i.second=0;
					//cout<<max<<pointer;
				}
			}
			for(auto i:x){
				//cout<<i.second;
				if(i.second==max)
					ans+=i.first;
			}
			cout<<ans<<endl;
			/*
			for(auto i:x){
				cout<<i.first<<"\t"<<i.second<<endl;
			}
			*/
		}
	}
}
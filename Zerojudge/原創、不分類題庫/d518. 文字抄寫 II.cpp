#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> dict;
int n,id;
string s;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	while(cin>>n){
		int id=0;
		dict.clear();
		for(int i=1;i<=n;i++){
			cin>>s;
			if(!dict[s]){
				dict[s]=++id;
				cout<<"New! ";
			}
			else{
				cout<<"Old! ";
			}
			cout<<dict[s]<<'\n';
		}
	}
}
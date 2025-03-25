#include<bits/stdc++.h>
using namespace std;

void dfs(string x,string y){
	string re=y,a;
	if(x.size()!=y.size()){
		for(int i=0;i<=y.size();i++){
			a=x[y.size()];
			re.insert(i,a);
			dfs(x,re);
			re=y;
		}
	}
	else{
		cout<<y<<endl;
	}
}

int main(){
	string s,y;
	bool n=0;
	while(cin>>s){
		if(n)
			cout<<endl;
		n=1;
		y=s[0];
		dfs(s,y);
	}
}
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
	map<string,int> x;
	x["1236"]=1;
	x["1235"]=1;
	x["1111"]=1;
	x["11"]=1;
	for(auto i:x)
		cout<<i.first<<" "<<i.second<<endl;
}
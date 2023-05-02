#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    //ios::sync_with_stdio(0),cin.tie(0);
	vector<int> x{1,2,3};
	x.erase(x.begin());
	x.erase(x.begin());
	x.erase(x.begin());
	for(auto i:x)
		cout<<i<<endl;
	cout<<"OK";
}
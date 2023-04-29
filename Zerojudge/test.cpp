#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    //ios::sync_with_stdio(0),cin.tie(0);
	deque<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	for(auto i:x){
		x.pop_front();
	}
	for(auto i:x){
		cout<<i<<" ";
	}
}
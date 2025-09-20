#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int n, m, arr[22];
vector<int> t;

void f(int idx = 0){
	if(t.size()==m){
		for(const auto &i:t)
			cout<<i<<" ";
		cout<<endl;
		return;
	}
	for(int i=idx;i<n;i++){
		t.emplace_back(arr[i]);
		f(i+1);
		t.pop_back();
	}
}
/*
1 3 5 7 9

*/
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	f();
}
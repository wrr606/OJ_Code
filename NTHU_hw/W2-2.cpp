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

int t, n, arr[1005], sum;
vi stk;
set<vi, greater<>> ans;
bool None;

void f(const int idx = 0){
	if(idx>n || sum>t)
		return;
	if(sum==t){
		None = 0;
		ans.insert(stk);
		return;
	}
	
	stk.emplace_back(arr[idx]), sum+=arr[idx];
	f(idx + 1);
	stk.pop_back(), sum-=arr[idx];
	f(idx + 1);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>t>>n && t && n){
		sum = 0, None = 1, ans.clear();
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<"Sums of "<<t<<":\n";
		f();
		if(None)
			cout<<"NONE\n";
		for(const auto &j:ans){
			for(int i=0;i<j.size();i++)
				cout<<j[i]<<"+\n"[i==j.size()-1];
		}
	}
}
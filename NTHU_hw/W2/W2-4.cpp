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

constexpr int n = 8;
int ans = 0;
bool pos[n], LD_RU[n*n-1], LU_RD[n*n-1];
vs grid(n);

inline void update(const int &y, const int &x){
	pos[x] = !pos[x];
	LD_RU[x + y] = !LD_RU[x + y];
	LU_RD[n - 1 + (y - x)] = !LU_RD[n - 1 + (y - x)];
}

inline bool check(const int &y, const int &x){
	if(pos[x])
		return 0;
	if(LD_RU[x + y])
		return 0;
	if(LU_RD[n - 1 + (y - x)])
		return 0;
	return 1;
}

void DFS(const int y = 0){
	if(y==n){
		ans++;
		return;
	}
	for(int x=0;x<n;x++){
		if(!check(y, x) || grid[y][x]=='*')
			continue;
		update(y, x);
		DFS(y + 1);
		update(y, x);
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	for(auto &i:grid)
		cin>>i;
	DFS();
	cout<<ans;
}
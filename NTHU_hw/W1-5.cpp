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

int n, grid[5][5], ans_sum;
vector<int> offices, ans;

void DFS(int idx = 0){
	if(offices.size() == 5){
		int sum=0;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				int min_dis=INT_MAX;
				for(const auto &k:offices){
					const int dis=(abs(k/5-i)+abs(k%5-j))*grid[i][j];
					min_dis=min(dis, min_dis);
				}
				sum+=min_dis;
			}
		}
		if(ans_sum>sum){
			ans_sum=sum;
			ans=offices;
		}
		return;
	}
	for(int i=idx;i<25;i++){
		offices.emplace_back(i);
		DFS(i+1);
		offices.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(grid, 0, sizeof(grid)), ans_sum=INT_MAX;
		for(int i=0, a, b, c;i<n;i++){
			cin>>a>>b>>c;
			grid[a][b]=c;
		}
		DFS();
		for(int i=0;i<5;i++)
			cout<<ans[i]<<"\n "[i!=4];
	}
}
//看懂題意比解題難 :/
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

class special_rooms{
public:
	int r = 0, c = 0;
	special_rooms() = default;
	special_rooms(const int &r, const int &c): r(r), c(c){}
};

special_rooms node[2][2];
int row, col, hive[10+2][5+2];
bool visited[10+2][5+2];
vector<special_rooms> t, route[2];

void DFS(const int &r, const int &c, const int &type, int &ans, const int &sum = 0){
	// cout<<r<<" "<<c<<endl;
	if(visited[r][c])
		return;
	if(r == node[type][1].r && c == node[type][1].c){
		if(ans > sum)
			route[type] = t, ans = sum;
		return;
	}
	t.emplace_back(r, c), visited[r][c] = 1;
	DFS(r + 1, c, type, ans, sum + hive[r][c]);
	DFS(r, c + 1, type, ans, sum + hive[r][c]);
	DFS(r, c - 1, type, ans, sum + hive[r][c]);
	DFS(r - 1, c, type, ans, sum + hive[r][c]);
	DFS(r - 1, c - 1, type, ans, sum + hive[r][c]);
	DFS(r + 1, c - 1, type, ans, sum + hive[r][c]);
	t.pop_back(), visited[r][c] = 0;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>row>>col;
		for(int i=0;i<4;i++)
			cin>>node[i/2][i%2].r>>node[i/2][i%2].c;
		memset(visited, 1, sizeof(visited)), route[0].clear(), route[1].clear();
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++)
				cin>>hive[i][j], visited[i][j]=0;
		}
		int ans1 = INT_MAX, ans2 = INT_MAX;
		DFS(node[0][0].r, node[0][0].c, 0, ans1);
		for(const auto &[i, j]:route[0])
			visited[i][j] = 1;
		DFS(node[1][0].r, node[1][0].c, 1, ans2);
		if(ans1==INT_MAX || ans2==INT_MAX)
			cout<<-1<<endl;
		else
			cout<<ans1 + ans2<<endl;
		// cout<<ans1<<" "<<ans2<<endl;
	}
}
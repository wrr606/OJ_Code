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

int ans = 0;
string s;
bool visited[9][9] = {//工人智慧 :)
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void DFS(const int idx = 0, const int row = 1, const int col = 1){
	if(row<1 || row>=8 || col<1 || row>=8 || visited[row][col])
		return;
	if(row==7 && col==1){
		if(idx==48)
			++ans;
		return;
	}
	if(!visited[row+1][col] && !visited[row-1][col] &&
		 visited[row][col+1] && visited[row][col-1])
		return;
	if(visited[row+1][col] && visited[row-1][col] &&
		 !visited[row][col+1] && !visited[row][col-1])
		return;
	visited[row][col] = 1;
	switch (s[idx]){
		case 'D':
			DFS(idx+1, row+1, col);
			break;
		case 'U':
			DFS(idx+1, row-1, col);
			break;
		case 'L':
			DFS(idx+1, row, col-1);
			break;
		case 'R':
			DFS(idx+1, row, col+1);
			break;
		default:
			DFS(idx+1, row+1, col);
			DFS(idx+1, row, col+1);
			DFS(idx+1, row-1, col);
			DFS(idx+1, row, col-1);
			break;
	}
	visited[row][col]=0;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s;
	DFS();
	cout<<ans;
}
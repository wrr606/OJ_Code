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

int n, sum, arr[20] = {};
bool ans, visited[20];
//8 1 7 2 6 4 4 3 5
//7 
void DFS(const int idx = 0, const int cur = 0, const int finish = 0){
	// cout<<idx<<" "<<cur<<" "<<finish<<endl;
	if(ans || finish == 3){
		ans = 1;
		return;
	}
	for(int i=idx;i<n;i++){
		// cout<<"i: "<<sum<<endl;
		if(visited[i])
			continue;
		visited[i]=1;
		if(cur + arr[i] == sum/4){
			DFS(0, 0, finish+1);
		}
		else if(cur + arr[i] < sum/4){
			DFS(i+1, cur+arr[i], finish);
		}
		visited[i]=0;
	}
}//8 	9 7 6 4 4 3 2 1

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		sum = 0, ans = 0, memset(visited, 0, sizeof(visited));
		for(int i=0;i<n;i++)
			cin>>arr[i], sum+=arr[i];
		sort(arr, arr+n, greater<>());
		if(sum%4==0 && arr[0]<=sum/4)
			DFS();
		if(ans)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}
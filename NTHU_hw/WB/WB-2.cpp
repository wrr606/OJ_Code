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

constexpr int N = 5e4 + 5;
int n, m;
bitset<N> adj[N];
vi routes[N];
bool visited[N];

void DFS(const int cur){
    visited[cur] = 1;
    adj[cur][cur] = 1;

    for(const auto &i: routes[cur]){
        if(!visited[i])
            DFS(i);
        adj[cur] |= adj[i];
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        routes[a].emplace_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i])
            DFS(i);
        cout<<adj[i].count()<<" ";
    }
}
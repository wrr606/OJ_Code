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

constexpr int N = 2e5 + 5;
vi routes[N];

int D1[N], D2[N]; // 最遠、次遠距離
int ans = 0; // 直徑長度
void dfs(int u = 1, int parent = -1) {
    D1[u] = D2[u] = 0;
    for (int v : routes[u]) {
        if (v == parent) continue;
        dfs(v, u);
        int dis = D1[v] + 1;
        if(dis > D1[u]){
            D2[u] = D1[u];
            D1[u] = dis;
        }
        else
            D2[u] = max(D2[u], dis);
    }
    ans = max(ans, D1[u] + D2[u]);
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, a, b;
    cin>>n;
    for(int _=0;_<n-1;_++){
        cin>>a>>b;
        routes[a].emplace_back(b);
        routes[b].emplace_back(a);
    }
    dfs();
    cout<<ans;
}
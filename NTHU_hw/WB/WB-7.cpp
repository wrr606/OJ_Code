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

constexpr int MAXN = 1e5 + 5, MOD = 1e9 + 7;
vi routes[MAXN];
int n;
ll dp[MAXN][2];

inline ll mod_add(ll a, ll b){
    return (a + b) % MOD;
}

inline ll mod_mul(ll a, ll b){
    return (a * b) % MOD;
}

ll DFS(const int cur, const bool pick, const int parent = -1){
    if(dp[cur][pick])
        return dp[cur][pick];

    ll cur_val = 1;
    for(const auto &i: routes[cur]){
        if(i == parent)
            continue;
        if(pick)
            cur_val = mod_mul(cur_val, DFS(i, 0, cur));
        else
            cur_val = mod_mul(cur_val, mod_add(DFS(i, 0, cur), DFS(i, 1, cur)));
    }
    return dp[cur][pick] = cur_val;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    int a, b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        routes[a].emplace_back(b);
        routes[b].emplace_back(a);
    }
    cout<<mod_add(DFS(1, 0), DFS(1, 1));
}
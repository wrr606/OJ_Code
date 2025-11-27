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

constexpr int MAXN = 2e5 + 5;
vi routes[MAXN];
int subtree_size[MAXN], ans, n;

void DFS(int cur = 1, int last = -1){
    subtree_size[cur] = 1;
    int max_subtree = 0;
    for(const auto &i: routes[cur]){
        if(i == last)
            continue;
        DFS(i, cur);
        subtree_size[cur] += subtree_size[i];
        max_subtree = max(max_subtree, subtree_size[i]);
    }
    max_subtree = max(max_subtree, n - subtree_size[cur]);
    if(max_subtree <= n / 2)
        ans = cur;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a, b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        routes[a].emplace_back(b);
        routes[b].emplace_back(a);
    }
    DFS();
    cout<<ans;
}
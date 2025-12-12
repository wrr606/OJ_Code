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
 
int n, x, weights[20];
 
#define F first
#define S second
 
unordered_map<int, pii> dp;
pii DFS(const int mask = 0){
    if(dp.count(mask))
        return dp[mask];
    if(__builtin_popcount(mask) == n)
        return dp[mask] = {1, 0};
    pii ans = {INT_MAX, INT_MAX};
    for(int i=0;i<n;i++){
        if(mask & (1<<i))
            continue;
        auto res = DFS(mask | (1<<i));
        if(res.S + weights[i] <= x)
            res.S += weights[i];
        else
            res = {res.F + 1, weights[i]};
        ans = min(ans, res);
    }
    return dp[mask] = ans;
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>weights[i];
    cout<<DFS().F;
}
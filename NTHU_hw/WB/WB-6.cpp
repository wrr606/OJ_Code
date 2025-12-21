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

constexpr int MAXN = 4e2 + 5;
ll dp[MAXN][MAXN], prefix[MAXN], arr[MAXN];

inline ll query(int a, int b){
    return prefix[b] - prefix[a - 1];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        fill(dp[i], dp[i] + MAXN, 1e15);
        dp[i][i] = 0;
    }
    partial_sum(arr + 1, arr + 1 + n, prefix + 1);

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            const int j = i + len - 1;
            const auto sum = query(i, j);
            for(int k=i;k<j;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
        }
    }
    cout<<dp[1][n];
}
//Two_Sets_II
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

int main(){//01背包 mod_inverse()
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    const ll mod=1e9+7,modinverse_2=5e8+4;
    cin>>n;
    int limit=(n*n+n)>>1;
    if(limit&1){
        cout<<0;
        return 0;
    }
    limit>>=1;
    vi dp(limit+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=limit;j>=i;j--){
            (dp[j]+=dp[j-i])%=mod;
        }
    }
    cout<<(dp[limit]*modinverse_2)%mod;
}
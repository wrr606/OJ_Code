//Array_Description
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
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    const int mod=1000000007;
    cin>>n>>m;
    vi num(n+1);
    for(int i=1;i<=n;i++)
        cin>>num[i];
    vector<vi> dp(n+1,vi(m+2));
    if(num[1])//初始化
        dp[1][num[1]]=1;
    else
        for(int i=1;i<=m;i++)
            dp[1][i]=1;
    for(int i=2;i<=n;i++){
        if(num[i]){
            dp[i][num[i]]=(dp[i][num[i]]+dp[i-1][num[i]+1])%mod;
            dp[i][num[i]]=(dp[i][num[i]]+dp[i-1][num[i]])%mod;
            dp[i][num[i]]=(dp[i][num[i]]+dp[i-1][num[i]-1])%mod;
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
    }
    if(num[n])
        cout<<dp[n][num[n]];
    else{
        ll ans=0;
        for(int i=1;i<=m;i++)
            ans+=dp[n][i];
        cout<<ans%mod;
    }
}
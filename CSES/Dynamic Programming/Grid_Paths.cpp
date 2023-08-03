//Grid_Paths
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
    int n;
    const int mod=1000000007;
    string s;
    cin>>n;
    vector<string> grids(n+2);
    vvi dp(n+2,vi(n+2));
    for(int i=1;i<=n;i++){
        cin>>s;
        stringstream ss(" "+s+" ");
        grids[i]=ss.str();
    }
    dp[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grids[i][j]=='*')
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n][n];
}
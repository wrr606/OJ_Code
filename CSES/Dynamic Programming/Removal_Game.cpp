//Removal_Game
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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vi num(n+1);
    for(int i=1;i<=n;i++)
        cin>>num[i];
    vector<vector<pll>> dp(n+2,vector<pll>(n+2));
    for(int i=1;i<=n;i++)//初始化
        dp[i][i]={num[i],0};
    for(int length=1;length<n;length++){
        for(int i=1,j=i+length;j<=n;i++,j++){
            if(dp[i+1][j].second+num[i]>=dp[i][j-1].second+num[j])
                dp[i][j]={dp[i+1][j].second+num[i],dp[i+1][j].first};
            else
                dp[i][j]={dp[i][j-1].second+num[j],dp[i][j-1].first};
        }
    }
    cout<<dp[1][n].first;
}
//Minimizing_Coins
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
    int n,x;
    cin>>n>>x;
    vi coins(n),dp(x+1);
    vector<bool> check(x+1);
    for(auto &i:coins)
        cin>>i;
    for(int i=1;i<=x;i++)
        dp[i]=i;
    check[0]=1;
    for(const auto &i:coins){
        for(int j=i;j<=x;j++){
            if(check[j-i]){
                dp[j]=min(dp[j-i]+1,dp[j]);
                check[j]=1;
            }
        }
    }
    if(check[x])
        cout<<dp[x];
    else
        cout<<-1;
}
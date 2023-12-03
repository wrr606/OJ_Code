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

constexpr int N=1e6+5;
ll dp[1000005]={};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x;
    cin>>n>>x;
    vi c(n);
    fill(dp+1,dp+1+x,INT_MAX);
    for(auto &i:c)
        cin>>i;
    for(const auto &i:c){
        for(int j=i;j<=x;j++){
            dp[j]=min(dp[j],dp[j-i]+1);
        }
    }
    if(dp[x]==INT_MAX)
        cout<<-1;
    else
        cout<<dp[x];
}
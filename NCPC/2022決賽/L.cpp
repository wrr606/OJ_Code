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

int pre[505]={};

int query(int i,int j){
    if(j<i)
        swap(i,j);
    return pre[j]-pre[i-1];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,cost[505]={},dp[505][50005]={},dis[505]={};
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>cost[i],pre[i]=cost[i]+pre[i-1];
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=cost[i];j--){
                dp[i][j]=min(dp[i-1][j-cost[i]],dp[i-1][j]+cost[i]);
                ans=min(ans,dp[i][j]);
            }
        }
        cout<<endl<<dp[n]<<endl;
    }
}
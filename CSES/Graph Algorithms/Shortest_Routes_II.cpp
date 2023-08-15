//Shortest_Routes_II
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

int n;
set<pii> routs[505];
ll dp[505][505];

void Initialization(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1e18;
        }
        dp[i][i]=0;
    }
}

void Floyd_warshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
}

int main(){//Floyd warshall
    ios::sync_with_stdio(0),cin.tie(0);
    int m,q;
    cin>>n>>m>>q;
    Initialization();
    while(m--){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=dp[a][b];
    }
    Floyd_warshall();
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dp[a][b]==1e18)
            cout<<-1<<endl;
        else
            cout<<dp[a][b]<<endl;
    }
}
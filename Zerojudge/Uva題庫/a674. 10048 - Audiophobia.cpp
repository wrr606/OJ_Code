//a674. 10048 - Audiophobia
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
    int n,m,q,t=0;
    bool b=0;
    while(cin>>n>>m>>q&&n&&m&&q){
        vvi dp(n+1,vi(n+1,1e8));
        for(int i=0;i<=n;i++)
            dp[i][i]=0;
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            dp[a][b]=min(dp[a][b],c);
            dp[b][a]=dp[a][b];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    int mx=max(dp[j][i],dp[i][k]);
                    dp[j][k]=min(dp[j][k],mx);
                }
            }
        }
        if(b)
            cout<<endl;
        b=1;
        cout<<"Case #"<<++t<<"\n";
        while(q--){
            int a,b;
            cin>>a>>b;
            if(dp[a][b]==1e8)
                cout<<"no path\n";
            else
                cout<<dp[a][b]<<endl;
        }
    }
}
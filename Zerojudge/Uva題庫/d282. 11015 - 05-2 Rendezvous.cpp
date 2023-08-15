//d282. 11015 - 05-2 Rendezvous
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
vvi dp;

void Initialization(){
    dp.assign(n+1,vi(n+1,INT_MAX));
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
}

int find_min(){
    vi ans(n+1);
    ans[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[j]+=dp[i][j];
        }
    }
    return min_element(all(ans))-ans.begin();
}

int main(){//Floyd warshall
    ios::sync_with_stdio(0),cin.tie(0);
    int t=0,m;
    while(cin>>n>>m&&n){
        t++;
        vs name(n);
        Initialization();
        for(auto &i:name)
            cin>>i;
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            dp[a][b]=min(dp[a][b],c);
            dp[b][a]=dp[a][b];
        }
        cout<<"Case #"<<t<<" : ";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
                }
            }
        }
        cout<<name[find_min()-1]<<endl;
    }
}
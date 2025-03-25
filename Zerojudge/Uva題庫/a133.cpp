//a133. 10066 - The Twin Towers
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
    int dp[105][105],n1,n2,x[105],y[105],c=1;
    while(cin>>n1>>n2&&n1&&n2){
        for(int i=0;i<n1;i++)
            cin>>x[i];
        for(int i=0;i<n2;i++)
            cin>>y[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<"Twin Towers #"<<c++<<endl;
        cout<<"Number of Tiles : "<<dp[n1][n2]<<endl<<endl;
    }
}
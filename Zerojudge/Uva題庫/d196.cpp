//d196. 11341 - Term Strategy
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

int main(){//dp
    int t,time[15][105],dp[15][105],n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&time[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
            if(time[1][i]>=5)
                dp[1][i]=time[1][i];
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                for(int k=1;k<=j;k++){
                    if(time[i][k]>=5&&dp[i-1][j-k])
                        dp[i][j]=max(dp[i][j],dp[i-1][j-k]+time[i][k]);
                }
            }
        }
        if(dp[n][m])
            printf("Maximal possible average mark - %.2lf.\n",dp[n][m]/double(n)+0.001);
        else
            printf("Peter, you shouldn't have played billiard that much.\n");
    }
}
//Rectangle_Cutting
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
    int a,b;
    cin>>a>>b;
    if(a<b)
        swap(a,b);
    vvi dp(a+1,vi(a+1,INT_MAX));
    for(int i=1;i<=a;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<i;k++)
                dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            for(int k=1;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
        }
    }
    cout<<dp[a][b];
}
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

int mp[55][10005]={},l[10005]={},r[10005]={},dp[55][10005]={},n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    l[0]=l[n+1]=r[0]=r[n+1]=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            r[j]=max(r[j-1],dp[i-1][j])+mp[i][j];
        for(int j=m;j>0;j--)
            l[j]=max(l[j+1],dp[i-1][j])+mp[i][j];
        for(int j=1;j<=m;j++)
            dp[i][j]=max(r[j],l[j]);
    }
    cout<<*max_element(dp[n]+1,dp[n]+m+1);
}
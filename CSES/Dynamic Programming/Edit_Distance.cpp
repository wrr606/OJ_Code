//Edit_Distance
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
    string a,b;
    cin>>a>>b;
    vvi dp(b.size()+1,vi(a.size()+1));
    for(int i=1;i<=a.size();i++)//初始化
        dp[0][i]=i;
    for(int i=1;i<=b.size();i++)
        dp[i][0]=i;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1])
                dp[j][i]=dp[j-1][i-1];
            else
                dp[j][i]=min(dp[j-1][i-1],min(dp[j-1][i],dp[j][i-1]))+1;
        }
    }
    cout<<dp[b.size()][a.size()];
}
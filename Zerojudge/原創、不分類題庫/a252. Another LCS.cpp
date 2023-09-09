//a252. Another LCS
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

int dp[105][105][105]={};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            for(int k=1;k<=c.size();k++){
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    cout<<dp[a.size()][b.size()][c.size()];
}
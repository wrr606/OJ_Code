//f507. 1207 - AGTC
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

int dp[1045][1045];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b;
    string s1,s2;
    while(cin>>a){
        cin>>s1>>b>>s2;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=max(a,b);i++){
            dp[0][i]=i;
            dp[i][0]=i;
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
        cout<<dp[a][b]<<endl;
    }
}
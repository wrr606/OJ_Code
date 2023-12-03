//d206. 00108 - Maximum Sum
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
    int n,dp[105][105];
    while(cin>>n){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>dp[i][j],dp[i][j]+=dp[i][j-1];
        int mx=dp[0][0];
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sum=0;
                for(int k=1;k<=n;k++){
                    sum+=dp[k][j]-dp[k][i];
                    if(sum<0)
                        sum=0;
                    mx=max(mx,sum);
                }
            }
        }
        cout<<mx<<endl;
    }
}
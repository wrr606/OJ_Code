//d378. 最小路徑
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

int n,m;

bool check(const int &i,const int &j){
    if(i<0||i>=n||j<0||j>=m)
        return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int cost[105][105],dp[105][105],t=1;
    while(cin>>n){
        cin>>m;
        fill(&dp[0][0],&dp[0][0]+105*105,INT_MAX);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>cost[i][j];
        cout<<"Case #"<<t++<<" :\n";
        dp[0][0]=cost[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i-1,j))
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+cost[i][j]);
                if(check(i,j-1))
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+cost[i][j]);
            }
        }
        cout<<dp[n-1][m-1]<<endl;
    }
}
//b565. 5.採蘑菇攻略問題
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
    int num[55],dp[55],n;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>num[i];
        dp[0]=num[0];
        int ans=0;
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],0)+num[i];
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
}
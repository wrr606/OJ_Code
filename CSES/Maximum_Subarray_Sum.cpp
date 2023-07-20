//Maximum_Subarray_Sum
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vll num(n),dp(n);
    for(auto &i:num)
        cin>>i;
    ll ans=0;
    dp[0]=num[0],ans=num[0];
    for(int i=1;i<n;i++){
        dp[i]=max(ll(0),dp[i-1])+num[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
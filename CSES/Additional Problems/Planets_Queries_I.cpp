//Planets_Queries_I
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
    int n,q,x,k;
    cin>>n>>q;
    int dp[n+1][32];
    for(int i=1;i<=n;i++)
        cin>>dp[i][0];
    for(int i=1;i<32;i++)
        for(int j=1;j<=n;j++)
            dp[j][i]=dp[dp[j][i-1]][i-1];
    while(q--){
        cin>>x>>k;
        int cur=x;
        for(int i=0;i<32;i++){
            if((k&(1<<i))!=0){
                cur=dp[cur][i];
            }
        }
        cout<<cur<<endl;
    }
}
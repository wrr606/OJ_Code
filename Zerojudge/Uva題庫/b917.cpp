//b917. 11059 Maximum Product
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,counter=0;
    bool end=0;
    ll dp[20][20],ans;
    while(cin>>n){
        counter++,ans=0;
        for(int i=0;i<n;i++){
            cin>>dp[i][i];
            ans=max(ans,dp[i][i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[i][j]=dp[j][j]*dp[i][j-1];
                //cout<<i<<"\t"<<j<<"\t"<<dp[i][j]<<endl;
                ans=max(dp[i][j],ans);
            }
        }
        cout<<"Case #"<<counter<<": The maximum product is "<<ans<<".\n\n";
    }
}
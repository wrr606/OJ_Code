#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001]={},w[21]={};

int main(){
    //dp[i-1][j] = max(dp[i-1][j], dp[i-1][j – w[i]] + v[i]);
    int t,n,p;
    while(cin>>t){
        for(;t>0;t--){
            cin>>n>>p;
            for(int q=1;q<=p;q++){
                cin>>w[q];
            }
            for(int i=1;i<=p;i++){
                for(int j=1;j<=n;j++){
                    if(w[i]>j){
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
                    }
                }
            }
            if(dp[p][n]==n){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}
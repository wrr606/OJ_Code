#include <bits/stdc++.h>
using namespace std;

int t,n,p[1001]={},w[1001]={},gi,dp[1001]={},counter,g;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>t){
        for(int o=0;o<t;o++){
            counter=0;
            cin>>n;
            for(int i=1;i<=n;i++){
                cin>>p[i]>>w[i];
            }
            cin>>g;
            for(int i=1;i<=g;i++){
                cin>>gi;
                memset(dp,0,sizeof(dp));
                for(int i=1;i<=n;i++){
                    for(int j=gi;j>=w[i];j--){
                        dp[j]=max(dp[j],p[i]+dp[j-w[i]]);
                    }
                }
                //cout<<"dp[gi]:"<<dp[gi]<<endl;
                counter+=dp[gi];
            }
            cout<<counter<<"\n";
        }
    }
}
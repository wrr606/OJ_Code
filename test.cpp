#include<iostream>
using namespace std;
const int N=105;
int n,ans,a[105];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];  
    int dp[9999];
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(a[j]<a[i]){
                dp[i]=max(dp[i],1+dp[j]);
                ans=max(ans,dp[i]);
            }
            
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n&&n){
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++)
            cin>>dp[i];
        int max=dp[1];
        for(int i=2;i<=n;i++){
            if(dp[i-1]>0)
                dp[i]+=dp[i-1];
            if(dp[i]>max)
                max=dp[i];
        }
        if(max<=0)
            cout<<"Losing streak.\n";
        else
            cout<<"The maximum winning streak is "<<max<<".\n";
    }
}
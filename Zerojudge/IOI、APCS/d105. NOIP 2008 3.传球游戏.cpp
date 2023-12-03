#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
    cin>>n>>m;
    int dp[m+1][n+1]={};
    dp[0][1]=1;
    for(int i=1;i<=m;i++){//次數
        for(int j=1;j<=n;j++){//人數、位置
            int temp=j-1,temp2=j+1;
            if(j==1)
                temp=n;
            if(j==n)
                temp2=1;
            dp[i][temp2]+=dp[i-1][j];
            dp[i][temp]+=dp[i-1][j];
        }
    }
    cout<<dp[m][1];
}
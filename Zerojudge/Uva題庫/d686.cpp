#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

long long int dp[1001][1001]={};

int main(){
	int l,n;
	while(cin>>l&&l){
        cin>>n;
        vector<int> cut(n+2);
        cut[0]=0;
        cut[n+1]=l;
        for(int i=1;i<=n;i++)
            cin>>cut[i];
        memset(dp,0,sizeof(dp));
        for(int j=2;j<=n+1;j++){
            for(int left=0,right=j+left;left<n||right<n+1;left++){
                right=j+left;
                dp[left][right]=INT_MAX;
                for(int m=left+1;m<right;m++){
                    dp[left][right]=min(dp[left][m]+dp[m][right]+cut[right]-cut[left],dp[left][right]);
                    //printf("dp[%d][%d]=%lld\t%d\n",left,right,dp[left][right],m);
                }
            }
        }
        cout<<"The minimum cutting is "<<dp[0][n+1]<<"."<<endl;
	}
}
/*
in:
100
3
25 50 75

out:
200
*/
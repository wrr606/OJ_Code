#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int dp[100001]={};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,min,max;
    while(cin>>n>>m){
        cin>>dp[1];
        for(int i=2;i<=n;i++){
            cin>>dp[i];
            dp[i]+=dp[i-1];
        }
        while(m--){
            cin>>min>>max;
            cout<<dp[max]-dp[min-1]<<endl;
        }
    }
}
//1 3 6
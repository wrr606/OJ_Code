//j122. 11957 - Checkers
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

char check[102][102]={};
bool check_bool[102][102]={0};
int dp[102][102]={},t,n,ans,x;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>t;
    for(int c=1;c<=t;c++){
        ans=0;
        memset(dp,0,sizeof(dp)),memset(check_bool,0,sizeof(check_bool));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=n;j++){
                check_bool[i][j]=1;
                check[i][j]=s[j-1];
                if(check[i][j]=='W'){
                    dp[i][j]=1;
                    x=i;
                }
            }
        }
        for(int i=x-1;i>0;i--){
            for(int j=1;j<=n;j++){
                if(check[i][j]=='B'){
                    if(check_bool[i+1][j+1]&&check[i-1][j-1]!='B')
                        dp[i-1][j-1]+=dp[i+1][j+1];
                    if(check_bool[i+1][j-1]&&check[i-1][j+1]!='B')
                        dp[i-1][j+1]+=dp[i+1][j-1];
                }
                else{
                    if(check_bool[i+1][j-1])
                        dp[i][j]+=dp[i+1][j-1];
                    if(check_bool[i+1][j+1])
                        dp[i][j]+=dp[i+1][j+1];
                }
                dp[i][j]%=1000007;
            }
        }
/*
        //debug
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        for(int j=1;j<=n;j++)
            ans+=dp[1][j];
        cout<<"Case "<<c<<": "<<ans%1000007<<endl;
    }
}
/*
....
....
.B..
..W.

0201
1010
0001
0010
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
int dp[501][501]={};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,x1,y1,x2,y2;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                cin>>dp[j][i];
                dp[j][i]+=dp[j-1][i];
            }
        while(m--){
            cin>>y1>>x1>>y2>>x2;
            int counter=0;
            for(int i=y1;i<=y2;i++){
                counter+=dp[x2][i]-dp[x1-1][i];
            }
            cout<<counter<<endl;
        }
    }
}
/*
1 2 3
4 5 6
7 8 9

0 0 0 0
0 1 3 6
0 4 9 15
0 7 15 24

28=15+24-4-7

2 2     3 3
*/
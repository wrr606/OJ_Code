#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int coin[5]={1,5,10,25,50},n;
    vector<long long int> dp(7490);
    dp[0]=1;
    for(auto i:coin)
        for(int j=i;j<7490;j++)
            dp[j]+=dp[j-i];
    while(cin>>n)
        cout<<dp[n]<<endl;
}
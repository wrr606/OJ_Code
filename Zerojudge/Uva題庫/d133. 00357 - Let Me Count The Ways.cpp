#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int coin[5]={1,5,10,25,50},n;
    vector<long long int> dp(30001);
    dp[0]=1;
    for(auto i:coin)
        for(int j=i;j<30001;j++)
            dp[j]+=dp[j-i];
    while(cin>>n){
        if(dp[n]==1)
            cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        else
            cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change.\n";
    }
}
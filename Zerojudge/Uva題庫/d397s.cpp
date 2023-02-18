#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    double n;
    vector<long long int> dp(30001);
    dp[0]=1;
    for(auto i:coin)
        for(int j=i;j<30001;j++)
            dp[j]+=dp[j-i];
    while(cin>>n&&n)
        printf("%6.2f%17lld\n",n,dp[(int)(n*100+0.001)]);
}
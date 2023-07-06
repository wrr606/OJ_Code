//1471 - Defense Lines
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){//LIS DP Greedy
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> l(n+1),r(n+1),number(n+1);
        for(int i=1;i<=n;i++)
            cin>>number[i];
        l[1]=1,r[n]=1;
        for(int i=2;i<=n;i++){
            if(number[i]>number[i-1])
                l[i]=l[i-1]+1;
            else
                l[i]=1;
        }
        for(int i=n-1;i>0;i--){
            if(number[i]<number[i+1])
                r[i]=r[i+1]+1;
            else
                r[i]=1;
        }
        vector<int> dp(n+1,INT_MAX);
        int ans=0;
        for(int i=1;i<=n;i++){
            int length=(lower_bound(dp.begin()+1,dp.end(),number[i])-(dp.begin()+1))+r[i];
            ans=max(ans,length);
            dp[l[i]]=min(dp[l[i]],number[i]);
        }
        cout<<ans<<endl;
    }
}
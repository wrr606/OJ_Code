//d242. 00481 - What Goes Up
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int dp[500001];

int main(){//LIS
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    vector<int> num,lis,ans;
    while(cin>>n){
        num.push_back(n);
    }
    for(int i=0;i<num.size();i++){
        if(lis.empty()||lis.back()<num[i]){
            lis.push_back(num[i]);
            dp[i]=lis.size();
        }
        else{
            auto iter=lower_bound(all(lis),num[i]);
            dp[i]=iter-lis.begin()+1;
            *iter=num[i];
        }
    }
    cout<<lis.size()<<"\n-\n";
    int length=lis.size();
    for(int i=num.size()-1;i>=0;i--){
        if(dp[i]==length){
            ans.push_back(num[i]);
            length--;
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<endl;
}
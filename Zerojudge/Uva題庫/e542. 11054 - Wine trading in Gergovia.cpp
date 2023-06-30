//e542. 11054 - Wine trading in Gergovia
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){//greedy algorithm
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(cin>>n&&n){
        vector<int> site(n);
        for(auto &i:site)
            cin>>i;
        int ans=abs(site[0]);
        for(int i=1;i<n;i++){
            site[i]+=site[i-1];
            ans+=abs(site[i]);
        }
        cout<<ans<<endl;
    }
}
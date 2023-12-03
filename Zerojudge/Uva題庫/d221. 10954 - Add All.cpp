//d221. 10954 - Add All
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){//huffman algorithm
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    while(cin>>t&&t){
        ll ans=0;
        priority_queue<ll,vector<ll>,greater<ll> > pq;
        for(int i=0;i<t;i++){
            cin>>n;
            pq.push(n);
        }
        while(pq.size()>1){
            ll x,y;
            x=pq.top(),pq.pop();
            y=pq.top(),pq.pop();
            pq.push(x+y),ans+=x+y;
        }
        cout<<ans<<endl;
    }
}
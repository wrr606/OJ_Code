//d122. Oh! My Zero!!
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n;
    while(cin>>n){
        ll ans=0;
        for(ll i=1;pow(5,i)<=n;i++){
            ans+=n/pow(5,i);
        }
        cout<<ans<<endl;
    }
}
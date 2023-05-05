//d237. 質數合
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool isprime(int n){
    for(int i=3;i*i<=n;i+=2){
        if(!(n%i))
            return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll ans=5;
    for(ll i=5;i<=2000000;i+=2)
        ans+=(isprime(i))?i:0;
    cout<<ans<<endl;
}
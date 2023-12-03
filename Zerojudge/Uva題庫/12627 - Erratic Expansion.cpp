//12627 - Erratic Expansion
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

//快速冪
ll qpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)
            ans*=a;
        a*=a;
        n/=2;
    }
    return ans;
}

ll f(int k,int r){
    if(r==0)
        return 0;
    if(k==0)
        return 1;
    if(r<=qpow(2,k-1))
        return 2*f(k-1,r);
    else
        return 2*qpow(3,k-1)+f(k-1,r-qpow(2,k-1));
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,k,a,b;
    cin>>t;
    for(int c=1;c<=t;c++){
        cin>>k>>a>>b;
        cout<<"Case "<<c<<": ";
        cout<<f(k,b)-f(k,a-1)<<endl;
    }
}
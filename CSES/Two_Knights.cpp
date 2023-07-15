//Two_Knights
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
    ll res=1;
    while(n){
        if(n&1)
            res*=a;
        a=a*a;
        n/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<qpow(i,2)*(qpow(i,2)-1)/2-4*(i-1)*(i-2)<<endl;
}
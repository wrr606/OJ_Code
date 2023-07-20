//Bit_Strings
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
    int res=1;
    while(n){
        if(n&1)
            res=res*a%1000000007;
        a=a*a%1000000007;
        n>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    cout<<qpow(2,n);
}
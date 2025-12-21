#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

constexpr ll MOD = 1e9 + 7;

ll modInverse(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1)
            res=res*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return res;
}

bool isPrime(const int n){
    if(n == 1)
        return 0;
    for(int i=2;i*i<=n;i+=(i==2?1:2)){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int l, r;
    cin>>l>>r;
    ll a = 1, b = 1;//  a / b
    for(int i=l;i<=r;i++){
        if(isPrime(i))
            a = (a * i) % MOD;
        else
            b = (b * i) % MOD;
    }
    cout<<(a * modInverse(b, MOD - 2)) % MOD;
}
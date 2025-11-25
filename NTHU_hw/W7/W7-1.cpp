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

constexpr int mod = 1e9 + 7;

ll qpow(ll a,ll b, ll m){
    ll res=1;
    while(b){
        if(b&1)
            res=res*a%m;
        b>>=1;
        a=a*a%m;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n, a, b, c;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        cout<<qpow(a, qpow(b, c, mod - 1), mod)<<endl;
    }
}
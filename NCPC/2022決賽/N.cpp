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

constexpr int mod=1e9+7;

ll p_nk(const int &n,const int &k){
    ll res=1;
    for(int i=n-k+1;i<=n;i++)
        res=(res*i)%mod;
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int v1,v2,vandv,a;
        cin>>v1>>v2>>vandv>>a;
        if(max(v1,v2)>a){
            cout<<0<<endl;
            continue;
        }
        if(vandv==0){
            cout<<p_nk(a,v1)*p_nk(a,v2)%mod<<endl;
            continue;
        }
        cout<<(p_nk(a,vandv)*p_nk(a-vandv,v1-vandv))%mod*p_nk(a-vandv,v2-vandv)%mod<<endl;
    }
}
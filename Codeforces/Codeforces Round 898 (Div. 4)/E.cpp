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

constexpr int N=2e5+5;
ll a[N],n,x;

bool check(ll h){
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(h-a[i]>0)
            cnt+=h-a[i];
    }
    if(cnt>x)
        return 1;
    else
        return 0;
}

ll binary_search(ll l=1,ll r=INT_MAX){
    ll mid;
    while(l<=r){
        mid=l+((r-l)>>1);
        if(check(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<binary_search()<<endl;
    }
}
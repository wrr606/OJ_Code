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

constexpr int N = 2e5 + 5, Mod = 1e9 + 7;
constexpr int ModDiv2 = (Mod + 1) / 2;
int n;
ll seg[N<<2], K[N<<2], B[N<<2];
//(i - l + 1) * x
//xi + (1 - l)x
//K + B

void add_mod(auto &a, const auto b){
    a = (a + b) % Mod;
}

ll get_sum(ll l, ll r){
    ll len = r - l + 1;
    ll sum = (l + r) % Mod * (len % Mod) % Mod * ModDiv2 % Mod;
    return sum;
}

void merge(int idx){
    seg[idx]=(seg[idx<<1]+seg[idx<<1|1])%Mod;
}

void push_tag(int idx,int l,int r){
    if(!K[idx] && !B[idx])
        return;
    const int mid = (l + r) >> 1;

    ll k = K[idx];
    ll b = B[idx];
    ll len_l = mid - l + 1;
    ll add_val_l = (k * get_sum(l, mid) % Mod + b * len_l % Mod) % Mod;
    add_mod(seg[idx<<1], add_val_l);
    add_mod(K[idx<<1], k);
    add_mod(B[idx<<1], b);

    ll len_r = r - mid;
    ll add_val_r = (k * get_sum(mid + 1, r) % Mod + b * len_r % Mod) % Mod;
    add_mod(seg[idx<<1|1], add_val_r);
    add_mod(K[idx<<1|1], k);
    add_mod(B[idx<<1|1], b);

    K[idx] = 0;
    B[idx] = 0;
}

void update_range(int ql,int qr,ll k,ll b,int idx=1,int l=1,int r=n){
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        ll len = r - l + 1;
        ll add_sum = (k * get_sum(l, r) % Mod + b * len % Mod) % Mod;
        add_mod(seg[idx], add_sum);
        add_mod(K[idx], k);
        add_mod(B[idx], b);
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        update_range(ql,qr,k,b,idx<<1,l,mid);
    else if(ql>mid)
        update_range(ql,qr,k,b,idx<<1|1,mid+1,r);
    else{
        update_range(ql,qr,k,b,idx<<1,l,mid);
        update_range(ql,qr,k,b,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

ll query(int ql,int qr,int idx=1,int l=1,int r=n){
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(mid>=qr)
        return query(ql,qr,idx<<1,l,mid);
    else if(ql>mid)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return (query(ql,qr,idx<<1,l,mid)+query(ql,qr,idx<<1|1,mid+1,r))%Mod;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q, op, l, r;
    ll x;
    cin>>n>>q;
    while(q--){
        cin>>op>>l>>r;
        if(op == 1){
            cin>>x;
            //(i - l + 1) * x
            //xi + (1 - l)x
            //K + B
            ll k = x % Mod;
            ll b = ((1 - l) * x) % Mod;
            if(b < 0)
                b += Mod;
            update_range(l, r, k, b);
        }
        else{
            cout<<query(l, r)<<endl;
        }
    }
}
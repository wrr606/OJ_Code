//Static_Range_Minimum_Queries
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

vll seg;
int n;

void merge(int idx){
    seg[idx]=min(seg[idx<<1],seg[idx<<1|1]);
}

void build(int idx=1,int l=1,int r=n){
    if(l==r){
        cin>>seg[idx];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

ll query(int ql,int qr,int idx=1,int l=1,int r=n){
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(qr<=mid)
        return query(ql,qr,idx<<1,l,mid);
    else if(mid<ql)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return min(query(ql,qr,idx<<1,l,mid),query(ql,qr,idx<<1|1,mid+1,r));
}

int main(){//線段樹
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>n>>q;
    seg.assign(n<<2|1,0);
    build();
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<endl;
    }
}
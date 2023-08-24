//Range_Update_Queries
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

vll seg,tag;
int n;

void merge(int idx){
    seg[idx]=seg[idx<<1]+seg[idx<<1|1];
}

void push_tag(int idx,int l,int r){
    if(tag[idx]){
        int mid=(l+r)>>1;
        seg[idx<<1]+=(mid-l+1)*tag[idx];
        seg[idx<<1|1]+=(r-mid)*tag[idx];
        tag[idx<<1]+=tag[idx];
        tag[idx<<1|1]+=tag[idx];
        tag[idx]=0;
    }
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
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        return seg[idx];
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        return query(ql,qr,idx<<1,l,mid);
    else if(mid<ql)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return query(ql,qr,idx<<1,l,mid)+query(ql,qr,idx<<1|1,mid+1,r);
}

void range_update(int ql,int qr,int val,int idx=1,int l=1,int r=n){
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]+=(r-l+1)*val;
        tag[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        range_update(ql,qr,val,idx<<1,l,mid);
    else if(mid<ql)
        range_update(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        range_update(ql,qr,val,idx<<1,l,mid);
        range_update(ql,qr,val,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

int main(){//segment_tree lazy_tag
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>n>>q;
    seg.assign(n<<2|1,0),tag.assign(n<<2|1,0);
    build();
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int a,b,u;
            cin>>a>>b>>u;
            range_update(a,b,u);
        }
        else{
            int k;
            cin>>k;
            cout<<query(k,k)<<endl;
        }
    }
}
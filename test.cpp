#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
vll seg;

void merge(int idx){
    seg[idx]=seg[idx<<1]+seg[idx<<1|1];
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

ll query(int ql,int qr,int idx,int l,int r){
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(qr<=mid)
        return query(ql,qr,idx<<1,l,mid);
    else if(mid<ql)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return query(ql,qr,idx<<1,l,mid)+query(ql,qr,idx<<1|1,mid+1,r);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    seg.assign((n+5)<<2,0);
    build();
    int m;
    cin>>m;
    while(m--){
        int ql,qr;
        cin>>ql>>qr;
        if(ql > qr) {
            swap(ql, qr);
        }
        cout<<query(ql,qr,1,1,n)<<endl;
    }
}

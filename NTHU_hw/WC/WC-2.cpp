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

constexpr int N = 2e5+5;
int n;
ll seg[N<<2], tag[N<<2];

void merge(int idx){
    seg[idx]=min(seg[idx<<1], seg[idx<<1|1]);
    //區間最大要把return x+y改成max(x,y)
}

void push_tag(int idx,int l,int r){
    if(tag[idx]){
        int mid=(l+r)>>1;
        seg[idx<<1]+=tag[idx];
        seg[idx<<1|1]+=tag[idx];
        tag[idx<<1]+=tag[idx];
        tag[idx<<1|1]+=tag[idx];
        tag[idx]=0;
    }
}

void build(int idx=1,int l=1,int r=n){//創建線段樹
    if(l==r){
        cin>>seg[idx];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

ll query(int ql,int qr,int idx=1,int l=1,int r=n){//區間查詢
    if(l!=r)
        push_tag(idx,l,r);
    //ql~qr為欲查詢的範圍
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(mid>=qr)
        return query(ql,qr,idx<<1,l,mid);
    else if(ql>mid)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return min(query(ql,qr,idx<<1,l,mid), query(ql,qr,idx<<1|1,mid+1,r));
        //區間最大要把return x+y改成max(x,y)
}

void update_range(int ql,int qr,int val,int idx=1,int l=1,int r=n){//區間加值
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]+=val;
        tag[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        update_range(ql,qr,val,idx<<1,l,mid);
    else if(ql>mid)
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        update_range(ql,qr,val,idx<<1,l,mid);
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

void update(int pos,int val,int idx=1,int l=1,int r=n){//單點更新
    if(l==r){
        seg[idx]=val;//max要改成seg[idx]=val
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(pos,val,idx<<1,l,mid);
    else
        update(pos,val,idx<<1|1,mid+1,r);
    merge(idx);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>n>>q;
    build();
    int op, a, b, c;
    while(q--){
        cin>>op>>a;
        if(op == 1)
            cin>>b>>c, update_range(a, b, c);
        else
            cout<<query(a, a)<<endl;
    }
}
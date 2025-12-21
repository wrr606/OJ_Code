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

constexpr int N= 2e5 + 5;
int n;
ll seg[N << 2], add_tag[N << 2], set_tag[N << 2];
bool has_set[N << 2];
//線段樹與懶惰標記

void merge(int idx){
    seg[idx]=seg[idx<<1]+seg[idx<<1|1];
    //區間最大要把return x+y改成max(x,y)
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

void push_tag(int idx,int l,int r){
    if(l == r)
        return;
    const int mid=(l+r)>>1;
    const int L = idx << 1, R = idx << 1 | 1;
    if(has_set[idx]){
        seg[L]=(mid-l+1)*set_tag[idx];//區間最大只需要seg[idx<<1]+=tag[idx];
        seg[R]=(r-mid)*set_tag[idx];//區間最大只需要seg[idx<<1|1]+=tag[idx];
        has_set[L] = has_set[R] = 1;
        set_tag[L] = set_tag[R] = set_tag[idx];
        add_tag[L] = add_tag[R] = 0;
        has_set[idx] = 0;
    }
    if(add_tag[idx]){
        seg[idx<<1]+=(mid-l+1)*add_tag[idx];//區間最大只需要seg[idx<<1]+=tag[idx];
        seg[idx<<1|1]+=(r-mid)*add_tag[idx];//區間最大只需要seg[idx<<1|1]+=tag[idx];
        add_tag[idx<<1]+=add_tag[idx];
        add_tag[idx<<1|1]+=add_tag[idx];
        add_tag[idx]=0;
    }
}

void range_add(int ql,int qr,ll val,int idx=1,int l=1,int r=n){//區間加值
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]+=(r-l+1)*val;
        add_tag[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        range_add(ql,qr,val,idx<<1,l,mid);
    else if(ql>mid)
        range_add(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        range_add(ql,qr,val,idx<<1,l,mid);
        range_add(ql,qr,val,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

void range_set(int ql,int qr,ll val,int idx=1,int l=1,int r=n){//區間加值
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]=(r-l+1)*val;
        set_tag[idx]=val;
        has_set[idx]=1;
        add_tag[idx]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        range_set(ql,qr,val,idx<<1,l,mid);
    else if(ql>mid)
        range_set(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        range_set(ql,qr,val,idx<<1,l,mid);
        range_set(ql,qr,val,idx<<1|1,mid+1,r);
    }
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
        return query(ql,qr,idx<<1,l,mid)+query(ql,qr,idx<<1|1,mid+1,r);
        //區間最大要把return x+y改成max(x,y)
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>n>>q;
    build();
    int op, a, b, c;
    while(q--){
        cin>>op;
        if(op == 1){
            cin>>a>>b>>c;
            range_add(a, b, c);
        }
        else if(op == 2){
            cin>>a>>b>>c;
            range_set(a, b, c);
        }
        else{
            cin>>a>>b;
            cout<<query(a, b)<<endl;
        }
    }
}
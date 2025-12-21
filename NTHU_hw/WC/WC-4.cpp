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

struct Item {
    ll sum, MCS;
    ll prefix_max, postfix_max;
    Item(ll sum= 0)
    : sum(sum), MCS(max(sum, 0LL)), prefix_max(MCS), postfix_max(MCS) {}
    friend Item operator+(const Item&L, const Item&R) {
        Item res(L.sum+ R.sum);
        res.MCS= max({L.MCS, R.MCS, L.postfix_max+ R.prefix_max});
        res.prefix_max= max(L.prefix_max, L.sum+ R.prefix_max);
        res.postfix_max = max(R.postfix_max, R.sum+ L.postfix_max);
        return res;
    }
};

constexpr int N= 2e5 + 5;
int n, init_arr[N];
Item seg[N<<2];
//線段樹與懶惰標記

void merge(int idx){
    seg[idx]=seg[idx<<1]+seg[idx<<1|1];
    //區間最大要把return x+y改成max(x,y)
}

void build(int idx=1,int l=1,int r=n){//創建線段樹
    if(l==r){
        seg[idx] = Item(init_arr[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

auto query(int ql,int qr,int idx=1,int l=1,int r=n){//區間查詢
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

void update(int pos,int val,int idx=1,int l=1,int r=n){//單點更新
    if(l==r){
        seg[idx]=Item(val);//區間最大要改成seg[idx]=val
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
    int q, a, b;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>init_arr[i];
    build();
    while(q--){
        cin>>a>>b;
        update(a, b);
        cout<<query(1, n).MCS<<endl;
    }
}
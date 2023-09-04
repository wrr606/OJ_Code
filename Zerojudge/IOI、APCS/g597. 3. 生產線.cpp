//g597. 3. 生產線
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

int n;
vi seg,tag;

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

void update_range(int ql,int qr,int val,int idx=1,int l=1,int r=n){
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]+=(r-l+1)*val;
        tag[idx]+=val;
        return;
    }
    int mid=(r+l)>>1;
    if(qr<=mid)
        update_range(ql,qr,val,idx<<1,l,mid);
    else if(mid<ql)
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        update_range(ql,qr,val,idx<<1,l,mid);
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

ll query(int ql,int qr,int idx=1,int l=1,int r=n){
    if(l!=r)
        push_tag(idx,l,r);
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
    int m;
    cin>>n>>m;
    seg.assign(n<<2|1,0),tag.assign(n<<2|1,0);
    vi t(n),w(n);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        update_range(a,b,c);
    }
    for(int i=0;i<n;i++){
        w[i]=query(i+1,i+1);
        cin>>t[i];
    }
    sort(w.rbegin(),w.rend()),sort(all(t));
    ll ans=0;
    for(int i=0;i<n;i++)
        ans+=w[i]*t[i];
    cout<<ans<<endl;
}
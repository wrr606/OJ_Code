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
int seg[N<<2];
//線段樹與懶惰標記

void merge(int idx){
    seg[idx]=max(seg[idx<<1], seg[idx<<1|1]);
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

int ans;
void st_bsearch(int pos,int idx=1,int l=1,int r=n){
    if(l==r&&seg[idx]>=pos){
        seg[idx]-=pos;
        ans=l;
        return;
    }
    int mid=(l+r)>>1;
    if(seg[idx<<1]>=pos)
        st_bsearch(pos,idx<<1,l,mid);
    else if(seg[idx<<1|1]>=pos)
        st_bsearch(pos,idx<<1|1,mid+1,r);
    merge(idx);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>n>>q;
    build();
    int num;
    while(q--){
        cin>>num;
        ans = 0;
        st_bsearch(num);
        cout<<ans<<" ";
    }
}
//Hotel_Queries
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

int n,ans;
vll seg;
vi hotel;

void merge(int idx){
    seg[idx]=max(seg[idx<<1],seg[idx<<1|1]);
}

void build(int idx=1,int l=1,int r=n){
    if(l==r){
        seg[idx]=hotel[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

void check_in(int person,int idx=1,int l=1,int r=n){
    if(l==r&&seg[idx]>=person){//避免找到旅館卻不夠房間
        seg[idx]-=person;
        ans=l;
        return;
    }
    int mid=(l+r)>>1;
    if(seg[idx<<1]>=person)//那代表左邊的區間有一個旅館能容納這組客人，往左節點遞迴
        check_in(person,idx<<1,l,mid);
    else if(seg[idx<<1|1]>=person)//代表右邊的區間夠
        check_in(person,idx<<1|1,mid+1,r);
    merge(idx);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    seg.assign(n<<2|1,0),hotel.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>hotel[i];
    build();
    while(m--){
        int person;
        cin>>person;
        ans=0;
        check_in(person);
        cout<<ans<<" ";
    }
}
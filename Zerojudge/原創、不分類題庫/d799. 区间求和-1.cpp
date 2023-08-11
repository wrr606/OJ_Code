//d799. 区间求和
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

void update(vll &BIT,int idx,ll val){
    while(idx<=n){
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}

ll query(const vll &BIT,int idx){
    ll res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=(idx&-idx);
    }
    return res;
}

ll sum(vll &BIT1,vll &BIT2,int idx){
    return query(BIT1,idx)*idx-query(BIT2,idx);
}

void add_range(vll &BIT1,vll &BIT2,int l,int r,ll val){//區間加值
    update(BIT1,l,val);
    update(BIT1,r+1,-val);
    update(BIT2,l,val*(l-1));
    update(BIT2,r+1,-val*r);
}

int main(){//雙BIT 區間插值 區間查詢
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vll num(n+1),BIT1(n+1),BIT2(n+1);
    for(int i=1;i<=n;i++)
        cin>>num[i],add_range(BIT1,BIT2,i,i,num[i]);
    int q,v,x,y,k;
    cin>>q;
    while(q--){
        cin>>v>>x>>y;
        if(v==1){
            cin>>k;
            add_range(BIT1,BIT2,x,y,k);
        }
        else{
            cout<<sum(BIT1,BIT2,y)-sum(BIT1,BIT2,x-1)<<endl;
        }
    }
}
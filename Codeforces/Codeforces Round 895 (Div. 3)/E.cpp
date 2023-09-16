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

const int N=1e5+5;
int n;
ll seg[N<<2],num[N];
//線段樹

void merge(int idx){
    seg[idx]=seg[idx<<1]^seg[idx<<1|1];
    //區間最大要把return x+y改成max(x,y)
}

void build(int idx=1,int l=1,int r=n){//創建線段樹
    if(l==r){
        seg[idx]=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

ll query(int ql,int qr,int idx=1,int l=1,int r=n){//區間查詢
    //ql~qr為欲查詢的範圍
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(mid>=qr)
        return query(ql,qr,idx<<1,l,mid);
    else if(ql>mid)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return query(ql,qr,idx<<1,l,mid)^query(ql,qr,idx<<1|1,mid+1,r);
        //區間最大要把return x+y改成max(x,y)
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,q,op,a,b,xor1,xor0;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        memset(seg,0,sizeof(seg));
        xor1=0,xor0=0;
        for(int i=1;i<=n;i++)
            cin>>num[i];
        build();
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                xor0^=num[i+1];
            else
                xor1^=num[i+1];
        }
        cin>>q;
        while(q--){
            cin>>op;
            if(op==1){
                cin>>a>>b;
                ll temp=query(a,b);
                xor0^=temp; 
                xor1^=temp;
            }
            else{
                cin>>a;
                if(a)
                    cout<<xor1<<" ";
                else
                    cout<<xor0<<" ";
            }
        }
        cout<<endl;
    }
}
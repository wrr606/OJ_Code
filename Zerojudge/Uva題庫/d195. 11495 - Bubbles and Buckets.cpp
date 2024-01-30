//d195. 11495 - Bubbles and Buckets
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

constexpr int N=1e5+5;
int BIT[N],n;
vi d;

inline void update_add(int idx,int val=1){
    while(idx<=n){
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}

inline int query(int idx){
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=(idx&-idx);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    register int num;
    while(cin>>n&&n){
        memset(BIT,0,sizeof(BIT));
        int ans=0;
        for(register int i=0;i<n;i++){
            cin>>num;
            ans+=i-query(num);
            update_add(num);
        }
        if(ans&1)
            cout<<"Marcelo\n";
        else
            cout<<"Carlos\n";
    }
}
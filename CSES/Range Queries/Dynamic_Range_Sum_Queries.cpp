//Dynamic_Range_Sum_Queries
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
typedef vector<vector<int> > vvi;

int n,q;
vll num,BIT;

void update(int index,int val){
    while(index<=n){
        BIT[index]+=val;
        index+=(index&-index);
    }
}

ll query(int index){
    ll res=0;
    while(index>0){
        res+=BIT[index];
        index-=(index&-index);
    }
    return res;
}

int main(){//BIT
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    num.assign(n+1,0),BIT.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>num[i];
        update(i,num[i]);
    }
    while(q--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1)
            update(a,b-num[a]),num[a]=b;
        else
            cout<<query(b)-query(a-1)<<endl;
    }
}
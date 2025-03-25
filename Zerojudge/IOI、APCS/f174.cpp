//f174. m6a2-蛋糕(Cake)
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

const int N=5e5+5;
int prefix[N]={};

int query(const int &a,const int &b){
    return prefix[b]-prefix[a];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>prefix[i];
        prefix[i]+=prefix[i-1];
    }
    deque<int> dq;
    dq.push_back(0);
    for(int i=1;i<=n;i++){
        if(!dq.empty()&&i-dq[0]>k)
            dq.pop_front();
        ans=max(ans,query(dq[0],i));
        while(!dq.empty()&&prefix[dq.back()]>prefix[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<ans;
}
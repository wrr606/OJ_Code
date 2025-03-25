//b606. Add All
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

int main(){//huffman algorithm
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    while(cin>>t&&t){
        ll ans=0;
        priority_queue<ll,vector<ll>,greater<ll> > pq;
        for(int i=0;i<t;i++){
            cin>>n;
            pq.push(n);
        }
        while(pq.size()>1){
            ll x,y;
            x=pq.top(),pq.pop();
            y=pq.top(),pq.pop();
            pq.push(x+y),ans+=x+y;
        }
        cout<<ans<<endl;
    }
}
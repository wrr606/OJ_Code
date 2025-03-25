//e346. 區間和練習
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

ll prefix[200005];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>prefix[i],prefix[i]+=prefix[i-1];
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
}
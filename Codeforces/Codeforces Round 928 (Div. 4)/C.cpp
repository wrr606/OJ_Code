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

constexpr int N=2e5+5;
int pre[N]={};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    for(int i=1;i<N;i++){
        s=to_string(i);
        for(const auto &j:s)
            pre[i]+=j-48;
        pre[i]+=pre[i-1];
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<pre[n]<<endl;
    }
}
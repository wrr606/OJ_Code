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

priority_queue<int> mx;
priority_queue<int, vi, greater<>> mn;

int get_mid(int n){
    if(n&1)
        return mx.top();
    else
        return mn.top() + mx.top() >> 1;
}

void adjust(){
    mn.emplace(mx.top()), mx.pop();
    if(mx.size() < mn.size())
        mx.emplace(mn.top()), mn.pop();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n = 0, k, mid;
    while(cin>>k){
        if(n++ == 0){
            mx.emplace(k);
            cout<<k<<endl;
            continue;
        }
        mx.emplace(k);
        adjust();
        cout<<get_mid(n)<<endl;
    }
}
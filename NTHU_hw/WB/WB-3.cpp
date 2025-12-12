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
 
bool cmp(pii a,pii b){
    if(a.second==b.second)
        return a.first>b.first;
    return a.second<b.second;
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pii> movie(n);
    for(auto &i:movie)
        cin>>i.first>>i.second;
    sort(all(movie),cmp);
    multiset<int> idle;
    int ans=0;
    for(int i=0;i<k;i++)
        idle.insert(-1);
    for(const auto &i:movie){
        auto iter=idle.upper_bound(i.first);
        if(iter==idle.begin())
            continue;
        else{
            idle.erase(--iter);
            idle.insert(i.second);
            ans++;
        }
    }
    cout<<ans;
}
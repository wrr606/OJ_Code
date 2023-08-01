//Subarray_Divisibility
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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vll sum(n);
    cin>>sum[0];
    for(int i=1;i<n;i++)
        cin>>sum[i],sum[i]+=sum[i-1];
    unordered_map<ll,int> check;
    ll ans=0;
    check[0]=1;
    for(const auto &i:sum){
        int key=(i%n+n)%n;
        ans+=check[key];
        check[key]++;
    }
    cout<<ans;
}
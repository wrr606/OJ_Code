//f855. 第 3 題 線段覆蓋長度 測資加強版
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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<pii> lines(n);
    for(auto &i:lines)
        cin>>i.first>>i.second;
    sort(all(lines));
    int r=0,ans=0;
    for(const auto &i:lines){
        if(i.second>=r){
            if(i.first>=r){
                ans+=i.second-i.first;
            }
            else{
                ans+=i.second-r;
            }
            r=i.second;
        }
    }
    cout<<ans<<endl;
}
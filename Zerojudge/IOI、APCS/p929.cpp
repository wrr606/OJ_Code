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
    int n, m, p, q;
    cin>>n>>m>>p>>q;
    vvi arr(n, vi(m));
    for(auto &i: arr){
        for(auto &j: i)
            cin>>j;
    }
    for(const auto &i: arr){
        for(int b = 0; b < p; b++){
            for(const auto &j: i){
                for(int a = 0; a < q; a++)
                    cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}
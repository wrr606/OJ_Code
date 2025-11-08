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

constexpr int MAXN = 1e6 + 5;
ll arr[MAXN], prefix[MAXN];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        partial_sum(arr, arr + n, prefix + 1);
        for(int i=0;i<=n;i++)
            cout<<prefix[i]<<" ";cout<<endl;
        vi inc, dec;
        int ans = 0;
        for(int i=0;i<=n;i++){
            while(!inc.empty() && prefix[inc.back()] > prefix[i])
                inc.pop_back();
            inc.emplace_back(i);
            while(!dec.empty() && prefix[dec.back()] <= prefix[i])
                dec.pop_back();
            dec.emplace_back(i);
            if(dec.size() == 1 && dec[0] >= 0){
                ans = max(ans, inc.back() - inc[0]);
            }
        }
        cout<<ans<<endl;
    }
}
/*
  -1 0 0 -1 0
0 -1 -1 -1 -2 -2
0 -1
-1 -1 -1

  -6 -4 -1 0 5 1 9 -8 -3 4
0 -6 -10 -11 -11 -6 -5 4 -4 -7 -3 
4
-11 -11 -6 -5 4
*/
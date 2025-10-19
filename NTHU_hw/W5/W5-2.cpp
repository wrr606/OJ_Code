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

#define int long long int

constexpr int MAXN = 1e5 + 5;
int arr[MAXN], n;

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n){
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        stack<pii, vector<pii>> stk;
        int ans = INT_MIN;
        for(int i = 0; i < n + 1; i++){
            int final_pop = i;
            while(!stk.empty() && stk.top().first >= arr[i]){
                const auto top = stk.top();
                ans = max(ans, (i - top.second) * top.first);
                final_pop = top.second;
                stk.pop();
            }
            stk.emplace(arr[i], final_pop);
        }
        cout<<ans<<endl;
    }
}
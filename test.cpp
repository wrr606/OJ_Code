#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    vi nums={41,33,29,33,35,26,47,24,18,28};
    sort(all(nums));
    for(auto i:nums)
        cout<<i<<" ";
        cout<<endl;
    const int length = nums.size() - 1;
    for(const auto &i:nums){
        auto mn=lower_bound(all(nums),i-length),mx=upper_bound(all(nums),i-length);
        
    }
}
//Array_Division
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
constexpr int MAXN = 2e5 + 1;
int n, k, arr[MAXN];

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    for(int i=0, idx=0;i<n;i++){
        cin>>arr[i];
    }
    const auto greed = [&](const int &mx){
        int cnt = 0, t = 0;
        for(int i=0;i<n;i++){
            t += arr[i];
            if(t > mx)
                t = arr[i], ++cnt;
        }
        if(t)
            ++cnt;
        return cnt > k;
    };
    int L = *max_element(arr, arr + n), R = accumulate(arr, arr + n, 0LL);
    while(L + 1 < R){
        if(greed(R)){
            L = R, R = R + 1;
            break;
        }
        if(!greed(L)){
            R = L, L = L - 1;
            break;
        }
        const int mid = L + (R - L >> 1);
        if(greed(mid))
            L = mid;
        else
            R = mid;
    }
    cout<<R<<endl;
}
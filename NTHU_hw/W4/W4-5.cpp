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
int n, c, arr[MAXN];

inline ld f(const ld &p){
    ld res = 0;
    for(int i=0;i<n;i++){
        res += (p - arr[i]) * (p - arr[i]);
    }
    return res;
}

inline ld get_slope(const ld &p){
    constexpr ld eps = 1e-10;
    return (f(p + eps) - f(p)) / eps;
}

void my_binary_search(ld &L, ld &R, const auto &check){
    constexpr ld eps = 1e-9;
    if(check(R) == 1)    L = R, R = R + eps;
    if(check(L) == 0)    R = L, L = L - eps;
    while(L + eps < R){
        const ld mid = L + (R - L) / 2;
        if(check(mid) == 1)
            L = mid;
        else
            R = mid;
    }
}

void my_ternary_search(ld &L, ld &R){
    constexpr ld eps = 1e-10;
    while(L + eps < R){
        const ld mL = L + (R - L) / 3, 
                 mR = R - (R - L) / 3;
        if(f(mL) > f(mR))
            L = mL;
        else
            R = mR;
    }
}

signed main(){
    scanf("%lld%lld",&n,&c);
    int ans = 0, y;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&arr[i],&y);
        ans += (c - y) * (c - y);
    }
    ld L = -1e6, R = 1e6;
    my_ternary_search(L, R);
    printf("%.15Lf", ans + f(R));
}
/*
873.769230769230717
873.769230769230769
*/
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

inline int my_ceil(const int &a, const int &b){
    return (a + b - 1) / b;
}

int speed, gas_speed, gas_cost, gas_refill, gas_init, length, total_time;

int usage_time(const int &t){
    int max_dis = INT_MIN;
    for(int special_time=0;special_time<=t;special_time++){
        const int need_refill_time = max(0LL, my_ceil((special_time * gas_cost - gas_init), gas_refill));
        if(special_time + need_refill_time > t)
            continue;
        const int dis = gas_speed * special_time + (t - special_time - need_refill_time) * speed;
        max_dis = max(max_dis, dis);
    }
    return max_dis;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>speed>>gas_speed>>gas_cost>>gas_refill;
    cin>>gas_init>>length>>total_time;
    if(usage_time(total_time) < length){
        cout<<"No\n"<<usage_time(total_time);
        return 0;
    }
    int L = 0, R = total_time;
    while(L < R){
        const int mid = L + ((R - L) >> 1);
        if(usage_time(mid) <= length)
            L = mid + 1;
        else
            R = mid;
    }
    cout<<"Yes\n"<<R;
}
/*
17 60 10 4
39 200 4
*/
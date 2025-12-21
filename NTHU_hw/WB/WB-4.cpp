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

constexpr int MAXN = 2e5 + 5;
struct Project{
    int start, end;
    ll reward;
    bool operator<(const Project &other){
        return start < other.start;
    }
};

int n;
ll dp[MAXN<<1];
Project projects[MAXN];

template <typename T>
auto get_unique_sorted(vector<T> arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

template <typename T>
auto get_rank(const vector<T> &unique_sorted, const T &x) {
    return lower_bound(unique_sorted.begin(), unique_sorted.end(), x) - unique_sorted.begin();
}
#define get_rk(x) get_rank(time_line, x)

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vi time_line;
    for(int i=0;i<n;i++){
        cin>>projects[i].start>>projects[i].end>>projects[i].reward;
        time_line.emplace_back(projects[i].start);
        time_line.emplace_back(projects[i].end);
    }
    time_line = get_unique_sorted(time_line);
    // for(auto i:time_line)
    //     cout<<i<<" ";cout<<endl;
    sort(projects, projects + n);
    ll ans = 0;
    for(int i = 0, day = 0; i < n; i++){
        const auto &[start, end, reward] = projects[i];
        while(day < get_rk(start) - 1){
            day++;
            dp[day] = max(dp[day], dp[day - 1]);
        }
        dp[get_rk(end)] = max(
            dp[get_rk(end)], dp[get_rk(start) - 1] + reward
        );
        ans = max(ans, dp[get_rk(end)]);
    }
    cout<<ans;
}
/*
4
2 4 4
3 6 6
5 7 3
6 8 2
*/
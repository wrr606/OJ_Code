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

constexpr int n = 3;
constexpr pair<int,int> swaps[] = {
    {0, 1}, {1, 2},
    {3, 4}, {4, 5},
    {6, 7}, {7, 8},

    {0, 3}, {1, 4}, {2, 5},
    {3, 6}, {4, 7}, {5, 8}
};
constexpr string_view perfect_s = "123456789";

inline bool check(const auto &a, const auto &b){
    return (0 <= a && a < n) && (0 <= b && b < n);
}

int BFS(string_view s){
    queue<pair<int, string>> que;
    unordered_set<string> visited;
    que.emplace(0, s);
    visited.emplace(s);
    while(que.size()){
        auto [cnt, cur] = que.front();
        que.pop();
        if(cur == perfect_s)
            return cnt;
        ++cnt;
        for(const auto &[i, j]: swaps){
            swap(cur[i], cur[j]);
            if(!visited.count(cur))
                que.emplace(cnt, cur), visited.emplace(cur);
            swap(cur[i], cur[j]);
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    string s;
    for(int i=0;i<9;i++){
        cin>>t;
        s += to_string(t);
    }
    cout<<BFS(s);
}
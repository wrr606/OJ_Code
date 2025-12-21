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

constexpr ll MAXN = 1e5 + 5;
int n;
vector<array<int, 3>> routes[MAXN];
//a b next_node

ll Dijkstra(const int x){
    priority_queue<pll,vector<pll>,greater<>> pq;
    vll ans(n + 1, 1e16);
    pq.emplace(0, 1), ans[1]=0;
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(cur.first>ans[cur.second])
            continue;
        for(const auto &i:routes[cur.second]){
            const ll w = (ll)i[0] * x + i[1];
            if(ans[i[2]]>cur.first+w){
                ans[i[2]] = cur.first+w;
                pq.emplace(ans[i[2]], i[2]);
            }
        }
    }
    return ans[n];
}

template <class Ty, class FuncTy>
Ty find_max_true(Ty L, Ty R, FuncTy check){
    while (L < R) {
        Ty mid = L + (R - L + 1) / 2;
        if (check(mid))
            L = mid;
        else
            R = mid - 1;
    }
    return L;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q, k;
    cin>>n>>q>>k;
    while(q--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        routes[a].push_back({c, d, b});
    }
    if(Dijkstra(0) >= k){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<find_max_true(0LL, 2000000000LL, [&](const int x){
        return Dijkstra(x) < k;
    });
}
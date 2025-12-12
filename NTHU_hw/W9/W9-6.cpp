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

vi cycle;

struct Edge{
    int start, end, cost;
};

void Bellman_Ford(auto& ans, const vector<Edge> &routes, int n, int start = 1){
    ans[start] = 0;
    auto relax = [&](const Edge &a){
        if(ans[a.end] > ans[a.start] + a.cost){
            ans[a.end] = ans[a.start] + a.cost;
            return 1;
        }
        return 0;
    };
    for(int t = 1; t < n; t++){
        bool update = 0;
        for(const auto &e: routes)
            update |= relax(e);
    }
    for(const auto &e: routes){
        if(relax(e))
            cycle.emplace_back(e.end);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<Edge> routes(m);
    for(auto &[s, e, c]: routes){
        cin>>s>>e>>c;
        c = -c;
    }
    vll ans(n + 1, 1e18);
    Bellman_Ford(ans, routes, n);
    // for(auto i:ans|views::drop(1))
    //     cout<<i<<" ";cout<<endl;
    if(cycle.empty()){
        if(ans[n] == 1e18)
            cout<<-1;
        else
            cout<<-ans[n];
        return 0;
    }
    
    vvi t(n + 1);
    for(const auto &[s, e, _]: routes)
        t[s].emplace_back(e);
    queue<int> que;
    vb visited(n + 1);
    for(const auto &i: cycle)
        que.emplace(i), visited[i] = 1;
    while(que.size()){
        int cur = que.front();
        que.pop();
        if(cur == n){
            cout<<-1;
            return 0;
        }
        for(const auto &i: t[cur]){
            if(!visited[i]){
                visited[i] = 1;
                que.emplace(i);
            }
        }
    }
    if(ans[n] == 1e18)
        cout<<-1;
    else
        cout<<-ans[n];
}
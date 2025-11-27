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

constexpr int N = 2e5 + 5;
vi routes[N];

int dis[2][N];
void DFS(const int cur = 1, const int last = 0, const int cur_dis = 0, const int types = 0){
    dis[types][cur] = cur_dis;
    for(const auto &i: routes[cur]){
        if(i != last)
            DFS(i, cur, cur_dis + 1, types);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, a, b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        routes[a].emplace_back(b);
        routes[b].emplace_back(a);
    }
    DFS();
    const int A = max_element(dis[0] + 1, dis[0] + n + 1) - dis[0];
    DFS(A);
    const int B = max_element(dis[0] + 1, dis[0] + n + 1) - dis[0];
    DFS(B, 0, 0, 1);
    for(int i=1;i<=n;i++){
        cout<<max(dis[0][i], dis[1][i])<<" ";
    }
    // cout<<endl<<A<<" "<<B<<endl;
}
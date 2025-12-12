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
int n, colors[MAXN];
vi routes[MAXN];
bool many = 0;

void DFS(const int cur, int color){
    if(many)
        return;
    colors[cur] = color;
    color = (color == 1) ? 2 : 1;
    for(const auto &i: routes[cur]){
        if(colors[i] != -1 && colors[i] != color){
            many = 1;
            return;
        }
        if(colors[i] == -1)
            DFS(i, color);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a, b, m;
    cin>>n>>m;
    memset(colors, -1, sizeof(colors));
    while(m--){
        cin>>a>>b;
        routes[a].emplace_back(b);
        routes[b].emplace_back(a);
    }
    for(int i=1;i<=n;i++){
        if(colors[i] == -1)
            DFS(i, 1);
    }
    if(many)
        cout<<"MANY";
    else{
        for(int i=1;i<=n;i++)
            cout<<colors[i]<<" ";
    }
}
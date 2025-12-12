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
 
constexpr int N=1e5+5;
vector<pii> routs[N];
ll dis[N]={};
 
void Dijkstra(){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        pll cur=pq.top();
        pq.pop();
        if(cur.first>dis[cur.second])
            continue;
        for(const auto &i:routs[cur.second]){
            if(dis[i.second]>i.first+cur.first){
                dis[i.second]=i.first+cur.first;
                pq.push({dis[i.second],i.second});
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    fill(dis+1,dis+1+n,LONG_LONG_MAX);
    dis[1]=0;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        routs[a].push_back({c,b});
    }
    Dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
}
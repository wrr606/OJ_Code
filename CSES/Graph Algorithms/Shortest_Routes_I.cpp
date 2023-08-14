//Shortest_Routes_I
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

int n;
vector<vector<pii>> routs;
vll ans;

void Dijkstra(){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({INT_MIN,1});
    while(!pq.empty()){
        pll cur=pq.top();
        pq.pop();
        if(cur.first>ans[cur.second])
            continue;
        for(const auto &i:routs[cur.second]){
            if(ans[i.second]>ans[cur.second]+i.first){
                ans[i.second]=ans[cur.second]+i.first;
                pq.push({ans[i.second],i.second});
            }
        }
    }
}

int main(){//Dijkstra
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    routs.assign(n+1,vector<pii>()),ans.assign(n+1,LONG_LONG_MAX);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        routs[a].push_back({c,b});
    }
    ans[1]=0;
    Dijkstra();
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}
//10986 - Sending email
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

constexpr int N=2e4+5;
vector<pii> routs[N];
int dis[N];

void Dijkstra(const int &s,const int &t){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pii cur=pq.top();
        pq.pop();
        if(dis[cur.second]<cur.first)
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
    int x,n,m,s,t;
    cin>>x;
    for(int c=1;c<=x;c++){
        cin>>n>>m>>s>>t;
        for(int i=0;i<n;i++)
            routs[i].clear();
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            routs[a].push_back({c,b});
            routs[b].push_back({c,a});
        }
        fill(dis,dis+n,INT_MAX);
        dis[s]=0;
        Dijkstra(s,t);
        cout<<"Case #"<<c<<": ";
        if(dis[t]==INT_MAX)
            cout<<"unreachable\n";
        else
            cout<<dis[t]<<endl;
    }
}
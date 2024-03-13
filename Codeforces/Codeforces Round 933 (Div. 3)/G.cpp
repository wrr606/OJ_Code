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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pii>> routs(n + m + 1, vector<pii>());
        map<int,int> check;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(!check.count(c))
                check[c]=++n;
            c=check[c];
            routs[c].emplace_back(0,a);
            routs[c].emplace_back(0,b);
            routs[a].emplace_back(1,c);
            routs[b].emplace_back(1,c);
        }
        int s,e;
        cin>>s>>e;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<int> dis(n + 1, INT_MAX);
        pq.emplace(0,s),dis[s]=0;
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            if(cur.first>dis[cur.second])
                continue;
            for(const auto &i:routs[cur.second]){
                if(dis[i.second]>i.first+cur.first){
                    dis[i.second]=i.first+cur.first;
                    pq.emplace(dis[i.second],i.second);
                }
            }
        }
        cout<<dis[e]<<endl;
    }
}
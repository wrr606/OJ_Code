//Flight_Discount
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

const int N=100005;
int n;
vector<pair<ll,int>> routs[N];
vector<vll> ans(2,vll(N,LONG_LONG_MAX));

void Dijkstra(){
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> pq;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        auto cur=pq.top();
        //cout<<cur.first<<" "<<cur.second.second<<" "<<cur.second.first<<endl;
        pq.pop();
        if(cur.first>ans[cur.second.second][cur.second.first])
            continue;
        for(const auto &i:routs[cur.second.first]){
            if(cur.first+i.first<ans[cur.second.second][i.second]){
                ans[cur.second.second][i.second]=cur.first+i.first;
                pq.push({ans[cur.second.second][i.second],{i.second,cur.second.second}});
            }
            if(cur.second.second==0){
                if(cur.first+i.first/2<ans[1][i.second]){
                    ans[1][i.second]=cur.first+i.first/2;
                    pq.push({ans[1][i.second],{i.second,1}});
                }
            }
        }
    }
}

int main(){//Dijkstra
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        routs[a].push_back({c,b});
    }
    ans[0][1]=0;
    Dijkstra();
    cout<<ans[1][n];
}
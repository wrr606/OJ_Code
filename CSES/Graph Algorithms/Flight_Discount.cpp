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

constexpr int N=100005;
int n;

struct node{
    ll cost;
    int point,sale;
    bool operator<(const node &other)const{
        return cost>other.cost;
    }
};

vector<node> routs[N];
ll ans[N][2];

void Dijkstra(){
    priority_queue<node> pq;
    pq.push({0,1,0});
    while(!pq.empty()){
        node cur=pq.top();
        pq.pop();
        if(cur.cost>ans[cur.point][cur.sale])
            continue;
        for(const auto &i:routs[cur.point]){
            if(ans[i.point][cur.sale]>cur.cost+i.cost){
                ans[i.point][cur.sale]=cur.cost+i.cost;
                pq.push({ans[i.point][cur.sale],i.point,cur.sale});
            }
            if(cur.sale==0){
                if(ans[i.point][1]>cur.cost+i.cost/2){
                    ans[i.point][1]=cur.cost+i.cost/2;
                    pq.push({ans[i.point][1],i.point,1});
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
    for(int i=1;i<=n;i++)
        ans[i][0]=LONG_LONG_MAX,ans[i][1]=LONG_LONG_MAX;
    ans[1][0]=0;
    Dijkstra();
    cout<<ans[n][1];
}
//Cycle_Finding
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

constexpr short int N=1005;
vector<pii> routs[N];
int dis[N],n,cnt[N];

bool SPFA(const int &start){
    fill(dis,dis+n,1e9);
    memset(cnt,0,sizeof(cnt));
    dis[start]=0;
    queue<int> que;
    bitset<N> in_que;
    que.push(start);
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        cnt[cur]++;
        if(cnt[cur]>n){
            return 1;
        }
        in_que[cur]=0;
        for(const auto &i:routs[cur]){
            if(dis[i.second]>dis[cur]+i.first){
                dis[i.second]=dis[cur]+i.first;
                if(!in_que[i.second]){
                    que.push(i.second);
                    in_que[i.second]=1;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        short int m;
        for(int i=0;i<n;i++)
            routs[i].clear();
        cin>>n>>m;
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            routs[a].push_back({c,b});
        }
        if(SPFA(0))
            cout<<"possible\n";
        else
            cout<<"not possible\n";
    }
}
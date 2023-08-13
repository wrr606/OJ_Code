//Building_Teams
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
vector<set<int>> routs;
bitset<100005> visited,teams;
bool IMPOSSIBLE=0;

void DFS(int num,bool color=0){
    visited[num]=1;
    teams[num]=color;
    for(const auto &i:routs[num]){
        if(visited[i]&&teams[i]!=(!color)){
            IMPOSSIBLE=1;
            return;
        }
        if(!visited[i])
            DFS(i,!color);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    routs.assign(n+1,set<int>());
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        routs[a].insert(b);
        routs[b].insert(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    if(IMPOSSIBLE){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n;i++)
        cout<<teams[i]+1<<" ";
}
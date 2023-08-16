//d768. 10004 - Bicoloring
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
vvi routs;
bitset<205> visited,color;
bool found=1;

void DFS(int cur,bool cur_color=0){
    if(!found)
        return;
    visited[cur]=1;
    color[cur]=cur_color;
    for(const auto &i:routs[cur]){
        if(visited[i]&&color[i]==cur_color){
            found=0;
            return;
        }
        if(!visited[i]){
            DFS(i,!cur_color);
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n&&n){
        found=1;
        int m;
        cin>>m;
        routs.assign(n+1,vi()),visited.reset(),color.reset();
        while(m--){
            int a,b;
            cin>>a>>b;
            routs[a].push_back(b);
            routs[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                DFS(i);
            }
        }
        if(found)
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
    }
}
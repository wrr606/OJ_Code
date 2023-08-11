//Building_Roads
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

vector<set<int>> city;
bitset<100005> visited;

void DFS(int cur){
    visited[cur]=1;
    for(const auto &i:city[cur]){
        if(!visited[i])
            DFS(i);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    city.assign(n+1,set<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        city[a].insert(b);
        city[b].insert(a);
    }
    vi ans;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++)
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
}
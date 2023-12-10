//a523. 12442 - Forwarding Emails
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

int routs[50005];
pii cnt;
bitset<50005> visited,DFS_visited;

void DFS(int cur){
    if(DFS_visited[cur])
        return;
    visited[cur]=1,DFS_visited[cur]=1;
    cnt.second++;
    DFS(routs[cur]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a,b;
            visited[i]=0;
            cin>>a>>b;
            routs[a]=b;
        }
        pii ans={0,0};
        for(int i=1;i<=n;i++){
            if(visited[i])
                continue;
            cnt={i,0};
            DFS_visited.reset();
            DFS(i);
            if(ans.second<cnt.second)
                ans=cnt;
            else if(ans.second==cnt.second)
                ans.first=min(ans.first,cnt.first);
        }
        cout<<"Case "<<c<<": "<<ans.first<<endl;
    }
}
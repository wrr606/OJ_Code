//Message_Route
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

int n,path[100005];
vector<set<int>> routs;
bitset<100005> visited;

void BFS(){
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int cur=que.front();
        if(cur==n)
            return;
        que.pop();
        for(const auto &i:routs[cur]){
            if(!visited[i]){
                visited[i]=1;
                que.push(i);
                path[i]=cur;
            }
        }
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
    BFS();
    if(!path[n]){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vi ans={n};
    while(n!=1){
        ans.push_back(path[n]);
        n=path[n];
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" "; 
}
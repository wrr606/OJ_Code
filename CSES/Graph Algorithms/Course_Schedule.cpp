//Course_Schedule
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
vvi out;
vi in,ans;

void Topological_sorting(){
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            que.push(i);
        }
    }
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        ans.push_back(cur);
        for(const auto &i:out[cur]){
            in[i]--;
            if(!in[i])
                que.push(i);
        }
    }
}

int main(){//拓樸排序
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    out.assign(n+1,vi()),in.assign(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        out[a].push_back(b);
        in[b]++;
    }
    Topological_sorting();
    if(ans.size()!=n)
        cout<<"IMPOSSIBLE";
    else
        for(const auto &i:ans)
            cout<<i<<" ";
}
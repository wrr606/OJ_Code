//f167. m4a1-社團 Club
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
vi in,ans;
vvi routs;

void BFS(){
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!in[i])
            que.push(i);
    }
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        ans.push_back(cur);
        for(const auto &i:routs[cur]){
            in[i]--;
            if(!in[i])
                que.push(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    in.assign(n+1,0),routs.assign(n+1,vi());
    while(m--){
        int a,b;
        cin>>a>>b;
        routs[a].push_back(b);
        in[b]++;
    }
    BFS();
    if(ans.size()==n){
        cout<<"YES\n";
        for(const auto &i:ans)
            cout<<i<<endl;
    }
    else
        cout<<"NO\n";
}
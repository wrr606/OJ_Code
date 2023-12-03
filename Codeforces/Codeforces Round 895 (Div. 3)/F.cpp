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

const int N=2e5+5;
bitset<N> visisted;
vi ans;
int money[N],in[N],n,out[N];
pii mn;

void Topological_sorting(){
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!in[i])
            que.push(i),visisted[i]=1;
    }
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        ans.push_back(cur);
        in[out[cur]]--;
        if(!in[out[cur]])
            que.push(out[cur]),visisted[out[cur]]=1;
    }
}

void DFS(int cur){
    visisted[cur]=1;
    if(mn.second>money[cur])
        mn={cur,money[cur]};
    if(!visisted[out[cur]])
        DFS(out[cur]);
}

void cycle(){
    int cur=out[mn.first];
    while(mn.first!=cur){
        ans.push_back(cur);
        cur=out[cur];
    }
    ans.push_back(cur);
}

int main(){//拓樸排序 DFS
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        //初始化
        memset(in,0,sizeof(in)),ans.clear(),visisted.reset();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>out[i];
            in[out[i]]++;
        }
        for(int i=1;i<=n;i++)
            cin>>money[i];
        Topological_sorting();
        for(int i=1;i<=n;i++){
            if(!visisted[i]){
                mn={i,money[i]};
                DFS(i);
                cycle();
            }
        }
        for(const auto &i:ans)
            cout<<i<<" ";
        cout<<endl;
    }
}
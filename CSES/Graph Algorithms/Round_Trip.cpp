    //Round_Trip
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

    int n,visited[100005],pre[100005];
    vector<set<int>> routs;
    bool find_it=0;

    void print_cycle(int end,int start){
        if(find_it)
            return;
        vi ans={start};
        while(end!=start){
            ans.push_back(end);
            end=pre[end];
        }
        ans.push_back(start);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i]<<" ";
    }

    void DFS(int cur,int last=0){
        if(find_it)
            return;
        visited[cur]=1;
        for(const auto &i:routs[cur]){
            if(i==last)
                continue;
            if(visited[i]==0){
                pre[i]=cur;
                DFS(i,cur);
            }
            else if(visited[i]==1){
                print_cycle(cur,i);
                find_it=1;
                return;
            }
        }
        visited[cur]=2;
    }

    int main(){
        ios::sync_with_stdio(0),cin.tie(0);
        int m;
        cin>>n>>m;
        routs.assign(n+1,set<int>());
        while(m--){
            int a,b;
            cin>>a>>b;
            routs[a].insert(b);
            routs[b].insert(a);
        }
        for(int i=1;i<=n;i++){
            if(find_it)
                break;
            if(!visited[i])
                DFS(i);
        }
        if(!find_it)
            cout<<"IMPOSSIBLE";
    }
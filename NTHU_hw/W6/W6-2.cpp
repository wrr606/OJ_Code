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

int n, q;
vi capacity;
set<vi> visited;

int BFS(){
    queue<pair<int, vi>> que;
    que.emplace(0, vi(n, 0));
    while(que.size()){
        auto [cnt, cur] = move(que.front());
        // cout<<cnt<<endl;
        // for(auto i:cur)
        //     cout<<i<<" ";cout<<endl;
        que.pop();
        if(visited.count(cur))
            continue;
        if(find(all(cur), q) != cur.end())
            return cnt;
        ++cnt;
        for(int i=0;i<n;i++){
            vi t = cur;
            //Pick a jug and fill it to full.
            t[i] = capacity[i];
            que.emplace(cnt, t), t = cur;

            //Pick a jug and empty it.
            t[i] = 0;
            que.emplace(cnt, t), t = cur;
            for(int j=0;j<n;j++){
                //Pick two jugs and transfer water
                if(i == j)
                    continue;
                t[j] = min(capacity[j], cur[i] + cur[j]);
                t[i] = cur[i] + cur[j] - t[j];
                que.emplace(cnt, t), t = cur;
            }
        }
        visited.emplace(cur);
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    capacity.resize(n);
    for(auto &i: capacity)
        cin>>i;
    cin>>q;
    cout<<BFS();
}
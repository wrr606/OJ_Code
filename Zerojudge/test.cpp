#include<bits/stdc++.h>
using namespace std;

const int maxd = 200 + 5;
int a, b, c, d;
int vis[maxd][maxd];
int ans[maxd];


struct Node{
    int x[3];
    int dist;
    bool operator<(const Node& node)const{
        return dist > node.dist;
    }
};

void update_ans(const Node& node)
{
    for(int i = 0; i < 3; i++){
        int x = node.x[i];
        if(ans[x] < 0 || node.dist < ans[x]){
            ans[x] = node.dist;
        }
    }
}

void solve()
{
    memset(ans, -1, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    int cap[3] = {a, b, c};
    Node start;
    start.x[0] = 0, start.x[1] = 0, start.x[2] = c;
    start.dist = 0;
    priority_queue<Node>pq;
    pq.push(start);
    vis[0][0] = 1;
    while(!pq.empty()){
        Node u = pq.top(); pq.pop();
        update_ans(u);
        if(ans[d] >= 0){
            break;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) if(i != j){  //if i -> i, it will get into dead loop
                //i->j
                if(u.x[i] == 0 || u.x[j] == cap[j]) continue;
                int amount = min(cap[j], u.x[i] + u.x[j]) - u.x[j];
                Node v;
                memcpy(&v, &u, sizeof(u));
                v.x[i] -= amount;
                v.x[j] += amount;
                v.dist = u.dist + amount;
                if(!vis[v.x[0]][v.x[1]]){
                    vis[v.x[0]][v.x[1]] = 1;
                    pq.push(v);
                }
            }
        }
    }
    while(d >= 0){
        if(ans[d] >= 0){
            cout << ans[d] << ' ' << d << endl;
            return;
        }
        d--;
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d;
        solve();
    }
    return 0;
}
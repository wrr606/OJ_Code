//d793. 00929 - Number Maze
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

int n,m,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vvi maze;
vector<vll> ans;

void dijkstra(){
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> pq;
    pq.push({LONG_LONG_MIN,0,0});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        int x=cur[1],y=cur[2];
        if(cur[0]>ans[x][y])
            continue;
        for(int i=0;i<4;i++){
            int nx=cur[1]+dir[i][0],ny=cur[2]+dir[i][1];
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            //out<<maze[nx][ny]<<" "<<ans[x][y]<<" "<<ans[nx][ny]<<endl;
            if(maze[nx][ny]+ans[x][y]<ans[nx][ny]){
                ans[nx][ny]=maze[nx][ny]+ans[x][y];
                pq.push({ans[nx][ny],nx,ny});
            }
        }
    }
}

int main(){//dijkstra
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        maze.assign(n,vi(m)),ans.assign(n,vll(m,LONG_LONG_MAX));
        for(auto &i:maze){
            for(auto &j:i){
                cin>>j;
            }
        }
        ans[0][0]=maze[0][0];
        dijkstra();
        cout<<ans[n-1][m-1]<<endl;
    }
}
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
 
struct node{
    int x,y,length;
};
 
vs labyrinth;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},path[1005][1005],n,m;
vector<pii> monsters;
vvi check_map;
string ans="",dir_chr=" UDLR";
pii A;
 
void print_ans(pii B){
    while(A!=B){
        ans+=dir_chr[path[B.first][B.second]];
        B={B.first-dir[path[B.first][B.second]-1][0],B.second-dir[path[B.first][B.second]-1][1]};
    }
    reverse(all(ans));
}
 
void Monsters_BFS(){
    vector<bitset<1005>> visited(n);
    queue<node> que;
    for(const auto &i:monsters)
        que.push({i.first,i.second,0});
    while(!que.empty()){
        node cur=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int x=cur.x+dir[i][0],y=cur.y+dir[i][1];
            if(x<0||x>=n||y<0||y>=m||visited[x][y]||labyrinth[x][y]=='#')
                continue;
            check_map[x][y]=min(check_map[x][y],cur.length+1);
            visited[x][y]=1;
            que.push({x,y,cur.length+1});
        }
    }/*
    for(auto i:check_map){
        for(auto j:i)
            cout<<j;
        cout<<endl;
    }*/
}
 
void Excape_BFS(){
    vector<bitset<1005>> visited(n);
    queue<node> que;
    que.push({A.first,A.second,0});
    while(!que.empty()){
        node cur=que.front();
        if(cur.x==0||cur.y==0||cur.x==n-1||cur.y==m-1){
            cout<<"YES\n";
            print_ans({cur.x,cur.y});
            cout<<ans.size()<<endl;
            cout<<ans;
            return;
        }
        que.pop();
        for(int i=0;i<4;i++){
            int x=cur.x+dir[i][0],y=cur.y+dir[i][1];
            if(x<0||x>=n||y<0||y>=m||visited[x][y]||check_map[x][y]<=cur.length+1)
                continue;
            path[x][y]=i+1;
            visited[x][y]=1;
            que.push({x,y,cur.length+1});
        }
    }
    cout<<"NO\n";
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    check_map.assign(n,vi(m,INT_MAX));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        labyrinth.push_back(s);
        for(int j=0;j<m;j++){
            if(s[j]=='A'){
                A={i,j};
                check_map[i][j]=0;
            }
            else if(s[j]=='M'){
                monsters.push_back({i,j});
                check_map[i][j]=0;
            }
            else if(s[j]=='#')
                check_map[i][j]=0;
        }
    }
    Monsters_BFS();
    Excape_BFS();
}
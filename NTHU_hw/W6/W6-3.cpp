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
 
int n,m,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},path[1005][1005],visited[1005][1005];
string s,dir_s=" UDLR";
pii A,B;
 
void BFS(){
    queue<pii> que;
    que.push({A.first,A.second});
    while(!que.empty()){
        pii cur=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int x=cur.first+dir[i][0],y=cur.second+dir[i][1];
            if(x<0||x>=n||y<0||y>=m||visited[x][y])
                continue;
            visited[x][y]=1;
            path[x][y]=i+1;
            que.push({x,y});
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='#')
                visited[i][j]=1;
            if(s[j]=='A')
                A.first=i,A.second=j;
            else if(s[j]=='B')
                B.first=i,B.second=j;
        }
    }
    BFS();
    if(!path[B.first][B.second]){
        cout<<"NO";
        return 0;
    }
    s="";
    while(A!=B){
        s+=dir_s[path[B.first][B.second]];
        B={B.first-dir[path[B.first][B.second]-1][0],B.second-dir[path[B.first][B.second]-1][1]};
    }
    reverse(all(s));
    cout<<"YES\n"<<s.size()<<endl<<s;
}
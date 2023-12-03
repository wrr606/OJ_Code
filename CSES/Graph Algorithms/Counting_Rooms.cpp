//Counting_Rooms
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

int n,m;
bool visited[1005][1005];
vs room;

void DFS(int x,int y){
    if(x<0||x>=n||y<0||y>=m||visited[x][y]||room[x][y]=='#')
        return;
    visited[x][y]=1;
    DFS(x+1,y);
    DFS(x-1,y);
    DFS(x,y+1);
    DFS(x,y-1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    room.assign(n,"");
    for(auto &i:room)
        cin>>i;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(room[i][j]!='#'&&!visited[i][j])
                DFS(i,j),ans++;
        }
    }
    cout<<ans;
}
//a562. ITSA201112 P2 小白鼠走方格
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

int n,matrix[8][8],m,ans=0;
bool visited[8][8],check[101];

void DFS(int x,int y,int dep=1){
    if(x<0||x>=m||y<0||y>=m||visited[x][y]||check[matrix[x][y]])
        return;
    visited[x][y]=1;
    check[matrix[x][y]]=1;
    ans=max(ans,dep);
    DFS(x+1,y,dep+1);
    DFS(x,y+1,dep+1);
    DFS(x-1,y,dep+1);
    DFS(x,y-1,dep+1);
    visited[x][y]=0;
    check[matrix[x][y]]=0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    while(n--){
        cin>>m;
        memset(visited,0,sizeof(visited)),memset(check,0,sizeof(check));
        ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                cin>>matrix[i][j];
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                DFS(i,j);
        cout<<ans<<endl;
    }
}
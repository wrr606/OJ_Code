//Grid_Paths
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

string s;
ll ans=0;
bool visited[9][9];

void dfs(int n=0,int x=1,int y=1){
    if(x<1||x>7||y<1||y>7||visited[x][y])
        return;
    if(x==7&&y==1){
        if(n==48)
            ans++;
        return;
    }
    if(!visited[x+1][y]&&!visited[x-1][y]&&visited[x][y+1]&&visited[x][y-1])
        return;
    if(visited[x+1][y]&&visited[x-1][y]&&!visited[x][y+1]&&!visited[x][y-1])
        return;
    visited[x][y]=1;
    if(s[n]=='D')
        dfs(n+1,x+1,y);
    else if(s[n]=='U')
        dfs(n+1,x-1,y);
    else if(s[n]=='L')
        dfs(n+1,x,y-1);
    else if(s[n]=='R')
        dfs(n+1,x,y+1);
    else{
        dfs(n+1,x+1,y);
        dfs(n+1,x-1,y);
        dfs(n+1,x,y-1);
        dfs(n+1,x,y+1);
    }
    visited[x][y]=0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    for(int i=1;i<=7;i++){
        visited[i][0]=1;
        visited[i][8]=1;
        visited[8][i]=1;
        visited[0][i]=1;
    }
    dfs();
    cout<<ans;
}
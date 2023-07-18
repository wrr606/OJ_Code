#include <bits/stdc++.h>
using namespace std;
array<char, 48> S;
array<array<bool, 9>, 9> vis;
int ans = 0;
void dfs(int x, int y, int s){
    if(x < 1 || y < 1 || x > 7 || y > 7 || vis[x][y]) return;
    if(x == 1 && y == 7){
        if(s == 48) ans++;
        return;
    }
    if(!vis[x+1][y]&&!vis[x-1][y]&&vis[x][y+1]&&vis[x][y-1])
        return;
    if(vis[x+1][y]&&vis[x-1][y]&&!vis[x][y+1]&&!vis[x][y-1])
        return;
    vis[x][y] = 1;
    if(S[s] == '?' || S[s] == 'L') dfs(x - 1, y, s + 1);
    if(S[s] == '?' || S[s] == 'R') dfs(x + 1, y, s + 1);
    if(S[s] == '?' || S[s] == 'U') dfs(x, y - 1, s + 1);
    if(S[s] == '?' || S[s] == 'D') dfs(x, y + 1, s + 1);
    vis[x][y] = 0;
}
signed main(){
    for(int i = 0; i < 48; i++){
        cin >> S[i];
    }
    for(int i = 1; i <= 7; i++){
        vis[0][i] = 1;
        vis[i][0] = 1;
        vis[8][i] = 1;
        vis[i][8] = 1;
    }
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}
//c129. 00572 - Oil Deposits
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

string deposit[110];
bool invited[110][110];
int m,n;

void DFS(int x,int y){
    if(x<0||x>=m||y<0||y>=n)
        return;
    else if(invited[x][y]||deposit[x][y]=='*')
        return;
    else{
        invited[x][y]=1;
        DFS(x+1,y);
        DFS(x,y+1);
        DFS(x-1,y);
        DFS(x,y-1);
        DFS(x-1,y-1);
        DFS(x+1,y-1);
        DFS(x-1,y+1);
        DFS(x+1,y+1);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>m>>n&&m&&n){
        int counter=0;
        memset(invited,0,sizeof(invited));
        for(int i=0;i<m;i++){
            cin>>deposit[i];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!invited[i][j]&&deposit[i][j]=='@'){
                    counter++;
                    DFS(i,j);
                }
            }
        }
        cout<<counter<<endl;
    }
}
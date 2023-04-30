//e584. 11094 - Continents
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

vector<string> matrix;
bool invited[22][22];
char land;
int m,n,x,y,ans,temp;

void DFS(int a,int b){
    //cout<<a<<" "<<b<<" "<<temp<<endl;
    if(a<0||a>=m)
        return;
    if(b<0)
        b=n-1;
    if(b>=n)
        b=0;
    if(invited[a][b]||matrix[a][b]!=land)
        return;
    invited[a][b]=1;
    temp++;
    ans=max(temp,ans);
    //cout<<temp<<endl;
    DFS(a,b-1),DFS(a,b+1);
    DFS(a-1,b),DFS(a+1,b);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(cin>>m){
        cin>>n;
        matrix.clear(),memset(invited,0,sizeof(invited));
        for(int i=0;i<m;i++){
            cin>>s;
            matrix.push_back(s);
        }
        cin>>x>>y;
        land=matrix[x][y];
        DFS(x,y);
        ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp=0;
                DFS(i,j);
            }
        }
        cout<<ans<<endl;
    }
}
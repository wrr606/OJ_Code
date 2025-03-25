//e550. 00722 - Lakes
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

ll ans;
vector<string> matrix;
bool invited[100][100];

void DFS(int x,int y){
    if(x<0||x>=matrix.size()||y<0||y>=matrix[0].size())
        return;
    if(invited[x][y]||matrix[x][y]=='1')
        return;
    invited[x][y]=1,ans++;
    DFS(x+1,y),DFS(x,y+1),DFS(x-1,y),DFS(x,y-1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,x,y;
    string s;
    bool b=0;
    cin>>t;
    getline(cin,s);
    while(t--){
        ans=0;
        if(b)
            cout<<endl;
        b=1;
        cin>>x>>y;
        x--,y--,memset(invited,0,sizeof(invited));
        getline(cin,s);
        matrix.clear();
        while(getline(cin,s)&&s!=""){
            matrix.push_back(s);
        }
        DFS(x,y);
        cout<<ans<<endl;
    }
}
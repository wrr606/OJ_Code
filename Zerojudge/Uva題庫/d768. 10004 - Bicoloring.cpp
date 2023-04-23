//d768. 10004 - Bicoloring
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

vector<pii > point;
bitset<205> invited;
bitset<205> color;
bool ans=1;

void dfs(int x,bool col=0){
    if(invited[x]){
        if(col!=color[x]){
            ans=0;
        }
        return;
    }
    invited[x]=1,color[x]=col;
    for(auto i:point){
        if(i.first==x){
            dfs(i.second,!col);
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,x,y;
    while(cin>>n&&n){
        cin>>m;
        invited.reset(),point.clear(),ans=1;
        for(int c=0;c<m;c++){
            cin>>x>>y;
            point.push_back({x,y});
        }
        dfs(point.begin()->first);
        if(ans){
            cout<<"BICOLORABLE.\n";
        }
        else{
            cout<<"NOT BICOLORABLE.\n";
        }
    }
}
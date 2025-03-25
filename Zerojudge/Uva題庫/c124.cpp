//c124. 00532 - Dungeon Master
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

struct point{
    ll x,y,z,n;
};

string s[40][40];
bool invited[40][40][40]={};
ll l,r,c,start[3]={},ending[3]={},ans;
deque<point> lis;

void BFS(){
    if(lis.empty()){
        return;
    }
    while(!lis.empty()){
        auto i=lis.front();
        if(i.x>=l||i.x<0||i.y>=r||i.y<0||i.z>=c||i.z<0){
            lis.pop_front();
            continue;
        }//cout<<i.x<<" "<<i.y<<" "<<i.z<<" "<<s[i.x][i.y][i.z]<<" "<<invited[i.x][i.y][i.z]<<endl;
        if(invited[i.x][i.y][i.z]){
            lis.pop_front();
            continue;
        }
        invited[i.x][i.y][i.z]=1;
        if(s[i.x][i.y][i.z]=='E'){
            ans=i.n;
            return;
        }
        lis.push_back({i.x,i.y+1,i.z,i.n+1}),lis.push_back({i.x,i.y,i.z+1,i.n+1});
        lis.push_back({i.x,i.y-1,i.z,i.n+1}),lis.push_back({i.x,i.y,i.z-1,i.n+1});
        lis.push_back({i.x+1,i.y,i.z,i.n+1}),lis.push_back({i.x-1,i.y,i.z,i.n+1});
        lis.pop_front();
    }
    BFS();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>l>>r>>c&&(l&&r&&c)){
        memset(invited,0,sizeof(invited)),lis.clear();
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                cin>>s[i][j];
                for(int k=0;k<c;k++){
                    if(s[i][j][k]=='S'){
                        start[0]=i;
                        start[1]=j;
                        start[2]=k;
                    }
                    else if(s[i][j][k]=='E'){
                        ending[0]=i;
                        ending[1]=j;
                        ending[2]=k;
                    }
                    else if(s[i][j][k]=='#'){
                        invited[i][j][k]=1;
                    }
                }
            }
        }
        lis.push_back({start[0],start[1],start[2],0});
        BFS();
        if(!invited[ending[0]][ending[1]][ending[2]])
            cout<<"Trapped!\n";
        else
            cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
    }
}
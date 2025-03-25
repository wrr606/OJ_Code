//e676. 00469 - Wetlands of Florida
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

vector<string> land;
bool invited[101][101],endln=0;
int a,b,ans;

void DFS(int x,int y){
    if(x<0||x>=land.size()||y<0||y>=land[0].size())
        return;
    if(land[x][y]=='L'||invited[x][y])
        return;
    invited[x][y]=1;
    ans++;
    DFS(x+1,y),DFS(x,y+1);
    DFS(x-1,y),DFS(x,y-1);
    DFS(x-1,y-1),DFS(x-1,y+1);
    DFS(x+1,y+1),DFS(x+1,y-1);
}

void split(string s){
    int index=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            a=stoi(s.substr(0,i));
            b=stoi(s.substr(i+1,s.size()-i-1));
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    string s;
    cin>>t;
    getline(cin,s);
    getline(cin,s);
    while(t--){
        if(endln)
            cout<<endl;
        endln=1;
        land.clear();
        while(getline(cin,s)&&s!=""){
            if(s[0]=='L'||s[0]=='W'){
                land.push_back(s);
            }
            else{
                ans=0;
                split(s),memset(invited,0,sizeof(invited));
                a--,b--;
                DFS(a,b);
                cout<<ans<<endl;
            }
        }
    }
}
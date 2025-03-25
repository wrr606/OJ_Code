//d669. 11677 - Alarm Clock
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int w,x,y,z;
    while(cin>>w>>x>>y>>z){
        if(!w&&!x&&!y&&!z){
            break;
        }
        if(w==0)
            w=24;
        if(y==0)
            y=24;
        int ans=y*60+z-w*60-x;
        if(ans<0)
            cout<<1440+ans;
        else
            cout<<ans;
        cout<<endl;
    }
}
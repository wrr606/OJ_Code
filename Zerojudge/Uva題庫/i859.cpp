//i859. 10642 - Can You Solve It?
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,x,y,x1,y1,ans1,ans2;
    cin>>t;
    for(int c=1;c<=t;c++){
        ans1=0,ans2=0;
        cin>>x>>y>>x1>>y1;
        ans1=(x+y+1)*(x+y)/2+x;
        ans2=(x1+y1+1)*(x1+y1)/2+x1;
        cout<<"Case "<<c<<": "<<ans2-ans1<<endl;
    }
}
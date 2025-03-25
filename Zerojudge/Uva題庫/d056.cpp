//d056. 10013 - Super long sums
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int x[1000002],y[1000002],ans[1000002];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,t;
    bool b=0,positional=0;
    cin>>t;
    while(t--){
        positional=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        memset(ans,0,sizeof(ans));
        for(int i=n-1;i>=1;i--){
            ans[i]+=x[i]+y[i];
            if(ans[i]>=10){
                ans[i]-=10;
                ans[i-1]=1;
            }
        }
        ans[0]+=x[0]+y[0];
        if(ans[0]>=10){
            ans[0]-=10;
            positional=1;
        }
        if(b){
            cout<<endl;
        }
        b=1;
        if(positional)
            cout<<1;
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
}
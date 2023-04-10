#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,t,a,b,ans=-1;
    cin>>n>>t;
    cin>>a;
    for(int i=1;i<n;i++){
        cin>>b;
        if(b-a<=t&&ans==-1){
            ans=b;
        }
        else{
            a=b;
        }
    }
    cout<<ans<<endl;
}
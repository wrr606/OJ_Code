#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int h,l;
            cin>>h>>l;
            if(h>l)
                ans++;
        }
        cout<<ans<<endl;
    }
}
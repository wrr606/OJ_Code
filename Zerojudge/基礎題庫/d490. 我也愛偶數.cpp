//d490. 我也愛偶數
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,ans=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(!(i&1))
            ans+=i;
    }
    cout<<ans<<endl;
}
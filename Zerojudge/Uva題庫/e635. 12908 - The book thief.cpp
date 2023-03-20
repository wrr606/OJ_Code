//e635. 12908 - The book thief
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,dp;
    while(cin>>n&&n){
        int i=2;
        dp=1;
        while(dp<=n){
            dp+=i;
            i++;
        }
        ll x=(-1+sqrt(1+8*n))/2;
        x++;
        cout<<dp-n<<" "<<x<<endl;
    }
}
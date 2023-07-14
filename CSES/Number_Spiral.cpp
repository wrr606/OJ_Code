//Number_Spiral
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        pair<ll,ll> start;
        ll Max=max(x,y);
        if(Max&1)
            start={Max,1};
        else
            start={1,Max};
        cout<<(Max-1)*(Max-1)+1+abs(x-start.first)+abs(y-start.second)<<endl;
    }
}
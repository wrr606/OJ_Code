//Stick_Lengths
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
    int n;
    cin>>n;
    vi num(n);
    for(auto &i:num)
        cin>>i;
    sort(all(num));
    ll ans=0;
    if(num.size()&1){
        int mid=num[num.size()/2];
        for(const auto &i:num){
            ans+=abs(mid-i);
        }
    }
    else{
        ll mid=(num[num.size()/2]+num[num.size()/2-1])/2;
        for(const auto &i:num){
            ans+=abs(mid-i);
        }
    }
    cout<<ans;
}
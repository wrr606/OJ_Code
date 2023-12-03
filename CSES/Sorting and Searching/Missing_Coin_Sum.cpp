//Missing_Coin_Sum
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

int main(){//greedy
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vi num(n);
    for(auto &i:num)
        cin>>i;
    sort(all(num));
    ll ans=1;
    for(const auto &i:num){
        if(ans<i)
            break;
        ans+=i;
    }
    cout<<ans;
}
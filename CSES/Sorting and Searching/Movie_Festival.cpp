//Restaurant_Customers
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

bool cmp(pii a,pii b){
    return a.second<b.second;
}

int main(){//最大不重複區間
    ios::sync_with_stdio(0),cin.tie(0);
    int n,ans=1;
    cin>>n;
    vector<pii > times(n);
    for(auto &i:times)
        cin>>i.first>>i.second;
    sort(all(times),cmp);
    int cur=times[0].second;
    for(const auto &i:times){
        if(cur<=i.first)
            cur=i.second,ans++;
    }
    cout<<ans;
}
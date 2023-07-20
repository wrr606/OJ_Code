//Distinct_Numbers
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

set<int> ans;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
        cin>>n,ans.insert(n);
    cout<<ans.size();
}
//Ferris_Wheel
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
    int n,x,ans;
    cin>>n>>x;
    set<int> person;
    for(auto &i:person)
        cin>>ans,person.insert(ans);
    ans=0;
    auto iter=person.begin();
    while(iter!=person.end()){
        int d=x-*iter;
        auto Max=person.lower_bound()
    }
}
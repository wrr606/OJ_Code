//Apartments
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
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
    vi person(n),house(m);
    for(auto &i:person)
        cin>>i;
    for(auto &i:house)
        cin>>i;
    sort(all(house)),sort(all(person));
    int index=0;
    for(const auto &i:house){
        while(index<n){
            if(abs(i-person[index])<=k){
                ans++;
                index++;
                break;
            }
            else if(i-person[index]>k)
                index++;
            else
                break;
        }
    }
    cout<<ans;
}
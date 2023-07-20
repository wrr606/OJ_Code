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
    int n,x,ans=0;
    cin>>n>>x;
    vi person(n);
    for(auto &i:person)
        cin>>i;
    sort(all(person));
    int i=0,j=n-1;
    while(i<=j){
        if(person[i]+person[j]<=x)
            i++,j--,ans++;
        else
            ans++,j--;
    }
    cout<<ans;
}
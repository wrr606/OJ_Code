//Weird_Algorithm
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
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n&1)
            n=n*3+1;
        else
            n/=2;
        cout<<n<<" ";
    }
}
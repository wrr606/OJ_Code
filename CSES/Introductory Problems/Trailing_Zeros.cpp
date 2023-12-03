//Trailing_Zeros
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
    int n,ans=0,temp=5;
    cin>>n;
    while(n>=temp){
        ans+=n/temp;
        temp*=5;
    }
    cout<<ans;
}
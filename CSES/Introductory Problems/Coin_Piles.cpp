//Coin_Piles
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
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a<b)
            swap(a,b);
        if((a+b)%3==0&&a<=b*2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
//Increasing_Array
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
    ll ans=0;
    cin>>n;
    vector<int> number(n);
    for(auto &i:number)
        cin>>i;
    for(int i=1;i<n;i++)
        if(number[i]<number[i-1]){
            ans+=number[i-1]-number[i];
            number[i]=number[i-1];
        }
    cout<<ans;
}
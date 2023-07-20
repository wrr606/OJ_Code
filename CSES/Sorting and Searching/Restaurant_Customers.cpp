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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    map<int,int> customers;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a>>b,customers[a]=1,customers[b]=-1;
    int ans=INT_MIN,counter=0;
    for(const auto &i:customers){
        counter+=i.second;
        ans=max(ans,counter);
    }
    cout<<ans;
}
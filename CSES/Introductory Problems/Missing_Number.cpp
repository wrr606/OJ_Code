//Missing_Number
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

bitset<200005> check;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>temp;
        check[temp]=1;
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            cout<<i;
            break;
        }
    }
}
//Collecting_Numbers
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

int main(){//greedy
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vi num(n+1),reflect(n+1);
    for(int i=1;i<=n;i++)
        cin>>num[i],reflect[num[i]]=i;
    int ans=1;
    for(int i=2;i<=n;i++){
        if(reflect[i]<reflect[i-1])
            ans++;
    }
    cout<<ans;
}
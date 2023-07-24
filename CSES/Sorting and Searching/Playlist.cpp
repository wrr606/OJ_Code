//Playlist
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

bitset<1000000002> check;

int main(){//greedy 最長不重複子序列
    ios::sync_with_stdio(0),cin.tie(0);
    int n,ans=0;
    cin>>n;
    vi song(n);
    for(auto &i:song)
        cin>>i;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int l=0,r=0;l<n;l++){
        while(r<n&&!check[song[r]]){
            check[song[r]]=1;
            r++;
        }
        ans=max(ans,r-l);
        check[song[l]]=0;
    }
    cout<<ans;
}
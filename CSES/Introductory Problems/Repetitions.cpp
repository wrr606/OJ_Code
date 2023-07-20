//Repetitions
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
    string s;
    int counter=1,ans=1;
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])
            counter++;
        else
            counter=1;
        ans=max(ans,counter);
    }
    cout<<ans;
}
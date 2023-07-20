//Creating_Strings
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
    vector<string> ans;
    cin>>s;
    sort(all(s));
    do{
        ans.push_back(s);
    }while(next_permutation(all(s)));
    cout<<ans.size()<<endl;
    for(const auto &i:ans)
        cout<<i<<endl;
}
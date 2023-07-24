//Towers
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

int main(){//greedy DP  LIS(題目敘述不一樣而已)
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vi num(n),ans;
    for(auto &i:num)
        cin>>i;
    for(const auto &i:num){
        if(ans.empty()||ans.back()<=i)
            ans.push_back(i);
        else
            *upper_bound(all(ans),i)=i;
    }
    cout<<ans.size();
}
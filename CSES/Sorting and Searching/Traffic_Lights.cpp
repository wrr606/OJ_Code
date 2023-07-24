//Traffic_Lights
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
    int x,n;
    cin>>x>>n;
    set<int> line={0,x};
    multiset<int> ans={x};
    while(n--){
        cin>>x;
        auto iter=line.upper_bound(x);
        int d=*iter-*--iter,a=x-*iter++,b=*iter-x;
        ans.erase(ans.find(d));
        ans.insert(a),ans.insert(b);
        cout<<*ans.rbegin()<<" ";
        line.insert(x);
    }
}
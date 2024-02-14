#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#include<chrono>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

constexpr int N=2e5+5;
int m[N],x;

inline int handle(const int &num){
    return (x-num%x)%x;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n,y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        unordered_map<int,unordered_map<int,int,custom_hash>,custom_hash> check;
        for(int c=0;c<n;c++)
            cin>>m[c];
        ll ans=0;
        int a,b;
        for(int i=0;i<n;i++){
            a=handle(m[i]),b=m[i]%y;
            ans+=check[a][b];
            a=m[i]%x;
            check[a][b]=check[a][b]+1;
        }
        cout<<ans<<endl;
    }
}
/*
1
9 4 10
14 10 2 2 11 11 13 5 6
2  2  2 2 3  3  1  1 2
4  0  2 2 1  1  3  5 6
*/
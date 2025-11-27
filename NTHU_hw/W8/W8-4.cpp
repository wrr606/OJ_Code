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

constexpr int MAXN = 2e5 + 5;

class DSU{
private:
    int n, num[MAXN];
public:
    int f(int cur){
        return num[cur]==cur?cur:num[cur]=f(num[cur]);
    }

    void merge(int a, int b){
        a=f(a),b=f(b);
        if(a!=b){
            num[b]=a;
        }
    }

    DSU(int n): n(n){
        iota(num, num + n + 1, 0);
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, k, l, a, b;
    cin>>n>>k>>l;
    DSU roads(n), railways(n);
    map<pii, int> cnt;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        roads.merge(a, b);
    }
    for(int i=0;i<l;i++){
        cin>>a>>b;
        railways.merge(a, b);
    }
    for(int i=1;i<=n;i++)
        ++cnt[{roads.f(i), railways.f(i)}];
    for(int i=1;i<=n;i++){
        cout<<cnt[{roads.f(i), railways.f(i)}]<<" ";
    }
}
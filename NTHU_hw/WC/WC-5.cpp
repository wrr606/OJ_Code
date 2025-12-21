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

int lowbit(int x) { return x & -x; }

class BIT{
    int n;
    vector<long long> bit;
public:
    void init(int _n) {
        n = _n;
        bit.resize(n);
        for (auto&b: bit) b= 0;
    }

    long long query(int x) const{
        long long sum= 0;
        for (; x; x-= lowbit(x))
        sum += bit[x];
        return sum;
    }

    void modify(int x, int val) {
        for (; x <= n; x+= lowbit(x))
        bit[x] += val;
    }
};


class BIT2D {
    int m;
    vector<BIT> bit1D;
public:
    void init(int _m, int _n) {
        m = _m;
        bit1D.resize(m);
        for (auto&b: bit1D) b.init(_n);
    }
    long long query(int x, int y) const{
        long long sum= 0;
        for (; x; x-= lowbit(x))
            sum += bit1D[x].query(y);
        return sum;
    }
    void modify(int x, int y, int val) {
        for (; x <= m; x+= lowbit(x))
        bit1D[x].modify(y, val);
    }
    long long query2D(int x1, int y1, int x2, int y2) {
        return query(x2, y2)
            - query(x1 - 1, y2)
            - query(x2, y1 - 1)
            + query(x1 - 1, y1 - 1);
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, q;
    cin>>n>>q;
    BIT2D bit;
    bit.init(n + 1, n + 1);

    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j - 1] == '.')
                bit.modify(i, j, 0);
            else
                bit.modify(i, j, 1);
        }
    }

    int op, a, b, c, d;
    while(q--){
        cin>>op;
        if(op == 1){
            cin>>a>>b;
            bool haveTree = bit.query2D(a, b, a, b);
            if(haveTree)
                bit.modify(a, b, -1);
            else
                bit.modify(a, b, 1);
        }
        else{
            cin>>a>>b>>c>>d;
            cout<<bit.query2D(a, b, c, d)<<endl;
        }
    }
}